#ifndef NUMSOLVER_H
#define NUMSOLVER_H

#include <vector>
#include "grid.h"


class NumSolver {
    int nx;
    int N = 0;
    double dt = 0.0;
    double total_time = 0.0;
    double* x = nullptr;
    double** S = nullptr;
    double** P = nullptr;
    Grid grid;

public:

    NumSolver(Grid& grid,double dt,double total_time);

    void run();
    double** stability();
    double** getPressure();

    ~NumSolver();
};

#endif // NUMSOLVER_H
