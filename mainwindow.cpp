#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    modelswgt = new ModelsDataWidget(this);
    ui->vl_tree_field->addWidget(modelswgt);

    tablewgt = new TableDataWidget(this);
    ui->vl_table_field->addWidget(tablewgt);

    plotwgt = new PlotDataWidget(this);
    ui->tabWidget->addTab(plotwgt,"График");
    ui->tabWidget->setCurrentIndex(1);

    main_spl = new QSplitter(Qt::Horizontal);
    main_spl->addWidget(ui->wgt_tree_field);
    main_spl->addWidget(ui->tabWidget);
    main_spl->addWidget(ui->wgt_table_field);

    ui->horizontalLayout_2->addWidget(main_spl);

    QList<int> sizes;
    sizes << 300 << 600 << 300;
    main_spl->setSizes(sizes);

    cmb_type_plot_data_show = new QComboBox(this);
    cmb_type_plot_data_show->addItem("Давление от координаты");
    cmb_type_plot_data_show->addItem("Давление от времени");
    ui->vl_tree_field->addWidget(cmb_type_plot_data_show);

    edt_status_solve = new QLineEdit(this);
    ui->vl_table_field->addWidget(edt_status_solve);
    edt_status_solve->setReadOnly(true);

    ui->statusBar->showMessage("BY DIYAROV D.R - RFS 1D v2024.07.21");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btn_run_clicked() {
    int nx = modelswgt->Nx();
    int nt = modelswgt->Nt();
    int maxIt = modelswgt->MaxIt();

    double dx = modelswgt->Dx();
    double dy = modelswgt->Dy();
    double dz = modelswgt->Dz();
    double Pw = modelswgt->Pw();
    double Pe = modelswgt->Pe();
    double T = modelswgt->totalTime();
    double B = modelswgt->B();
    double mu = modelswgt->Mu();
    double cf = modelswgt->Cf();
    double cr = modelswgt->Cr();
    double fi = modelswgt->Poro();
    double kx = modelswgt->Permx();

    type = TypeSolve::EXPLICIT;
    if(modelswgt->NumMethod() == "Неявный") {
         type = TypeSolve::IMPLICIT;
    }

    double L = nx*dx;
    double dt = T/nt;
    double ct = cf*fi+cr;
    double etta = kx/(ct*mu*fi);
    double dimt = etta/(L*L);
    double dimp = Pe - Pw;
    double dimx = 1/L;

    // Граничное условие для численного решения. Случай постоянного давления на концах пласта.
    std::function<double(double)> boundaryCondition = [=](double x) {
        if (std::abs(x - 0.0) < epsilon) {
            return Pw;
        } else if (std::abs(x - L) < epsilon) {
            return Pe;
        } else {
            return 0.0;
        }
    };

    // Решение в прастранстве Лапласа для случая ограниченного пласта длиной L с постоянными заданными давлениями на границе.
    std::function<double(double,double)> solution = [=](double s, double xd) {
        return -((exp(sqrt(s))*(exp(-xd*sqrt(s))-1)-exp(-sqrt(s))*(exp(xd*sqrt(s))-1))/(exp(sqrt(s))-exp(-sqrt(s))))/s;
    };

    Grid grid(nx,dx,dy,dz);
    Props prop(B,mu,cf,cr);

    grid.setInitPressure(Pe);
    grid.setPermability(kx);
    grid.setPorosity(fi);
    grid.setPropertyFluid(prop);
    grid.setBoudaryCondition(boundaryCondition);
    grid.update();

    NumSolver numSol(grid,dt,T);
    numSol.setTypeSolve(type);
    numSol.setMaxIt(maxIt);
    numSol.run();

    AnSolver anSol(dt,T);
    anSol.setDims(dimp,dimt,dimx);
    anSol.setCoords(nx,grid.getX());
    anSol.setSolution(solution);
    anSol.setPressure(Pw,Pe);
    anSol.run();

    Pnum = numSol.getPressure();
    Pan = anSol.getPressure();
    S = numSol.stability();
    t = anSol.getTime();
    x = grid.getX();

    tablewgt->setSize(nx,nt);
    tablewgt->setData(Pnum,Pan,S);
    tablewgt->setType(TypeData::PRESSURE_VS_COORDS);
    tablewgt->setStepTime(dt);

    plotwgt->setSize(nx,nt);
    plotwgt->setType(TypeData::PRESSURE_VS_COORDS);
    plotwgt->setData(Pnum,Pan,x,t);

    ui->time_slider->setEnabled(true);
    ui->time_slider->setMaximum(nt);
    ui->spin_box_current_time_step->setEnabled(true);
    ui->spin_box_current_time_step->setMaximum(nt);
    ui->cmb_solve_steps->setEnabled(true);

    QStringList items;
    for(int n = 0;n < nt;++n){
        items << QString::number(t[n]);
    }
    ui->cmb_solve_steps->clear();
    ui->cmb_solve_steps->addItems(items);
    on_time_slider_valueChanged(1);
}


void MainWindow::on_time_slider_valueChanged(int value) {
    ui->spin_box_current_time_step->setValue(value);
    tablewgt->update(value);
    plotwgt->update(value);
    ui->cmb_solve_steps->setCurrentIndex(value);
    if(type == TypeSolve::IMPLICIT){
        edt_status_solve->setText("");
        return;
    }
    if (tablewgt->checkStability(value)){
        edt_status_solve->setText("Метод устойчив");
    }
    else {
        edt_status_solve->setText("Метод НЕ устойчив");
    }
}

