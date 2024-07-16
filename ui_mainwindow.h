/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_field;
    QHBoxLayout *horizontalLayout;
    QCustomPlot *plot;
    QTableWidget *data;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLineEdit *edt_fi;
    QLineEdit *edt_b;
    QLabel *label_7;
    QLineEdit *edt_nt;
    QLabel *label_3;
    QLabel *label_1;
    QLineEdit *edt_cf;
    QLineEdit *edt_kx;
    QLabel *label_2;
    QLineEdit *edt_mu;
    QLineEdit *edt_nx;
    QLabel *label_9;
    QLabel *label_13;
    QLineEdit *edt_cr;
    QLabel *label_16;
    QLineEdit *edt_pw;
    QLineEdit *edt_pe;
    QLabel *label_6;
    QLabel *label;
    QLineEdit *edt_dx;
    QLabel *label_12;
    QLabel *label_8;
    QLabel *label_5;
    QLineEdit *edt_dt;
    QLabel *label_11;
    QLineEdit *edt_T;
    QLineEdit *edt_L;
    QLabel *label_10;
    QLineEdit *edt_dz;
    QLabel *label_15;
    QLineEdit *edt_dy;
    QLabel *label_14;
    QHBoxLayout *horizontalLayout_1;
    QPushButton *btn_run;
    QSlider *time_slider;
    QSpinBox *spin_box_current_time_step;
    QComboBox *cmb_solve_steps;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(911, 659);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_field = new QWidget(centralwidget);
        widget_field->setObjectName(QString::fromUtf8("widget_field"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(widget_field->sizePolicy().hasHeightForWidth());
        widget_field->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget_field);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        plot = new QCustomPlot(widget_field);
        plot->setObjectName(QString::fromUtf8("plot"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plot->sizePolicy().hasHeightForWidth());
        plot->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(plot);

        data = new QTableWidget(widget_field);
        if (data->columnCount() < 3)
            data->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        data->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        data->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        data->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        data->setObjectName(QString::fromUtf8("data"));
        data->setEditTriggers(QAbstractItemView::NoEditTriggers);
        data->setAlternatingRowColors(true);
        data->setSelectionMode(QAbstractItemView::NoSelection);
        data->horizontalHeader()->setMinimumSectionSize(37);
        data->horizontalHeader()->setDefaultSectionSize(85);
        data->verticalHeader()->setVisible(false);

        horizontalLayout->addWidget(data);


        verticalLayout->addWidget(widget_field);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, -1, -1, -1);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy2);
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(5);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(5, 5, 5, 5);
        edt_fi = new QLineEdit(groupBox_3);
        edt_fi->setObjectName(QString::fromUtf8("edt_fi"));

        gridLayout_3->addWidget(edt_fi, 4, 4, 1, 1);

        edt_b = new QLineEdit(groupBox_3);
        edt_b->setObjectName(QString::fromUtf8("edt_b"));

        gridLayout_3->addWidget(edt_b, 4, 2, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(11);
        label_7->setFont(font1);

        gridLayout_3->addWidget(label_7, 3, 0, 1, 1);

        edt_nt = new QLineEdit(groupBox_3);
        edt_nt->setObjectName(QString::fromUtf8("edt_nt"));

        gridLayout_3->addWidget(edt_nt, 2, 6, 1, 1);

        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy3);
        label_3->setFont(font1);

        gridLayout_3->addWidget(label_3, 3, 5, 1, 1);

        label_1 = new QLabel(groupBox_3);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        sizePolicy3.setHeightForWidth(label_1->sizePolicy().hasHeightForWidth());
        label_1->setSizePolicy(sizePolicy3);
        label_1->setFont(font1);

        gridLayout_3->addWidget(label_1, 0, 5, 1, 1);

        edt_cf = new QLineEdit(groupBox_3);
        edt_cf->setObjectName(QString::fromUtf8("edt_cf"));

        gridLayout_3->addWidget(edt_cf, 0, 4, 1, 1);

        edt_kx = new QLineEdit(groupBox_3);
        edt_kx->setObjectName(QString::fromUtf8("edt_kx"));

        gridLayout_3->addWidget(edt_kx, 2, 2, 1, 1);

        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        label_2->setFont(font1);

        gridLayout_3->addWidget(label_2, 1, 5, 1, 1);

        edt_mu = new QLineEdit(groupBox_3);
        edt_mu->setObjectName(QString::fromUtf8("edt_mu"));

        gridLayout_3->addWidget(edt_mu, 3, 2, 1, 1);

        edt_nx = new QLineEdit(groupBox_3);
        edt_nx->setObjectName(QString::fromUtf8("edt_nx"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(edt_nx->sizePolicy().hasHeightForWidth());
        edt_nx->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(edt_nx, 0, 6, 1, 1);

        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font1);

        gridLayout_3->addWidget(label_9, 4, 3, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);

        gridLayout_3->addWidget(label_13, 0, 3, 1, 1);

        edt_cr = new QLineEdit(groupBox_3);
        edt_cr->setObjectName(QString::fromUtf8("edt_cr"));

        gridLayout_3->addWidget(edt_cr, 1, 4, 1, 1);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        sizePolicy3.setHeightForWidth(label_16->sizePolicy().hasHeightForWidth());
        label_16->setSizePolicy(sizePolicy3);
        label_16->setFont(font1);

        gridLayout_3->addWidget(label_16, 2, 5, 1, 1);

        edt_pw = new QLineEdit(groupBox_3);
        edt_pw->setObjectName(QString::fromUtf8("edt_pw"));

        gridLayout_3->addWidget(edt_pw, 0, 2, 1, 1);

        edt_pe = new QLineEdit(groupBox_3);
        edt_pe->setObjectName(QString::fromUtf8("edt_pe"));

        gridLayout_3->addWidget(edt_pe, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        gridLayout_3->addWidget(label_6, 2, 0, 1, 1);

        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        edt_dx = new QLineEdit(groupBox_3);
        edt_dx->setObjectName(QString::fromUtf8("edt_dx"));
        sizePolicy4.setHeightForWidth(edt_dx->sizePolicy().hasHeightForWidth());
        edt_dx->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(edt_dx, 1, 6, 1, 1);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);

        gridLayout_3->addWidget(label_12, 1, 3, 1, 1);

        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font1);

        gridLayout_3->addWidget(label_8, 4, 0, 1, 1);

        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        gridLayout_3->addWidget(label_5, 1, 0, 1, 1);

        edt_dt = new QLineEdit(groupBox_3);
        edt_dt->setObjectName(QString::fromUtf8("edt_dt"));
        sizePolicy4.setHeightForWidth(edt_dt->sizePolicy().hasHeightForWidth());
        edt_dt->setSizePolicy(sizePolicy4);

        gridLayout_3->addWidget(edt_dt, 3, 6, 1, 1);

        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy3.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy3);
        label_11->setFont(font1);

        gridLayout_3->addWidget(label_11, 4, 5, 1, 1);

        edt_T = new QLineEdit(groupBox_3);
        edt_T->setObjectName(QString::fromUtf8("edt_T"));

        gridLayout_3->addWidget(edt_T, 4, 6, 1, 1);

        edt_L = new QLineEdit(groupBox_3);
        edt_L->setObjectName(QString::fromUtf8("edt_L"));

        gridLayout_3->addWidget(edt_L, 5, 6, 1, 1);

        label_10 = new QLabel(groupBox_3);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy3.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy3);
        label_10->setFont(font1);

        gridLayout_3->addWidget(label_10, 5, 5, 1, 1);

        edt_dz = new QLineEdit(groupBox_3);
        edt_dz->setObjectName(QString::fromUtf8("edt_dz"));

        gridLayout_3->addWidget(edt_dz, 2, 4, 1, 1);

        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font1);

        gridLayout_3->addWidget(label_15, 2, 3, 1, 1);

        edt_dy = new QLineEdit(groupBox_3);
        edt_dy->setObjectName(QString::fromUtf8("edt_dy"));

        gridLayout_3->addWidget(edt_dy, 3, 4, 1, 1);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);

        gridLayout_3->addWidget(label_14, 3, 3, 1, 1);


        horizontalLayout_2->addWidget(groupBox_3);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName(QString::fromUtf8("horizontalLayout_1"));
        horizontalLayout_1->setContentsMargins(5, 5, 5, 5);
        btn_run = new QPushButton(centralwidget);
        btn_run->setObjectName(QString::fromUtf8("btn_run"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Segoe UI"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        btn_run->setFont(font2);

        horizontalLayout_1->addWidget(btn_run);

        time_slider = new QSlider(centralwidget);
        time_slider->setObjectName(QString::fromUtf8("time_slider"));
        time_slider->setOrientation(Qt::Horizontal);
        time_slider->setTickPosition(QSlider::TicksBelow);
        time_slider->setTickInterval(0);

        horizontalLayout_1->addWidget(time_slider);

        spin_box_current_time_step = new QSpinBox(centralwidget);
        spin_box_current_time_step->setObjectName(QString::fromUtf8("spin_box_current_time_step"));

        horizontalLayout_1->addWidget(spin_box_current_time_step);

        cmb_solve_steps = new QComboBox(centralwidget);
        cmb_solve_steps->setObjectName(QString::fromUtf8("cmb_solve_steps"));

        horizontalLayout_1->addWidget(cmb_solve_steps);


        verticalLayout->addLayout(horizontalLayout_1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 911, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Reservoir Fluid Simulator 1D", nullptr));
        QTableWidgetItem *___qtablewidgetitem = data->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "P (num)", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = data->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "P (exact)", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = data->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Abs", nullptr));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\201\320\270\321\201\321\202\320\265\320\274\321\213", nullptr));
        edt_fi->setText(QApplication::translate("MainWindow", "0.15", nullptr));
        edt_b->setText(QApplication::translate("MainWindow", "1.0", nullptr));
        label_7->setText(QApplication::translate("MainWindow", "mu", nullptr));
        edt_nt->setText(QApplication::translate("MainWindow", "100", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "dt", nullptr));
        label_1->setText(QApplication::translate("MainWindow", "nx", nullptr));
        edt_cf->setText(QApplication::translate("MainWindow", "1E-6", nullptr));
        edt_kx->setText(QApplication::translate("MainWindow", "10", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "dx", nullptr));
        edt_mu->setText(QApplication::translate("MainWindow", "15", nullptr));
        edt_nx->setText(QApplication::translate("MainWindow", "100", nullptr));
        label_9->setText(QApplication::translate("MainWindow", "\317\206", nullptr));
        label_13->setText(QApplication::translate("MainWindow", "Cf", nullptr));
        edt_cr->setText(QApplication::translate("MainWindow", "1E-5", nullptr));
        label_16->setText(QApplication::translate("MainWindow", "nt", nullptr));
        edt_pw->setText(QApplication::translate("MainWindow", "50", nullptr));
        edt_pe->setText(QApplication::translate("MainWindow", "200", nullptr));
        label_6->setText(QApplication::translate("MainWindow", "kx", nullptr));
        label->setText(QApplication::translate("MainWindow", "Pw", nullptr));
        edt_dx->setText(QApplication::translate("MainWindow", "10", nullptr));
        label_12->setText(QApplication::translate("MainWindow", "Cr", nullptr));
        label_8->setText(QApplication::translate("MainWindow", "B", nullptr));
        label_5->setText(QApplication::translate("MainWindow", "Pe", nullptr));
        edt_dt->setText(QApplication::translate("MainWindow", "864", nullptr));
        label_11->setText(QApplication::translate("MainWindow", "T", nullptr));
        edt_T->setText(QApplication::translate("MainWindow", "86400", nullptr));
        edt_L->setText(QApplication::translate("MainWindow", "1000", nullptr));
        label_10->setText(QApplication::translate("MainWindow", "L", nullptr));
        edt_dz->setText(QApplication::translate("MainWindow", "10", nullptr));
        label_15->setText(QApplication::translate("MainWindow", "dz", nullptr));
        edt_dy->setText(QApplication::translate("MainWindow", "200", nullptr));
        label_14->setText(QApplication::translate("MainWindow", "dy", nullptr));
        btn_run->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\265\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
