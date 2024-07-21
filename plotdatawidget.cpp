#include "plotdatawidget.h"

PlotDataWidget::PlotDataWidget(QWidget *parent): QCustomPlot(parent) {
    type = TypeData::PRESSURE_VS_COORDS;

    addGraph();
    graph(0)->setPen(QPen(Qt::blue));
    graph(0)->setLineStyle(QCPGraph::lsNone);
    graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 10));

    addGraph();
    graph(1)->setPen(QPen(Qt::red,2));

    yAxis->setLabel("P, атм");


    QFont labelFont = yAxis->labelFont();
    labelFont.setPointSize(12);
    yAxis->setLabelFont(labelFont);
    xAxis->setLabelFont(labelFont);

    QFont tickFont = yAxis->tickLabelFont();
    tickFont.setPointSize(12);
    yAxis->setTickLabelFont(tickFont);
    xAxis->setTickLabelFont(tickFont);

    // Добавление вспомогательной сетки
    xAxis->grid()->setSubGridVisible(true);
    yAxis->grid()->setSubGridVisible(true);

    // Настройка стиля линии вспомогательной сетки
    QPen subGridPen;
    subGridPen.setStyle(Qt::DotLine);
    subGridPen.setColor(QColor(200, 200, 200)); // Цвет вспомогательной сетки
    xAxis->grid()->setSubGridPen(subGridPen);
    yAxis->grid()->setSubGridPen(subGridPen);

    // Включение возможности перемещения и масштабирования графика
    setInteraction(QCP::iRangeDrag, true);
    setInteraction(QCP::iRangeZoom, true);

    // Настройка осей для масштабирования
    axisRect()->setRangeZoom(Qt::Horizontal | Qt::Vertical);
    axisRect()->setRangeDrag(Qt::Horizontal | Qt::Vertical);

    connect(this, &PlotDataWidget::bothMouseButtonsClicked, this, &PlotDataWidget::setInitRange);
}

void PlotDataWidget::mousePressEvent(QMouseEvent *event) {
    // Проверка, нажаты ли одновременно левая и правая кнопки мыши
    if ((event->buttons() & Qt::LeftButton) && (event->buttons() & Qt::RightButton)) {
        emit bothMouseButtonsClicked();
    }
    // Вызов базового класса для обеспечения стандартного поведения
    QCustomPlot::mousePressEvent(event);
}

void PlotDataWidget::setInitRange() {
    yAxis->setRange(0.9*minY,1.05*maxY);
    xAxis->setRange(0.9*minX,1.05*maxX);
    replot();
}

void PlotDataWidget::setSize(int nx, int nt) {
    this->nx = nx;
    this->nt = nt;
    Pnum.resize(nt);
    Pan.resize(nt);
    x.resize(nx);
    t.resize(nt);
}

void PlotDataWidget::setData(double **Pnum, double **Pan, double *x, double *t) {
    for (int n = 0; n < nt; ++n) {
        this->Pnum[n].resize(nx);
        this->Pan[n].resize(nx);
        for (int i = 0; i < nx; ++i) {
            this->Pnum[n][i] = Pnum[n][i] / 1E+5;
            this->Pan[n][i] = Pan[n][i] / 1E+5;
        }
        this->t[n] = t[n];
    }
    for (int i = 0; i < nx; ++i) {
        this->x[i] = x[i];
    }

    minY = std::numeric_limits<double>::max();
    maxY = std::numeric_limits<double>::lowest();

    for (const auto &row : this->Pan) {
        for (const auto &value : row) {
            if (value < minY) {
                minY = value;
            }
            if (value > maxY) {
                maxY = value;
            }
        }
    }

    if (type == TypeData::PRESSURE_VS_COORDS){
        minX = this->x.first();
        maxX = this->x.last();
    }
    else {
        minX = this->x.first();
        maxX = this->x.last();
    }

    yAxis->setRange(0.9*minY,1.05*maxY);
    xAxis->setRange(0.9*minX,1.05*maxX);
}

void PlotDataWidget::setType(TypeData type) {
    this->type = type;
}


void PlotDataWidget::update(int value) {
    if(type==TypeData::PRESSURE_VS_COORDS){
        graph(0)->setData(x, Pnum[value]);
        graph(1)->setData(x, Pan[value]);
        xAxis->setLabel("x, м");
        //xAxis->rescale(true);
        //yAxis->rescale(true);
    }
    if(type == TypeData::PRESSURE_VS_TIME) {
        //graph(0)->setData(t, Pnum ???);
        //graph(1)->setData(t, Pan ???);
        xAxis->setLabel("t, сут");
    }
    replot();
}
