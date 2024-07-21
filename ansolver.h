#ifndef ANSOLVER_H
#define ANSOLVER_H

#include <iostream>
#include <functional>
#include "mathhelper.h"
#include "props.h"

class AnSolver {
    int nx = 0;
    int m = 8;
    int N = 0;
    double dt = 0.0;
    double total_time = 0.0;
    double dimt = 0.0;
    double dimp = 0.0;
    double dimx = 0.0;
    double Pw = 0.0;
    double Pe = 0.0;
    double* t = nullptr;
    double* x = nullptr;
    double** P = nullptr;
    std::function<double(double,double)> solution;

    double StephestCoefficients(int i);
    double StephestAlgorithm(double td,double xd);


public:
    AnSolver(double dt,double total_time);
    ~AnSolver();
    void run();
    void setSolution(std::function<double(double,double)>& fun);
    void setCoords(int nx, double* xd);
    void setDims(double dimp, double dimt, double dimx);
    void setPressure(double Pw,double Pe);
    std::function<double(double,double)> getSol() const;

    double **getPressure();
    double* getTime();
};

#endif // ANSOLVER_H
