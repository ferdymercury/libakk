//
//  AkkCalc.cpp
//  AkkCalc
//
//  Copyright 2012 CERN, João Guilherme Martins Correia & Marcelo Baptista Barbosa.
//  All rights reserved.
//

#include <cmath>
#include "AkkCalc.h"


// Constructor is used to ser default inital values
AkkCalc::AkkCalc()
{
    ji = 0.0;
    j = 0.0; // intermediate state spin
    jf = 0.0; // final state spin
    d1 = 0.0; // 
    d2 = 0.0;
    firstAl = 1.0;
    firstAl1 = 1.0;
    firstB211 = 1.0;
    firstB212 = 1.0;
    firstB222 = 1.0;
    firstB411 = 1.0;
    firstB412 = 1.0;
    firstB422 = 1.0;
    secondAl = 1.0;
    secondAl1 = 1.0;
    secondB211 = 1.0;
    secondB212 = 1.0;
    secondB222 = 1.0;
    secondB411 = 1.0;
    secondB412 = 1.0;
    secondB422 = 1.0;
    
    a22 = 0.0;
    a24 = 0.0;
    a42 = 0.0;
    a44 = 0.0;
}

void AkkCalc::calculateAkk()
{
    int k;
    double de, f11, f12, f22, l1, l2, l1PlusOne, l2PlusOne;
    double a2gamma1, a4gamma1, a2gamma2, a4gamma2;
    
    
    if ((ji-j)>=0) {
        l1 = ji-j;
    }
    else {
        l1 = j-ji;
    }
    
    if ((jf-j)>=0) {
        l2 = jf-j;
    }
    else {
        l2 = j-jf;
    }
    
    l1PlusOne = l1+1;
    l2PlusOne = l2+1;
    
    
    //##########
    //  A2 (gamma 1)
    //##########
    
    k = 2;
    de = sqrt(firstAl1/firstAl)*d1;
    
    f11 = firstB211*pow(-1.,ji+j+1)*sqrt((2.*l1+1.)*(2.*l1+1.)*(2*k+1.)*(2*j+1.))
        *gsl_sf_coupling_3j((int)(2.*l1),(int)(2.*l1),(int)(2.*k),(int)(2.*1.),(int)(2.*(-1.)),0.)
        *gsl_sf_coupling_6j((int)(2.*j),(int)(2.*j),(int)(2.*k),(int)(2.*l1),(int)(2.*l1),(int)(2.*ji));
    
    f12 = firstB212*pow(-1.,ji+j+1)*sqrt((2.*l1+1.)*(2.*l1PlusOne+1.)*(2*k+1.)*(2*j+1.))
    *gsl_sf_coupling_3j((int)(2.*l1),(int)(2.*l1PlusOne),(int)(2.*k),(int)(2.*1.),(int)(2.*(-1.)),0.)
    *gsl_sf_coupling_6j((int)(2.*j),(int)(2.*j),(int)(2.*k),(int)(2.*l1),(int)(2.*l1PlusOne),(int)(2.*ji));
    
    f22 = firstB222*pow(-1.,ji+j+1)*sqrt((2.*l1PlusOne+1.)*(2.*l1PlusOne+1.)*(2*k+1.)*(2*j+1.))
    *gsl_sf_coupling_3j((int)(2.*l1PlusOne),(int)(2.*l1PlusOne),(int)(2.*k),(int)(2.*1.),(int)(2.*(-1.)),0.)
    *gsl_sf_coupling_6j((int)(2.*j),(int)(2.*j),(int)(2.*k),(int)(2.*l1PlusOne),(int)(2.*l1PlusOne),(int)(2.*ji));
    
    a2gamma1 = (f11-2.*de*f12+de*de*f22)/(1+de*de);
    
    //##########
    //  A4 (gamma 1)
    //##########
    
    k = 4;
    de = sqrt(firstAl1/firstAl)*d1;
    
    f11 = firstB411*pow(-1.,ji+j+1)*sqrt((2.*l1+1.)*(2.*l1+1.)*(2*k+1.)*(2*j+1.))
    *gsl_sf_coupling_3j((int)(2.*l1),(int)(2.*l1),(int)(2.*k),(int)(2.*1.),(int)(2.*(-1.)),0.)
    *gsl_sf_coupling_6j((int)(2.*j),(int)(2.*j),(int)(2.*k),(int)(2.*l1),(int)(2.*l1),(int)(2.*ji));
    
    f12 = firstB412*pow(-1.,ji+j+1)*sqrt((2.*l1+1.)*(2.*l1PlusOne+1.)*(2*k+1.)*(2*j+1.))
    *gsl_sf_coupling_3j((int)(2.*l1),(int)(2.*l1PlusOne),(int)(2.*k),(int)(2.*1.),(int)(2.*(-1.)),0.)
    *gsl_sf_coupling_6j((int)(2.*j),(int)(2.*j),(int)(2.*k),(int)(2.*l1),(int)(2.*l1PlusOne),(int)(2.*ji));
    
    f22 = firstB422*pow(-1.,ji+j+1)*sqrt((2.*l1PlusOne+1.)*(2.*l1PlusOne+1.)*(2*k+1.)*(2*j+1.))
    *gsl_sf_coupling_3j((int)(2.*l1PlusOne),(int)(2.*l1PlusOne),(int)(2.*k),(int)(2.*1.),(int)(2.*(-1.)),0.)
    *gsl_sf_coupling_6j((int)(2.*j),(int)(2.*j),(int)(2.*k),(int)(2.*l1PlusOne),(int)(2.*l1PlusOne),(int)(2.*ji));
    
    a4gamma1 = (f11-2.*de*f12+de*de*f22)/(1+de*de);
    
    //##########
    //  A2 (gamma 2)
    //##########
    
    k = 2;
    de = sqrt(secondAl1/secondAl)*d2;
    
    f11 = secondB211*pow(-1.,jf+j+1)*sqrt((2.*l2+1.)*(2.*l2+1.)*(2*k+1.)*(2*j+1.))
    *gsl_sf_coupling_3j((int)(2.*l2),(int)(2.*l2),(int)(2.*k),(int)(2.*1.),(int)(2.*(-1.)),0.)
    *gsl_sf_coupling_6j((int)(2.*j),(int)(2.*j),(int)(2.*k),(int)(2.*l2),(int)(2.*l2),(int)(2.*jf));
    
    f12 = secondB212*pow(-1.,jf+j+1)*sqrt((2.*l2+1.)*(2.*l2PlusOne+1.)*(2*k+1.)*(2*j+1.))
    *gsl_sf_coupling_3j((int)(2.*l2),(int)(2.*l2PlusOne),(int)(2.*k),(int)(2.*1.),(int)(2.*(-1.)),0.)
    *gsl_sf_coupling_6j((int)(2.*j),(int)(2.*j),(int)(2.*k),(int)(2.*l2),(int)(2.*l2PlusOne),(int)(2.*jf));
    
    f22 = secondB222*pow(-1.,jf+j+1)*sqrt((2.*l2PlusOne+1.)*(2.*l2PlusOne+1.)*(2*k+1.)*(2*j+1.))
    *gsl_sf_coupling_3j((int)(2.*l2PlusOne),(int)(2.*l2PlusOne),(int)(2.*k),(int)(2.*1.),(int)(2.*(-1.)),0.)
    *gsl_sf_coupling_6j((int)(2.*j),(int)(2.*j),(int)(2.*k),(int)(2.*l2PlusOne),(int)(2.*l2PlusOne),(int)(2.*jf));
    
    a2gamma2 = (f11+2.*de*f12+de*de*f22)/(1+de*de);
    
    //##########
    //  A4 (gamma 4)
    //##########
    
    k = 4;
    de = sqrt(secondAl1/secondAl)*d2;
    
    f11 = secondB411*pow(-1.,jf+j+1)*sqrt((2.*l2+1.)*(2.*l2+1.)*(2*k+1.)*(2*j+1.))
    *gsl_sf_coupling_3j((int)(2.*l2),(int)(2.*l2),(int)(2.*k),(int)(2.*1.),(int)(2.*(-1.)),0.)
    *gsl_sf_coupling_6j((int)(2.*j),(int)(2.*j),(int)(2.*k),(int)(2.*l2),(int)(2.*l2),(int)(2.*jf));
    
    f12 = secondB412*pow(-1.,jf+j+1)*sqrt((2.*l2+1.)*(2.*l2PlusOne+1.)*(2*k+1.)*(2*j+1.))
    *gsl_sf_coupling_3j((int)(2.*l2),(int)(2.*l2PlusOne),(int)(2.*k),(int)(2.*1.),(int)(2.*(-1.)),0.)
    *gsl_sf_coupling_6j((int)(2.*j),(int)(2.*j),(int)(2.*k),(int)(2.*l2),(int)(2.*l2PlusOne),(int)(2.*jf));
    
    f22 = secondB422*pow(-1.,jf+j+1)*sqrt((2.*l2PlusOne+1.)*(2.*l2PlusOne+1.)*(2*k+1.)*(2*j+1.))
    *gsl_sf_coupling_3j((int)(2.*l2PlusOne),(int)(2.*l2PlusOne),(int)(2.*k),(int)(2.*1.),(int)(2.*(-1.)),0.)
    *gsl_sf_coupling_6j((int)(2.*j),(int)(2.*j),(int)(2.*k),(int)(2.*l2PlusOne),(int)(2.*l2PlusOne),(int)(2.*jf));
    
    a4gamma2 = (f11+2.*de*f12+de*de*f22)/(1+de*de);
            
    a22 = a2gamma1*a2gamma2;
    a24 = a2gamma1*a4gamma2;
    a42 = a4gamma1*a2gamma2;
    a44 = a4gamma1*a4gamma2;
}
