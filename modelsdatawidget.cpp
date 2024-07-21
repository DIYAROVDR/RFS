#include "modelsdatawidget.h"


ModelsDataWidget::ModelsDataWidget(QWidget *parent) : QTreeWidget(parent) {
    mainFont.setPointSize(10);
    setFont(mainFont);
    setupTree();
    connect(cmb_type_left_boundary, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &ModelsDataWidget::currentTypeBoundaryChanged);
}

int ModelsDataWidget::Nx() {
    QLineEdit *lineEdit = qobject_cast<QLineEdit*>(itemWidget(nxItem,1));
    if (lineEdit) {
        return lineEdit->text().toInt();
    } else {
        return 0;
    }
}

int ModelsDataWidget::Nt() {
    return qobject_cast<QLineEdit*>(itemWidget(ntItem,1))->text().toInt();
}

int ModelsDataWidget::MaxIt() {
    return qobject_cast<QLineEdit*>(itemWidget(maxNewtonItItem,1))->text().toInt();
}

double ModelsDataWidget::Eps() {
    return qobject_cast<QLineEdit*>(itemWidget(epsItem,1))->text().toDouble();
}

double ModelsDataWidget::Dx() {
    return qobject_cast<QLineEdit*>(itemWidget(dxNumItem,1))->text().toDouble();
}

double ModelsDataWidget::Dy() {
    return qobject_cast<QLineEdit*>(itemWidget(dyNumItem,1))->text().toDouble();
}

double ModelsDataWidget::Dz() {
    return qobject_cast<QLineEdit*>(itemWidget(dzNumItem,1))->text().toDouble();
}

double ModelsDataWidget::Permx() {
    return qobject_cast<QLineEdit*>(itemWidget(permxNumItem,1))->text().toDouble()*1E-15;
}

double ModelsDataWidget::Poro() {
    return qobject_cast<QLineEdit*>(itemWidget(poroNumItem,1))->text().toDouble();
}

double ModelsDataWidget::Cr() {
    return qobject_cast<QLineEdit*>(itemWidget(CrNumItem,1))->text().toDouble()*1E-5;
}

double ModelsDataWidget::Pe() {
    return qobject_cast<QLineEdit*>(itemWidget(initPreNumItem,1))->text().toDouble()*1E+5;
}

double ModelsDataWidget::Mu() {
    return qobject_cast<QLineEdit*>(itemWidget(muNumItem,1))->text().toDouble()*1E-3;
}

double ModelsDataWidget::Cf() {
    return qobject_cast<QLineEdit*>(itemWidget(CfNumItem,1))->text().toDouble()*1E-5;
}

double ModelsDataWidget::B() {
    return qobject_cast<QLineEdit*>(itemWidget(BNumItem,1))->text().toDouble();
}

double ModelsDataWidget::Pw() {
    return qobject_cast<QLineEdit*>(itemWidget(PwItem,1))->text().toDouble()*1E+5;
}

double ModelsDataWidget::Qw() {
    return qobject_cast<QLineEdit*>(itemWidget(QwItem,1))->text().toDouble();
}

double ModelsDataWidget::totalTime() {
    return qobject_cast<QLineEdit*>(itemWidget(timeItem,1))->text().toDouble()*86400;
}

QString ModelsDataWidget::NumMethod() {
    return qobject_cast<QComboBox*>(itemWidget(typeItem,1))->currentText();
}

QString ModelsDataWidget::boundaryType() {
    return qobject_cast<QComboBox*>(itemWidget(typeCoditionItem,1))->currentText();
}



