#ifndef PROPS_H
#define PROPS_H


class Props {
    double b = 0.0;
    double mu = 0.0;
    double cf = 0.0;
    double cr = 0.0;

public:
    Props();
    Props(double b,double mu,double cf,double cr);

    double B(double P);
    double MU(double P);
    double Cf();
    double Cr();

};

#endif // PROPS_H
