#include "ansolver.h"

AnSolver::AnSolver(double dt,double total_time):dt(dt),total_time(total_time) {
    N = static_cast<int>(total_time/dt);
    t = new double[N+1];
    P = new double*[N+1];
    for(int n = 0; n < N + 1;++n) {
        t[n] = dt*n;
    }
}

AnSolver::~AnSolver() {
    //delete [] t;
    delete [] x;
    //delete [] P;
}

double AnSolver::StephestCoefficients(int i) {
    int jmin, jmax;
    double Sum = 0.0;
    double lambda;

    jmin = trunc((i + 1) / 2);
    jmax = std::min(i, m / 2);

    for (int j = jmin; j <= jmax; ++j){
        Sum += (pow(j, static_cast<int>(m / 2)) * 
                MathHelper::factorial(2 * j)) / 
               (MathHelper::factorial(m / 2 - j) * MathHelper::factorial(j) * MathHelper::factorial(j - 1) * MathHelper::factorial(i - j) * MathHelper::factorial(2 * j - i));
    }
    lambda = pow(-1, static_cast<int>(m / 2) + i) * Sum;
    return lambda;
}

double AnSolver::StephestAlgorithm(double td,double xd) {
    if (td == 0) return 0;
    double Sum = 0.0;
    for (int i = 1; i <= m; ++i) {
        Sum += StephestCoefficients(i) * solution(i * (log(2) / td),xd);
    }
    return (log(2) / td) * Sum;
}

void AnSolver::run() {
    for(int n = 0;n < N + 1;++n) {
        for(int i = 0; i < nx; ++i) {
            P[n][i] = Pw + dimp*StephestAlgorithm(t[n]*dimt,x[i]*dimx);
        }
    }
}

std::function<double (double,double)> AnSolver::getSol() const {
    return solution;
}

double **AnSolver::getPressure() {
    return P;
}

double *AnSolver::getTime() {
    return t;
}

void AnSolver::setSolution(std::function<double (double,double)> &fun) {
    solution = fun;
}

void AnSolver::setCoords(int nx, double *x) {
    this->nx = nx;
    this->x = new double[nx + 1];
    
    for(int n = 0; n < N + 1;++n) {
        P[n] = new double[nx];
    }
    
    std::copy(x, x + nx + 1, this->x);
}

void AnSolver::setDims(double dimp, double dimt,double dimx) {
    this->dimp = dimp;
    this->dimt = dimt;
    this->dimx = dimx;
}


void AnSolver::setPressure(double Pw, double Pe) {
    this->Pw = Pw;
    this->Pe = Pe;
}






