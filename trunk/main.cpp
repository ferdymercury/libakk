//
//  main.cpp
//  AkkCalc
//
//  Copyright 2012 CERN, João Guilherme Martins Correia & Marcelo Baptista Barbosa.
//  All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include "AkkCalc.h"

using namespace std;

void example();
void fromFile(char *fileName);


int main(int argc, char **argv)
{
    // ANSI Escape Code to clear the terminal
    cout << "\033[2J\033[1;1H";
 
    cout << "*********************************************************" << endl;
    cout << "*		\"Akk Calculator\"                        *" << endl;
    cout << "* Copyright 2012 CERN, João Guilherme Martins Correia & *" << endl;
    cout << "* Marcelo Baptista Barbosa                              *" << endl;
    cout << "*                                                       *" << endl;
    cout << "* DO NOT CHANGE THE FORMAT OF THE FILE OR IT WON'T WORK *" << endl;
    cout << "********************************************************#" << endl;
    
    
    // Uncomment to run the simple example
    //{example(); return 0;}
    
    
    // If the name of a file is given, read values from file, otherwise runs example()
    if ((argc == 2)) {
        fromFile(argv[1]);
    }
    else {
        //example();
        char fileName[50];
        cout << "\nInsert the file name:" << endl;
        cin >> fileName;
        
        fromFile(fileName);        
    }
    
    
    return 0;
}


void example()
{
    // Create class instance
    AkkCalc akk;
    
    // Example values for the cascade 111In -> 111Cd
    akk.ji = 3.5;
    akk.d1 = -0.144;
    akk.j = 2.5;
    akk.jf = 0.5;
    
    // Calculate the Akk values
    akk.calculateAkk();
    
    // Print the result
    cout << "\n";
    cout <<"a22 = " << akk.a22 << endl;
    cout <<"a24 = " << akk.a24 << endl;
    cout <<"a42 = " << akk.a42 << endl;
    cout <<"a44 = " << akk.a44 << endl;
    cout << "\n";
}

void fromFile(char *fileName)
{
    // Open file
    ifstream file;
    
	file.open(fileName, ios::in);
	
	if ( file.fail() ){
		cout << "Sorry, couldn't open the file" << endl;
		exit(1);
	}
    
    
    // creat class instance
    AkkCalc akk;
    
    
    // Read values from file
    file.ignore(500,'#');
    file >> akk.ji; file.ignore(500,'#');
    file >> akk.j; file.ignore(500,'#');
    file >> akk.jf; file.ignore(500,'#');
    
    file >> akk.d1; file.ignore(500,'#');
    file >> akk.d2; file.ignore(500,'#');
    
    file.ignore(500,'#');
    file >> akk.firstAl;
    file >> akk.firstAl1; file.ignore(500,'#');
    file >> akk.firstB211;
    file >> akk.firstB212;
    file >> akk.firstB222; file.ignore(500,'#');
    file >> akk.firstB411;
    file >> akk.firstB412;
    file >> akk.firstB422; file.ignore(500,'#');
    
    file.ignore(500,'#');
    file >> akk.secondAl;
    file >> akk.secondAl1; file.ignore(500,'#');
    file >> akk.secondB211;
    file >> akk.secondB212;
    file >> akk.secondB222; file.ignore(500,'#');
    file >> akk.secondB411;
    file >> akk.secondB412;
    file >> akk.secondB422; file.ignore(500,'#');
    
    file.close();
    
    // Calculate the Akk values
    akk.calculateAkk();
    
    
    // Print the result
    cout << "\n";
    cout <<"a22 = " << akk.a22 << endl;
    cout <<"a24 = " << akk.a24 << endl;
    cout <<"a42 = " << akk.a42 << endl;
    cout <<"a44 = " << akk.a44 << endl;
    cout << "\n";
}