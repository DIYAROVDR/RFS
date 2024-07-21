#ifndef TABLEDATAWIDGET_H
#define TABLEDATAWIDGET_H

#include <QTableWidget>
#include <QWidget>
#include <QHeaderView>
#include <QFont>

enum class TypeData {
    PRESSURE_VS_COORDS,
    PRESSURE_VS_TIME
};

class TableDataWidget : public QTableWidget
{
    Q_OBJECT
public:
    explicit TableDataWidget(QWidget* parent = nullptr);
    ~TableDataWidget();

    void setSize(int nx, int nt);
    void setData(double** Pnum, double** Pan, double** S);
    void setType(TypeData type);
    void setStepTime(double dt);
    void update(int value);
    bool checkStability(int value);

private:
    int nx = 0;
    int nt = 0;
    double dt = 0.0;
    double** Pnum = nullptr;
    double** Pan = nullptr;
    double** S = nullptr;
    TypeData type;

    void initializeTable();
};

#endif // TABLEDATAWIDGET_H
