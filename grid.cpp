#include "grid.h"


Grid::Grid(int nx,double dx,double dy,double dz):
    nx(nx),
    dz(dz),
    dy(dy),
    dx(new double[nx]),
    x(new double[nx+1]),
    A(new double[nx+1]),
    V(new double[nx]),
    D(new double[nx]),
    T(new double[nx-1]),
    P(new double[nx]),
    q(new double[nx]),
    Q(new double[nx]),
    kx(new double[nx]),
    poro(new double[nx]),
    props(new Props[nx]) {

    std::fill(this->dx,this->dx + nx,dx);

    L = std::accumulate(this->dx, this->dx + nx, 0.0);

    for(int i = 0; i < nx;++i) {
       x[i] = i*this->dx[i];
       A[i] = dy*dz;
       V[i] = A[i]*this->dx[i];
       q[i] = 0.0;
       Q[i] = 0.0;
    }
    x[nx] = nx*this->dx[nx-1];
    A[nx] = dy*dz;
}

Grid::Grid(const Grid& other) :
    nx(other.nx),
    L(other.L),
    dz(other.dz),
    dy(other.dy),
    dx(new double[nx]),
    x(new double[nx+1]),
    A(new double[nx+1]),
    V(new double[nx]),
    D(new double[nx]),
    T(new double[nx-1]),
    P(new double[nx]),
    q(new double[nx]),
    Q(new double[nx]),
    kx(new double[nx]),
    poro(new double[nx]),
    props(new Props[nx]) {
    std::copy(other.dx, other.dx + nx, this->dx);
    std::copy(other.x, other.x + nx + 1, this->x);
    std::copy(other.A, other.A + nx + 1, this->A);
    std::copy(other.V, other.V + nx, this->V);
    std::copy(other.D, other.D + nx, this->D);
    std::copy(other.T, other.T + nx - 1, this->T);
    std::copy(other.P, other.P + nx, this->P);
    std::copy(other.q, other.q + nx, this->q);
    std::copy(other.Q, other.Q + nx, this->Q);
    std::copy(other.kx, other.kx + nx, this->kx);
    std::copy(other.poro, other.poro + nx, this->poro);
    std::copy(other.props, other.props + nx, this->props);

    boundaryCondition = other.boundaryCondition;
}

int Grid::size() {
    return nx;
}

void Grid::transmissibility() {
    double k = 0.0;
    double Fi = 0.0;
    double F = 0.0;

    for(int i = 0;i < nx - 1; ++i) {
        k = (dx[i] + dx[i+1])/(dx[i]/kx[i]+dx[i+1]/kx[i+1]);

        Fi = P[i+1] - P[i];

        if(Fi > 0) {
            F = 1/(props[i+1].B(P[i+1])*props[i+1].MU(P[i+1]));
        } else {
            F = 1/(props[i].B(P[i])*props[i].MU(P[i]));
        }
        T[i] = F*k*A[i]/dx[i];
    }
}

void Grid::compressibility() {
    for(int i = 0;i < nx; ++i) {
        D[i] = V[i]*poro[i]*(props[i].Cf()+props[i].Cr()/props[i].B(P[i]));
    }
}

void Grid::sourse() {
    Q[0] = T[0]*(P[1]-P[0]);
    for(int i = 1;i < nx; ++i) {
        Q[i] = - V[i]*q[i];
    }
}

void Grid::update() {
    transmissibility();
    compressibility();
    sourse();
}

void Grid::setPressure(double* P) {
    std::copy(P, P + nx, this->P);
}

void Grid::setInitPressure(double P) {
    std::fill(this->P,this->P + nx,P);
}


void Grid::setPermability(double kx) {
    std::fill(this->kx,this->kx + nx,kx);
}

void Grid::setPorosity(double poro) {
    std::fill(this->poro,this->poro + nx,poro);
}

void Grid::setPropertyFluid(const Props& props) {
    std::fill(this->props,this->props + nx,props);
}

void Grid::setBoudaryCondition(const std::function<double(double x)>& function){
    boundaryCondition = function;
}

void Grid::setBoudaryCondition() {
    P[0] = boundaryCondition(x[0]);
    P[nx-1] = boundaryCondition(x[nx]);
}

double *Grid::getP() {
    return P;
}

double *Grid::getT() {
    return T;
}

double *Grid::getD() {
    return D;
}

double *Grid::getQ() {
    return Q;
}

double *Grid::getX() {
    return x;
}

std::function<double (double x)> Grid::getBoundaryCondition() {
    return boundaryCondition;
}

Grid::~Grid() {
    delete[] dx;
    delete[] x;
    delete[] A;
    delete[] V;
    delete[] D;
    delete[] T;
    delete[] P;
    delete[] q;
    delete[] Q;
    delete[] kx;
    delete[] poro;
    delete[] props;
}











