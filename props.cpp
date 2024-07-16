#include "props.h"

Props::Props() {

}

Props::Props(double b, double mu,double cf,double cr):
            b(b),
            mu(mu),
            cf(cf),
            cr(cr) {
}

double Props::B(double P) {
    static_cast<void>(P);
    return b;
}

double Props::MU(double P) {
    static_cast<void>(P);
    return mu;
}

double Props::Cf() {
    return cf;
}

double Props::Cr() {
    return cr;
}
