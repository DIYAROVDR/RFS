#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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
    void on_edt_nx_textChanged(const QString &arg1);
    void on_edt_nt_textChanged(const QString &arg1);

    void on_time_slider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    int nx;
    double** P_num;
    double** P_an;
    double* x;

};




#endif // MAINWINDOW_H
