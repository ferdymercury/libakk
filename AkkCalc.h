//
//  AkkCalc.h
//  AkkCalc
//
//  Copyright 2012 CERN, João Guilherme Martins Correia & Marcelo Baptista Barbosa.
//  All rights reserved.
//

#include <iostream>
#include <gsl/gsl_sf_coupling.h>

class AkkCalc {
public:
    // Constructor
    AkkCalc();
    
    // Input variables
    double ji; // initial state spin
    double j; // intermediate state spin
    double jf; // final state spin
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
    
    // Calculation routine
    void calculateAkk();
};