#ifndef NUMSOLVER_H
#define NUMSOLVER_H

#include <vector>
#include "grid.h"

enum class TypeSolve {
    EXPLICIT,
    IMPLICIT
};

class NumSolver {
    int nx;
    int N = 0;
    int max_iterations = 100;
    double dt = 0.0;
    double t_end = 0.0;
    double* x = nullptr;
    double** S = nullptr;
    double** P = nullptr;
    Grid grid;
    std::function<double(double)> function;
    TypeSolve type;

public:

    NumSolver(Grid& grid,double dt,double total_time);

    void run();
    void setTypeSolve(TypeSolve type);
    void setMaxIt(int maxIt);
    double** stability();
    double** getPressure();

    ~NumSolver();
private:
    void explicitSol();
    void implicitSol();
};

#endif // NUMSOLVER_H
