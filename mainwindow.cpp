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
    double dx = modelswgt->Dx();
    double dy = modelswgt->Dy();
    double dz = modelswgt->Dz();
    double L = nx*dx;
    double Pw = modelswgt->Pw();
    double Pe = modelswgt->Pe();

    int nt = modelswgt->Nt();

    double T = modelswgt->totalTime();
    double dt = T/nt;

    double B = modelswgt->B();
    double mu = modelswgt->Mu();
    double cf = modelswgt->Cf();
    double cr = modelswgt->Cr();
    double fi = modelswgt->Poro();
    double kx = modelswgt->Permx();

    double ct = cf*fi+cr;
    double etta = kx/(ct*mu*fi);

    double dimt = etta/(L*L);
    double dimp = Pe - Pw;
    double dimx = 1/L;

    Grid g1(nx,dx,dy,dz);
    Props prop(B,mu,cf,cr);

    std::function<double(double)> boundaryCondition = [=](double x) {
        if (std::abs(x - 0.0) < epsilon) {
            return Pw;
        } else if (std::abs(x - L) < epsilon) {
            return Pe;
        } else {
            return 0.0;
        }
    };

    std::function<double(double,double)> solution = [=](double s, double xd) {
        return -((exp(sqrt(s))*(exp(-xd*sqrt(s))-1)-exp(-sqrt(s))*(exp(xd*sqrt(s))-1))/(exp(sqrt(s))-exp(-sqrt(s))))/s;
    };

    g1.setInitPressure(Pe);
    g1.setPermability(kx);
    g1.setPorosity(fi);
    g1.setPropertyFluid(prop);
    g1.setBoudaryCondition(boundaryCondition);
    g1.update();
    x = g1.getX();

    NumSolver solver_1(g1,dt,T);
    solver_1.run();
    Pnum = solver_1.getPressure();
    S = solver_1.stability();

    AnSolver solver_2(dt,T);
    solver_2.setDims(dimp,dimt,dimx);
    solver_2.setCoords(nx,g1.getX());
    solver_2.setSolution(solution);
    solver_2.setPressure(Pw,Pe);
    solver_2.run();
    Pan = solver_2.getPressure();
    t = solver_2.getTime();

    tablewgt->setSize(nx,nt);
    tablewgt->setData(Pnum,Pan,S);
    tablewgt->setStepTime(dt);

    plotwgt->setSize(nx,nt);
    plotwgt->setType(TypeData::PRESSURE_VS_COORDS);
    plotwgt->setData(Pnum,Pan,x,t);

    ui->time_slider->setEnabled(true);
    ui->time_slider->setMaximum(nt);
    ui->spin_box_current_time_step->setEnabled(true);
    ui->spin_box_current_time_step->setMaximum(nt);
    ui->cmb_solve_steps->setEnabled(true);
    on_time_slider_valueChanged(1);

    QStringList items;
    for(int n = 0;n < nt;++n){
        items << QString::number(t[n]);
    }
    ui->cmb_solve_steps->clear();
    ui->cmb_solve_steps->addItems(items);
}


void MainWindow::on_time_slider_valueChanged(int value) {
    ui->spin_box_current_time_step->setValue(value);
    tablewgt->update(value);
    plotwgt->update(value);
    ui->cmb_solve_steps->setCurrentIndex(value);
    if (tablewgt->checkStability(value)){
        edt_status_solve->setText("Метод устойчив");
    }
    else {
        edt_status_solve->setText("Метод НЕ устойчив");
    }
}

