#include "tabledatawidget.h"

TableDataWidget::TableDataWidget(QWidget *parent):QTableWidget(parent) {
    type = TypeData::PRESSURE_VS_COORDS;
    setColumnCount(4);
    QStringList headers = { "P (num)", "P (an)", "Abs", "S" };
    setHorizontalHeaderLabels(headers);

    QFont boldFont;
    boldFont.setBold(true);
    horizontalHeader()->setFont(boldFont);

    setAlternatingRowColors(true);
    setEditTriggers(EditTrigger::NoEditTriggers);
    //horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //horizontalHeader()->setStretchLastSection(true);
}

TableDataWidget::~TableDataWidget() {

}

void TableDataWidget::setSize(int nx, int nt) {
    this->nx = nx;
    this->nt = nt;
}

void TableDataWidget::setData(double **Pnum, double **Pan, double **S) {
    this->Pnum = Pnum;
    this->Pan = Pan;
    this->S = S;
}

void TableDataWidget::setType(TypeData type) {
    this->type = type;
}

void TableDataWidget::setStepTime(double dt) {
    this->dt = dt;
}

void TableDataWidget::update(int value) {
    if(type==TypeData::PRESSURE_VS_COORDS) {
        setRowCount(nx);
        for (int i = 0; i < nx; ++i) {
            QTableWidgetItem* pnumItem = new QTableWidgetItem(QString::number(Pnum[value][i]/1E+5));
            setItem(i, 0, pnumItem);

            QTableWidgetItem* panItem = new QTableWidgetItem(QString::number(Pan[value][i]/1E+5));
            setItem(i, 1, panItem);

            double absValue = Pan[value][i] - Pnum[value][i];
            QTableWidgetItem* absItem = new QTableWidgetItem(QString::number(absValue/1E+5));
            setItem(i, 2, absItem);

            QTableWidgetItem* sItem = new QTableWidgetItem(QString::number(S[value][i]));
            setItem(i, 3, sItem);
        }
    }
    if(type == TypeData::PRESSURE_VS_TIME) {
        for (int n = 0; n < nx; ++n) {
            QTableWidgetItem* pnumItem = new QTableWidgetItem(QString::number(Pnum[n][value]));
            setItem(n, 0, pnumItem);

            QTableWidgetItem* panItem = new QTableWidgetItem(QString::number(Pan[n][value]));
            setItem(n, 1, panItem);

            double absValue = Pan[n][value] - Pnum[n][value];
            QTableWidgetItem* absItem = new QTableWidgetItem(QString::number(absValue));
            setItem(n, 2, absItem);

            QTableWidgetItem* sItem = new QTableWidgetItem(QString::number(S[n][value]));
            setItem(n, 3, sItem);
        }
    }

}

bool TableDataWidget::checkStability(int value) {
    if(type==TypeData::PRESSURE_VS_COORDS) {
        double min = std::numeric_limits<double>::max();
        double tmp = 0.0;
        for (int i = 0; i < nx; ++i) {
            tmp = S[value][i];
            if (min > tmp) {
                min = tmp;
            }
        }
        if(dt<=min) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return true;
    }
}


























