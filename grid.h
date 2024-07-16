#ifndef GRID_H
#define GRID_H

#include <functional>
#include <algorithm>
#include <numeric>
#include <iostream>

#include "props.h"

class Grid {
    int nx;
    double L;
    double dz;
    double dy;
    double* dx;
    double* x;
    double* A;
    double* V;
    double* D;
    double* T;
    double* P;
    double* q;
    double* Q;
    double* kx;
    double* poro;
    Props* props;
    std::function<double(double x)> boundaryCondition;

public:

    Grid(int nx,double dx,double dy,double dz);
    Grid(const Grid& other);

    int size();

    void transmissibility();
    void compressibility();
    void sourse();
    void update();

    void setPressure(double* P);
    void setInitPressure(double P);
    void setPermability(double kx);
    void setPorosity(double poro);
    void setPropertyFluid(const Props& props);
    void setBoudaryCondition(const std::function<double(double x)>& function);
    void setBoudaryCondition();

    double* getP();
    double* getT();
    double* getD();
    double* getQ();
    double* getX();

    std::function<double(double x)> getBoundaryCondition();

    ~Grid();
};


#endif // GRID_H