void ModelsDataWidget::setupTree() {
    this->setAlternatingRowColors(true);
    setColumnCount(2);
    QStringList headers;
    headers << "Параметр" << "Значение";
    setHeaderLabels(headers);

    QFont boldFont;
    boldFont.setBold(true);

    QStringList items;
    items << "Явный" << "Неявный";
    cmb_type_solve  = new QComboBox();
    cmb_type_left_boundary = new QComboBox();
    cmb_type_solve->setFont(mainFont);
    cmb_type_solve->addItems(items);
    items.clear();
    items << "P = const" << "No flow";
    cmb_type_left_boundary->setFont(mainFont);
    cmb_type_left_boundary->addItems(items);

    QString style = "QComboBox {"
    "    background-color: rgba(0, 0, 0, 0);"
    "    border: none;"
    "}"
    "QComboBox QAbstractItemView {"
    "    background-color: rgba(255, 255, 255, 255);"
    "}"
    "QComboBox::drop-down {"
    "    border: none;"
    "}"
    "QComboBox:focus {"
    "    background-color: rgba(0, 0, 0, 0);"
    "    border: none;"
    "}";

    cmb_type_solve->setStyleSheet(style);
    cmb_type_left_boundary->setStyleSheet(style);

    // Свойства численной модели
    numericalModel = new QTreeWidgetItem(this);
    numericalModel->setText(0, "Численная модель");
    numericalModel->setFont(0, boldFont);


    // Ветка численных параметров расчета
    calcParams = new QTreeWidgetItem(numericalModel);
    calcParams->setText(0, "Параметры расчета");

    nxItem = new QTreeWidgetItem(calcParams);
    nxItem->setText(0, "Количество ячеек nx");
    setItemWidget(nxItem, 1, createLineEdit("50", new QIntValidator(1, 10000, this)));

    ntItem = new QTreeWidgetItem(calcParams);
    ntItem->setText(0, "Количество временных шагов");
    setItemWidget(ntItem, 1, createLineEdit("200", new QIntValidator(1, 10000, this)));

    maxNewtonItItem = new QTreeWidgetItem(calcParams);
    maxNewtonItItem->setText(0, "Макс. число итераций Ньютона");
    setItemWidget( maxNewtonItItem, 1, createLineEdit("100", new QIntValidator(1, 10000, this)));

    epsItem = new QTreeWidgetItem(calcParams);
    epsItem->setText(0, "Допустимая погрешность метода");
    setItemWidget(epsItem, 1, createLineEdit("1E-5", new QDoubleValidator(1E-9, 1E-3, 5, this)));

    typeItem = new QTreeWidgetItem(calcParams);
    typeItem->setText(0, "Метод решения");
    setItemWidget(typeItem, 1, cmb_type_solve);


    // Ветка геометрии пласта
    geomNum = new QTreeWidgetItem(numericalModel);
    geomNum->setText(0, "Геометрия пласта");

    dxNumItem = new QTreeWidgetItem(geomNum);
    dxNumItem->setText(0, "Размер ячейки dx");
    setItemWidget(dxNumItem, 1, createLineEdit("10", new QDoubleValidator(0.0, 1000.0, 2, this)));

    dyNumItem = new QTreeWidgetItem(geomNum);
    dyNumItem->setText(0, "Ширина пласта dy");
    setItemWidget(dyNumItem, 1, createLineEdit("250", new QDoubleValidator(0.0, 5000.0, 2, this)));

    dzNumItem = new QTreeWidgetItem(geomNum);
    dzNumItem->setText(0, "Толщина пласта dz");
    setItemWidget(dzNumItem, 1, createLineEdit("15", new QDoubleValidator(0.0, 1000.0, 2, this)));


    // Ветка свойств пласта
    rockPropNum = new QTreeWidgetItem(numericalModel);
    rockPropNum->setText(0, "Свойства пласта");

    permxNumItem = new QTreeWidgetItem(rockPropNum);
    permxNumItem->setText(0, "Проницаемость");
    setItemWidget(permxNumItem, 1, createLineEdit("5", new QDoubleValidator(1E-5, 1E+5, 3, this)));

    poroNumItem = new QTreeWidgetItem(rockPropNum);
    poroNumItem->setText(0, "Пористость");
    setItemWidget(poroNumItem, 1, createLineEdit("0.2", new QDoubleValidator(0.0, 1.0, 3, this)));

    CrNumItem = new QTreeWidgetItem(rockPropNum);
    CrNumItem->setText(0, "Сжимаемость");
    setItemWidget(CrNumItem, 1, createLineEdit("1E-5", new QDoubleValidator(0.0, 1.0, 6, this)));

    initPreNumItem = new QTreeWidgetItem(rockPropNum);
    initPreNumItem->setText(0, "Начальное давление");
    setItemWidget(initPreNumItem, 1, createLineEdit("200", new QDoubleValidator(0.0, 350, 6, this)));



    // Ветка свойств флюида
    fluidPropNum = new QTreeWidgetItem(numericalModel);
    fluidPropNum->setText(0, "Свойства флюида");

    muNumItem = new QTreeWidgetItem(fluidPropNum);
    muNumItem->setText(0, "Вязкость");
    setItemWidget(muNumItem, 1, createLineEdit("15", new QDoubleValidator(0.0, 100, 3, this)));

    CfNumItem = new QTreeWidgetItem(fluidPropNum);
    CfNumItem->setText(0, "Сжимаемость");
    setItemWidget(CfNumItem, 1, createLineEdit("1E-6", new QDoubleValidator(0.0, 1E-3, 6, this)));

    BNumItem = new QTreeWidgetItem(fluidPropNum);
    BNumItem->setText(0, "Коэффициент расширения");
    setItemWidget(BNumItem, 1, createLineEdit("1.0", new QDoubleValidator(0.0, 1.0, 3, this)));


    // Ветка граничных условий
    boundaryConditionNum = new QTreeWidgetItem(numericalModel);
    boundaryConditionNum->setText(0, "Граничные условия");

    typeCoditionItem = new QTreeWidgetItem(boundaryConditionNum);
    typeCoditionItem->setText(0, "Тип левой границы");
    setItemWidget(typeCoditionItem, 1, cmb_type_left_boundary);

    PwItem = new QTreeWidgetItem(boundaryConditionNum);
    PwItem->setText(0, "Давление");
    setItemWidget(PwItem, 1, createLineEdit("50", new QDoubleValidator(0.0, 350, 6, this)));

    QwItem = new QTreeWidgetItem(boundaryConditionNum);
    QwItem->setText(0, "Расход");
    setItemWidget(QwItem, 1, createLineEdit("300", new QDoubleValidator(0.0, 1000, 6, this)));
    currentTypeBoundaryChanged(0);



    // Свойства аналитической модели
    analyticalModel = new QTreeWidgetItem(this);
    analyticalModel->setText(0, "Аналитическая модель");
    analyticalModel->setFont(0, boldFont);


    // Ветка геометрии пласта
    geomAn = new QTreeWidgetItem(analyticalModel);
    geomAn->setText(0, "Геометрия пласта");

    lenghttem = new QTreeWidgetItem(geomAn);
    lenghttem->setText(0, "Длина пласта L");
    setItemWidget(lenghttem, 1, createLineEdit("10.0", new QDoubleValidator(0.0, 1000.0, 2, this)));

    dyAnItem = new QTreeWidgetItem(geomAn);
    dyAnItem->setText(0, "Ширина пласта dy");
    setItemWidget(dyAnItem, 1, createLineEdit("1.0", new QDoubleValidator(0.0, 5000.0, 2, this)));

    dzAnItem = new QTreeWidgetItem(geomAn);
    dzAnItem->setText(0, "Толщина пласта dz");
    setItemWidget(dzAnItem, 1, createLineEdit("15", new QDoubleValidator(0.0, 1000.0, 2, this)));


    // Ветка свойств пласта
    rockPropAn = new QTreeWidgetItem(analyticalModel);
    rockPropAn->setText(0, "Свойства пласта");

    permxAnItem = new QTreeWidgetItem(rockPropAn);
    permxAnItem->setText(0, "Проницаемость");
    setItemWidget(permxAnItem, 1, createLineEdit("100", new QDoubleValidator(1E-5, 1E+5, 3, this)));

    poroAnItem = new QTreeWidgetItem(rockPropAn);
    poroAnItem->setText(0, "Пористость");
    setItemWidget(poroAnItem, 1, createLineEdit("0.15", new QDoubleValidator(0.0, 1.0, 3, this)));

    CrAnItem = new QTreeWidgetItem(rockPropAn);
    CrAnItem->setText(0, "Сжимаемость");
    setItemWidget(CrAnItem, 1, createLineEdit("1E-5", new QDoubleValidator(0.0, 1.0, 6, this)));


    // Ветка свойств флюида
    fluidPropAn = new QTreeWidgetItem(analyticalModel);
    fluidPropAn->setText(0, "Свойства флюида");

    muAnItem = new QTreeWidgetItem(fluidPropAn);
    muAnItem->setText(0, "Вязкость");
    setItemWidget(muAnItem, 1, createLineEdit("1.0", new QDoubleValidator(0.0, 1000, 2, this)));

    CrAnItem = new QTreeWidgetItem(fluidPropAn);
    CrAnItem->setText(0, "Сжимаемость");
    setItemWidget(CrAnItem, 1, createLineEdit("1e-6", new QDoubleValidator(0.0, 1E-3, 6, this)));

    BAnItem = new QTreeWidgetItem(fluidPropAn);
    BAnItem->setText(0, "Коэффициент расширения");
    setItemWidget(BAnItem, 1, createLineEdit("1.0", new QDoubleValidator(0.0, 1.0, 3, this)));



    generalParam = new QTreeWidgetItem(this);
    generalParam->setText(0, "Общие параметры");
    generalParam->setFont(0, boldFont);

    timeItem = new QTreeWidgetItem(generalParam);
    timeItem->setText(0, "Конечное расчетное время, сут");
    setItemWidget(timeItem, 1, createLineEdit("1", new QDoubleValidator(0.0, 5000, 2, this)));


    expandAll();
    header()->setSectionResizeMode(QHeaderView::ResizeToContents);
    //header()->setStretchLastSection(false);
}

void ModelsDataWidget::currentTypeBoundaryChanged(int index) {
    if(index == 0){
        if(itemWidget(PwItem,1) != nullptr){
            itemWidget(PwItem,1)->setEnabled(true);
        }
        if(itemWidget(QwItem,1) != nullptr){
            itemWidget(QwItem,1)->setEnabled(false);
        }
    }
    if(index == 1){
        if(itemWidget(PwItem,1) != nullptr){
            itemWidget(PwItem,1)->setEnabled(false);
        }
        if(itemWidget(QwItem,1) != nullptr){
            itemWidget(QwItem,1)->setEnabled(true);
        }
    }
}


QLineEdit* ModelsDataWidget::createLineEdit(const QString &text, QValidator *validator) {
    QLineEdit *lineEdit = new QLineEdit(text);
    lineEdit->setValidator(validator);
    lineEdit->setFrame(false);
    lineEdit->setStyleSheet("QLineEdit {background-color: rgba(0, 0, 0, 0);}");
    lineEdit->setFont(mainFont);
    return lineEdit;
}
