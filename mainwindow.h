#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <modelsdatawidget.h>
#include <tabledatawidget.h>
#include <plotdatawidget.h>
#include "numsolver.h"
#include "ansolver.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
    const double epsilon = 1e-9;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_run_clicked();
    void on_time_slider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    ModelsDataWidget* modelswgt;
    TableDataWidget* tablewgt;
    PlotDataWidget* plotwgt;
    QSplitter* main_spl;
    QComboBox* cmb_type_plot_data_show;
    QLineEdit* edt_status_solve;
    TypeSolve type;
    double** Pnum;
    double** Pan;
    double** S;
    double* x;
    double* t;

};




#endif // MAINWINDOW_H
