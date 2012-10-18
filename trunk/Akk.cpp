//
//  Copyright 2012 CERN, João Guilherme Martins Correia & Marcelo Baptista Barbosa.
//  All rights reserved.
//

#include "Akk.h"
#include <cmath>
#include <gsl/gsl_sf_coupling.h>

class AkkPrivate {

public:
    bool valid;

    // Input variables
    int dbl_ji; // initial state spin
    int dbl_j; // intermediate state spin
    int dbl_jf; // final state spin
    double d1;
    double d2;
    double firstAl;
    double firstAl1;
    double firstB211;
    double firstB212;
    double firstB222;
    double firstB411;
    double firstB412;
    double firstB422;
    double secondAl;
    double secondAl1;
    double secondB211;
    double secondB212;
    double secondB222;
    double secondB411;
    double secondB412;
    double secondB422;
    // Output variables
    double a22;
    double a24;
    double a42;
    double a44;

    AkkPrivate()
        : valid(false),
          dbl_ji(0),
          dbl_j(0),
          dbl_jf(0),
          d1(0.0),
          d2(0.0),
          firstAl(1.0),
          firstAl1(1.0),
          firstB211(1.0),
          firstB212(1.0),
          firstB222(1.0),
          firstB411(1.0),
          firstB412(1.0),
          firstB422(1.0),
          secondAl(1.0),
          secondAl1(1.0),
          secondB211(1.0),
          secondB212(1.0),
          secondB222(1.0),
          secondB411(1.0),
          secondB412(1.0),
          secondB422(1.0),
          a22(0.0),
          a24(0.0),
          a42(0.0),
          a44(0.0)
    {
    }

    void calculateAkk()
    {
        //  A2 (gamma 1)
        double a2gamma1 = calculateComponent(2, dbl_ji, dbl_j, firstAl1, firstAl, firstB211, firstB212, firstB222, d1);

        //  A4 (gamma 1)
        double a4gamma1 = calculateComponent(4, dbl_ji, dbl_j, firstAl1, firstAl, firstB411, firstB412, firstB422, d1);

        //  A2 (gamma 2)
        double a2gamma2 = calculateComponent(2, dbl_jf, dbl_j, secondAl1, secondAl, secondB211, secondB212, secondB222, d2);

        //  A4 (gamma 2)
        double a4gamma2 = calculateComponent(4, dbl_jf, dbl_j, secondAl1, secondAl, secondB411, secondB412, secondB422, d2);

        a22 = a2gamma1*a2gamma2;
        a24 = a2gamma1*a4gamma2;
        a42 = a4gamma1*a2gamma2;
        a44 = a4gamma1*a4gamma2;

        valid = true;
    }

    double calculateComponent(int k, int jx_2, int j_2, double Al1, double Al, double Bx11, double Bx12, double Bx22, double delta)
    {
        int lx_2;
        if (jx_2 >= j_2)
            lx_2 = jx_2-j_2;
        else
            lx_2 = j_2-jx_2;

        int lxPlusOne_2 = lx_2 + 2;

        double de = sqrt(Al1/Al)*delta;

        double f11 = Bx11*(((jx_2+j_2)/2+1)%2 ? -1 : 1)*sqrt((lx_2+1.)*(lx_2+1.)*(2*k+1.)*(j_2+1.))
        *gsl_sf_coupling_3j(lx_2, lx_2, 2*k, 2, -2, 0.)
        *gsl_sf_coupling_6j(j_2, j_2, 2*k, lx_2, lx_2, jx_2);

        double f12 = Bx12*(((jx_2+j_2)+1)%2 ? -1 : 1)*sqrt((lx_2+1.)*(lxPlusOne_2+1.)*(2*k+1.)*(j_2+1.))
        *gsl_sf_coupling_3j(lx_2, lxPlusOne_2, 2*k, 2, -2, 0.)
        *gsl_sf_coupling_6j(j_2, j_2, 2*k, lx_2, lxPlusOne_2, jx_2);

        double f22 = Bx22*(((jx_2+j_2)+1)%2 ? -1 : 1)*sqrt((lxPlusOne_2+1.)*(lxPlusOne_2+1.)*(2*k+1.)*(j_2+1.))
        *gsl_sf_coupling_3j(lxPlusOne_2, lxPlusOne_2, 2*k, 2, -2, 0.)
        *gsl_sf_coupling_6j(j_2, j_2, 2*k, lxPlusOne_2, lxPlusOne_2, jx_2);

        return (f11-2.*de*f12+de*de*f22)/(1+de*de);
    }

};


Akk::Akk()
    : d(new AkkPrivate)
{
}

Akk::~Akk()
{
    delete d;
}

void Akk::setInitialStateSpin(int doubledSpin)
{
    d->dbl_ji = doubledSpin;
    d->valid = false;
}

void Akk::setIntermediateStateSpin(int doubledSpin)
{
    d->dbl_j = doubledSpin;
    d->valid = false;
}

void Akk::setFinalStateSpin(int doubledSpin)
{
    d->dbl_jf = doubledSpin;
    d->valid = false;
}

void Akk::setPopulatingGammaMixing(double delta)
{
    d->d1 = delta;
    d->valid = false;
}

void Akk::setDepopulatingGammaMixing(double delta)
{
    d->d2 = delta;
    d->valid = false;
}

double Akk::a22()
{
    if (!d->valid)
        d->calculateAkk();
    return d->a22;
}

double Akk::a24()
{
    if (!d->valid)
        d->calculateAkk();
    return d->a24;
}

double Akk::a42()
{
    if (!d->valid)
        d->calculateAkk();
    return d->a42;
}

double Akk::a44()
{
    if (!d->valid)
        d->calculateAkk();
    return d->a44;
}
