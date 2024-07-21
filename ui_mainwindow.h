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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_1;
    QPushButton *btn_run;
    QSlider *time_slider;
    QSpinBox *spin_box_current_time_step;
    QComboBox *cmb_solve_steps;
    QHBoxLayout *horizontalLayout_2;
    QWidget *wgt_tree_field;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *vl_tree_field;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *wgt_table_field;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *vl_table_field;
    QMenuBar *menubar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1151, 877);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe UI"));
        font.setPointSize(10);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_1 = new QHBoxLayout();
        horizontalLayout_1->setObjectName(QString::fromUtf8("horizontalLayout_1"));
        horizontalLayout_1->setContentsMargins(5, 5, 5, 5);
        btn_run = new QPushButton(centralwidget);
        btn_run->setObjectName(QString::fromUtf8("btn_run"));
        btn_run->setEnabled(true);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Segoe UI"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        btn_run->setFont(font1);

        horizontalLayout_1->addWidget(btn_run);

        time_slider = new QSlider(centralwidget);
        time_slider->setObjectName(QString::fromUtf8("time_slider"));
        time_slider->setEnabled(false);
        time_slider->setOrientation(Qt::Horizontal);
        time_slider->setTickPosition(QSlider::TicksBelow);
        time_slider->setTickInterval(0);

        horizontalLayout_1->addWidget(time_slider);

        spin_box_current_time_step = new QSpinBox(centralwidget);
        spin_box_current_time_step->setObjectName(QString::fromUtf8("spin_box_current_time_step"));
        spin_box_current_time_step->setEnabled(false);

        horizontalLayout_1->addWidget(spin_box_current_time_step);

        cmb_solve_steps = new QComboBox(centralwidget);
        cmb_solve_steps->setObjectName(QString::fromUtf8("cmb_solve_steps"));
        cmb_solve_steps->setEnabled(false);
        cmb_solve_steps->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_1->addWidget(cmb_solve_steps);


        verticalLayout->addLayout(horizontalLayout_1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, -1);
        wgt_tree_field = new QWidget(centralwidget);
        wgt_tree_field->setObjectName(QString::fromUtf8("wgt_tree_field"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wgt_tree_field->sizePolicy().hasHeightForWidth());
        wgt_tree_field->setSizePolicy(sizePolicy);
        wgt_tree_field->setMinimumSize(QSize(0, 0));
        verticalLayout_4 = new QVBoxLayout(wgt_tree_field);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        vl_tree_field = new QVBoxLayout();
        vl_tree_field->setObjectName(QString::fromUtf8("vl_tree_field"));

        verticalLayout_4->addLayout(vl_tree_field);


        horizontalLayout_2->addWidget(wgt_tree_field);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        tabWidget->addTab(tab, QString());

        horizontalLayout_2->addWidget(tabWidget);

        wgt_table_field = new QWidget(centralwidget);
        wgt_table_field->setObjectName(QString::fromUtf8("wgt_table_field"));
        sizePolicy.setHeightForWidth(wgt_table_field->sizePolicy().hasHeightForWidth());
        wgt_table_field->setSizePolicy(sizePolicy);
        wgt_table_field->setMinimumSize(QSize(0, 0));
        verticalLayout_5 = new QVBoxLayout(wgt_table_field);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        vl_table_field = new QVBoxLayout();
        vl_table_field->setSpacing(6);
        vl_table_field->setObjectName(QString::fromUtf8("vl_table_field"));

        verticalLayout_5->addLayout(vl_table_field);


        horizontalLayout_2->addWidget(wgt_table_field);


        verticalLayout->addLayout(horizontalLayout_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1151, 23));
        MainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(statusBar->sizePolicy().hasHeightForWidth());
        statusBar->setSizePolicy(sizePolicy1);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Reservoir Fluid Simulator 1D", nullptr));
        btn_run->setText(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\320\265\321\202", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\320\232\320\260\321\200\321\202\320\260", nullptr));
#ifndef QT_NO_STATUSTIP
        statusBar->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
