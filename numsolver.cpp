#include "numsolver.h"


NumSolver::NumSolver(Grid& grid,double dt,double total_time):
          nx(grid.size()),
          N(static_cast<int>(total_time/dt)),
          dt(dt),
          total_time(total_time),
          x(new double[nx + 1]),
          P(new double*[N + 1]),
          grid(grid) {

}

void NumSolver::run() {
    P = new double*[N + 1];
    x = new double[nx + 1];
    std::copy(grid.getX(), grid.getX() + nx + 1, x);
    std::function<double(double)> function = grid.getBoundaryCondition();

    for(int n = 0; n < N + 1;++n){
        P[n] = new double[nx];
        if (n > 0){
            P[n][0] = function(x[0]);
            P[n][nx-1] = function(x[nx]);
        }
    }

    grid.setBoudaryCondition();
    grid.sourse();

    std::copy(grid.getP(), grid.getP() + nx, P[0]);

    for(int n = 0; n < N;++n) {
        double* D = new double[nx];
        double* T = new double[nx-1];
        double* Q = new double[nx];

        std::copy(grid.getD(), grid.getD() + nx, D);
        std::copy(grid.getT(), grid.getT() + nx - 1, T);
        std::copy(grid.getQ(), grid.getQ() + nx, Q);

        for(int i = 1; i < nx - 1; ++i) {
            P[n+1][i] = P[n][i] + (dt/D[i])*(T[i]*(P[n][i+1]-P[n][i])+T[i-1]*(P[n][i-1]-P[n][i])-Q[i-1]);
        }
        /*
        std::cout <<"Time step n = " << n << std::endl;
        for(int i = 0; i < nx; ++i){
            std::cout << "P[" << i + 1 << "] = " << P[n][i]/1E+5 << ";" << " ";
        }
        std::cout << std::endl;
        std::cout << std::endl;
        */
        grid.setPressure(P[n+1]);
        grid.update();

        delete [] D;
        delete [] T;
        delete [] Q;
    }
}

double** NumSolver::getPressure(){
    return P;
}

NumSolver::~NumSolver(){
    delete [] x;
    //delete [] P;
}
