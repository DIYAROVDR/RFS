#ifndef PLOTDATAWIDGET_H
#define PLOTDATAWIDGET_H

#include "qcustomplot.h"
#include <QObject>
#include <QWidget>

#include <tabledatawidget.h>

class PlotDataWidget : public QCustomPlot {
    Q_OBJECT
public:
    PlotDataWidget(QWidget *parent);
    void setSize(int nx, int nt);
    void setData(double** Pnum, double** Pan,double* x,double* t);
    void setType(TypeData type);
    void update(int value);

signals:
    void bothMouseButtonsClicked(); // Сигнал для нажатия обеих кнопок

public slots:
    void setInitRange();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    int nx = 0;
    int nt = 0;
    QVector<QVector<double>> Pnum;
    QVector<QVector<double>> Pan;
    QVector<double> x;
    QVector<double> t;
    double maxY = 0.0;
    double minY = 0.0;
    double maxX = 0.0;
    double minX = 0.0;
    TypeData type;
};

#endif // PLOTDATAWIDGET_H
