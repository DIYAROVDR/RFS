#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
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
    for(int i = 0;i<nx;++i){
        ui->data->item(i,0)->setText(QString::number(P_num[value][i]));
        ui->data->item(i,1)->setText(QString::number(P_an[value][i]));
    }
}

