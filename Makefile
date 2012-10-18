OBJS = AkkCalc.o main.o
CC = g++
GSLPATH = /sw

CFLAGS = -O2 -Wall -I$(GSLPATH)/include -c
LFLAGS = -O2 -Wall -L$(GSLPATH)/lib -lgsl -lgslcblas

all : akkcalc

akkcalc : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o akkcalc

AkkCalc.o : AkkCalc.cpp AkkCalc.h
	$(CC) $(CFLAGS) AkkCalc.cpp

main.o : main.cpp AkkCalc.h AkkCalc.o
	$(CC) $(CFLAGS) main.cpp

clean : 
	\rm -f *.o *~ akkcalc
