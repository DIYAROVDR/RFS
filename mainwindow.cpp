#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->plot->addGraph();
    ui->plot->graph(0)->setPen(QPen(Qt::blue));

    ui->plot->addGraph();
    ui->plot->graph(1)->setPen(QPen(Qt::red));

    ui->plot->xAxis->setLabel("x,m");
    ui->plot->yAxis->setLabel("P,atm");

    ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone); // Убираем линии
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4)); // Устанавливаем кружки

}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_btn_run_clicked() {
    nx = ui->edt_nx->text().toInt();
    double L = ui->edt_L->text().toDouble();
    double dx = L/nx;
    double dy = ui->edt_dy->text().toDouble();
    double dz = ui->edt_dz->text().toDouble();

    double Pw = ui->edt_pw->text().toDouble()*1E+5;
    double Pe = ui->edt_pe->text().toDouble()*1E+5;

    int nt = ui->edt_nt->text().toDouble();
    double T = ui->edt_T->text().toDouble();
    double dt = T/nt;

    double B = ui->edt_b->text().toDouble();
    double mu = ui->edt_mu->text().toDouble()*1E-3;
    double cf = ui->edt_cf->text().toDouble()*1E-5;
    double cr = ui->edt_cr->text().toDouble()*1E-5;
    double fi = ui->edt_fi->text().toDouble();
    double kx = ui->edt_kx->text().toDouble()*1E-15;

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

    std::function<double(double,double)> solution = [=](double s, double xd){
        return (exp(xd*sqrt(s))/(exp(sqrt(s))-exp(-sqrt(s))) + exp(-xd*sqrt(s))/(exp(-sqrt(s))-exp(sqrt(s))))/s;
    };

    g1.setInitPressure(Pe);
    g1.setPermability(kx);
    g1.setPorosity(fi);
    g1.setPropertyFluid(prop);
    g1.setBoudaryCondition(boundaryCondition);
    g1.update();

    NumSolver solver_1(g1,dt,T);
    solver_1.run();
    P_num = solver_1.getPressure();

    AnSolver solver_2(dt,T);
    solver_2.setDims(dimp,dimt,dimx);
    solver_2.setCoords(nx,g1.getX());
    solver_2.setSolution(solution);
    solver_2.setPressure(Pw,Pe);
    solver_2.run();
    P_an = solver_2.getPressure();

    ui->time_slider->setMaximum(nt);
    ui->spin_box_current_time_step->setMaximum(nt);

    ui->plot->xAxis->setRange(0, L);
    ui->plot->yAxis->setRange(Pw/1E+5, Pe/1E+5);
    x = g1.getX();
    coords.clear();
    for(int i=0;i < nx+1;++i) {

        coords.append(x[i]);
    }
}


void MainWindow::on_edt_nx_textChanged(const QString &arg1) {
    double dx = ui->edt_L->text().toDouble()/arg1.toDouble();
    ui->edt_dx->setText(QString::number(dx));
}


void MainWindow::on_edt_nt_textChanged(const QString &arg1) {
    double dt = ui->edt_T->text().toDouble()/arg1.toDouble();
    ui->edt_dt->setText(QString::number(dt));
}


void MainWindow::on_time_slider_valueChanged(int value) {
    ui->spin_box_current_time_step->setValue(value);
    ui->data->setRowCount(0);
    ui->data->setRowCount(nx+1);
    QVector<double> Pn,Pa,x;
    double Pa_i,Pn_i;
    for(int i = 0;i<nx;++i){
        Pn_i = P_num[value][i]/1E+5;
        Pa_i = P_an[value][i]/1E+5;

        Pn.append(Pn_i);
        Pa.append(Pa_i);


        QTableWidgetItem * unum = new QTableWidgetItem();
        QTableWidgetItem * uan = new QTableWidgetItem();
        QTableWidgetItem * abs = new QTableWidgetItem();

        unum->setText(QString::number(Pn_i));
        uan->setText(QString::number(Pa_i));
        abs->setText(QString::number(Pa_i-Pn_i));

        ui->data->setItem(i,0,unum);
        ui->data->setItem(i,1,uan);
        ui->data->setItem(i,2,abs);

    }

    ui->plot->graph(0)->setData(coords, Pn);
    ui->plot->graph(1)->setData(coords, Pa);

    ui->plot->replot();
}

