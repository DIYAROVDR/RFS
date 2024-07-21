#ifndef MODELSDATAWIDGET_H
#define MODELSDATAWIDGET_H

#include <QTreeWidget>
#include <QObject>
#include <QWidget>
#include <QFont>
#include <QHeaderView>
#include <QLineEdit>
#include <QDoubleValidator>
#include <QIntValidator>
#include <QComboBox>
#include <functional>

class ModelsDataWidget : public QTreeWidget {
    Q_OBJECT
public:
    ModelsDataWidget(QWidget *parent = nullptr);
    int Nx();
    int Nt();
    int MaxIt();
    double Eps();
    double Dx();
    double Dy();
    double Dz();
    double Permx();
    double Poro();
    double Cr();
    double Pe();
    double Mu();
    double Cf();
    double B();
    double Pw();
    double Qw();
    double totalTime();
    QString NumMethod();
    QString boundaryType();


private:
    QFont mainFont;
    QComboBox* cmb_type_solve;
    QComboBox* cmb_type_left_boundary;

    // Численная модель.
    QTreeWidgetItem *numericalModel;

    QTreeWidgetItem *calcParams;
    QTreeWidgetItem *nxItem;
    QTreeWidgetItem *ntItem;
    QTreeWidgetItem *maxNewtonItItem;
    QTreeWidgetItem *epsItem;
    QTreeWidgetItem *typeItem;

    QTreeWidgetItem *geomNum;
    QTreeWidgetItem *dxNumItem;
    QTreeWidgetItem *dyNumItem;
    QTreeWidgetItem *dzNumItem;

    QTreeWidgetItem *rockPropNum;
    QTreeWidgetItem *permxNumItem;
    QTreeWidgetItem *poroNumItem;
    QTreeWidgetItem *CrNumItem;
    QTreeWidgetItem *initPreNumItem;

    QTreeWidgetItem *fluidPropNum;
    QTreeWidgetItem *muNumItem;
    QTreeWidgetItem *CfNumItem;
    QTreeWidgetItem *BNumItem;

    QTreeWidgetItem *boundaryConditionNum;
    QTreeWidgetItem *typeCoditionItem;
    QTreeWidgetItem *PwItem;
    QTreeWidgetItem *QwItem;

    // Аналитическая модель
    QTreeWidgetItem *analyticalModel;

    QTreeWidgetItem *geomAn;
    QTreeWidgetItem *lenghttem;
    QTreeWidgetItem *dyAnItem;
    QTreeWidgetItem *dzAnItem;

    QTreeWidgetItem *rockPropAn;
    QTreeWidgetItem *permxAnItem;
    QTreeWidgetItem *poroAnItem;
    QTreeWidgetItem *CrAnItem;

    QTreeWidgetItem *fluidPropAn;
    QTreeWidgetItem *muAnItem;
    QTreeWidgetItem *CfAnItem;
    QTreeWidgetItem *BAnItem;


    QTreeWidgetItem *generalParam;

    QTreeWidgetItem *timeItem;

    void setupTree();
    void currentTypeBoundaryChanged(int index);
    QLineEdit* createLineEdit(const QString &text, QValidator *validator);

};

#endif // MODELSDATAWIDGET_H
