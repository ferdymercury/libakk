*********************************************************
*	"Akk Calculator"    ReadMe.txt                  *
* Copyright 2012 CERN, João Guilherme Martins Correia & *
* Marcelo Baptista Barbosa                              *
********************************************************#

To compile:
Change the GSLPATH variable in the Makefile to the path were the GSL library is installed.
Do "make" on the terminal.

To run:
Do "./akkcalc file.txt" to run from file.txt.
If only "./akkcalc" is typed, the file name will be asked.

To run the included example file, do "./akkcalc 111In_111Cd.txt"

The file template.txt shows the requested structure for the files to be used, so copy it every time you need and just change the values for the ones you need.


About the code:
To run a calculation, there's only need to create an instance from the class AkkCalc, and define the needed variables. They are always initiated with default values, so there's only need to change the needed variables. Then, run calculateAkk() and the output variables will have the right values.
See (and run) the function example() on main.cpp to see a very simple example on how to set a new calculation without an external file.

Marcelo Barbosa: marcelo.barbosa@cern.ch
João Guilherme Martins Correia: Guilherme.Correia@cern.ch
