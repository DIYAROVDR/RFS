#include "numsolver.h"


NumSolver::NumSolver(Grid& grid,double dt,double t_end):
          nx(grid.size()),
          N(static_cast<int>(t_end/dt)),
          dt(dt),
          t_end(t_end),
          x(new double[nx + 1]),
          S(new double*[N + 1]),
          P(new double*[N + 1]),
          grid(grid),
          function(grid.getBoundaryCondition()){
}

void NumSolver::run() {
    std::copy(grid.getX(), grid.getX() + nx + 1, x);

    for(int n = 0; n < N + 1;++n){
        P[n] = new double[nx];
        S[n] = new double[nx];
        if (n > 0){
            P[n][0] = function(x[0]);
            P[n][nx-1] = function(x[nx]);
        }
    }

    grid.setBoudaryCondition();
    grid.sourse();

    std::copy(grid.getP(), grid.getP() + nx, P[0]);

    if(type==TypeSolve::EXPLICIT) {
        explicitSol();
    }
    if(type==TypeSolve::IMPLICIT) {
        implicitSol();
    }
}

void NumSolver::explicitSol() {
    for(int n = 0; n < N;++n) {
        double* D = new double[nx];
        double* T = new double[nx-1];
        double* Q = new double[nx];

        std::copy(grid.getD(), grid.getD() + nx, D);
        std::copy(grid.getT(), grid.getT() + nx - 1, T);
        std::copy(grid.getQ(), grid.getQ() + nx, Q);

        for(int i = 1; i < nx - 1; ++i) {
            P[n+1][i] = P[n][i] + (dt/D[i])*(T[i]*(P[n][i+1]-P[n][i])+T[i-1]*(P[n][i-1]-P[n][i])-Q[i]);
        }

        for(int i = 0; i < nx; ++i) {
            if (i == 0){
                S[n][i] = D[i]/(T[i]);
            }
            S[n][i] = D[i]/(T[i]+T[i-1]);
        }

        grid.setPressure(P[n+1]);
        grid.update();

        delete [] D;
        delete [] T;
        delete [] Q;
    }
}


void NumSolver::setTypeSolve(TypeSolve type) {
    this->type = type;
}

void NumSolver::setMaxIt(int maxIt) {
    max_iterations = maxIt;
}



void NumSolver::implicitSol() {
    // Итерации по времени
    for(int n = 0; n < N; ++n) {
        double* D = new double[nx];
        double* T = new double[nx-1];
        double* Q = new double[nx];

        std::copy(grid.getD(), grid.getD() + nx, D);
        std::copy(grid.getT(), grid.getT() + nx - 1, T);
        std::copy(grid.getQ(), grid.getQ() + nx, Q);

        // Начальное приближение
        double* p_old = new double[nx];
        double* p_new = new double[nx];
        std::copy(P[n], P[n] + nx, p_old);

        // Итерации метода Ньютона-Рафсона
        for(int iter = 0; iter < max_iterations; ++iter) {
            double* F = new double[nx];
            double* deltaP = new double[nx];
            double** J = new double*[nx];
            for(int i = 0; i < nx; ++i) {
                J[i] = new double[nx]();
            }

            // Заполнение функции и якобиана
            for(int i = 1; i < nx - 1; ++i) {
                F[i] = -T[i] * p_old[i+1] + (D[i]/dt + T[i] + T[i-1]) * p_old[i] - T[i-1] * p_old[i-1] + Q[i] - D[i]/dt * P[n][i];

                J[i][i-1] = -T[i-1];
                J[i][i] = D[i]/dt + T[i] + T[i-1];
                J[i][i+1] = -T[i];
            }

            // Граничные условия
            F[0] = p_old[0] - function(x[0]);
            F[nx-1] = p_old[nx-1] - function(x[nx]);

            J[0][0] = 1.0;
            J[nx-1][nx-1] = 1.0;

            // Решение системы J * deltaP = -F
            // Используем метод прогонки (TDMA) для решения системы

            // Прямой ход
            double* c_prime = new double[nx];
            double* d_prime = new double[nx];
            c_prime[0] = J[0][1] / J[0][0];
            d_prime[0] = -F[0] / J[0][0];

            for(int i = 1; i < nx; ++i) {
                double m = 1.0 / (J[i][i] - J[i][i-1] * c_prime[i-1]);
                c_prime[i] = J[i][i+1] * m;
                d_prime[i] = (-F[i] - J[i][i-1] * d_prime[i-1]) * m;
            }

            // Обратный ход
            deltaP[nx-1] = d_prime[nx-1];
            for(int i = nx-2; i >= 0; --i) {
                deltaP[i] = d_prime[i] - c_prime[i] * deltaP[i+1];
            }

            // Обновление решения
            for(int i = 0; i < nx; ++i) {
                p_new[i] = p_old[i] + deltaP[i];
            }

            // Проверка сходимости
            double max_delta = 0.0;
            for(int i = 0; i < nx; ++i) {
                max_delta = std::max(max_delta, std::abs(deltaP[i]));
            }
            if(max_delta < 1e-6) {
                break;
            }

            std::copy(p_new, p_new + nx, p_old);

            delete[] F;
            delete[] deltaP;
            delete[] c_prime;
            delete[] d_prime;
            for(int i = 0; i < nx; ++i) {
                delete[] J[i];
            }
            delete[] J;
        }

        // Обновляем давление для следующего шага по времени
        std::copy(p_new, p_new + nx, P[n + 1]);

        grid.setPressure(P[n + 1]);
        grid.update();

        delete[] D;
        delete[] T;
        delete[] Q;
        delete[] p_old;
        delete[] p_new;
    }
}




double** NumSolver::stability() {
    return S;
}

double** NumSolver::getPressure(){
    return P;
}

NumSolver::~NumSolver() {
    delete [] x;
    //delete [] P;
}

