#ifndef AKK_H
#define AKK_H

#include "akk_global.h"

class AkkPrivate;

class AKKSHARED_EXPORT Akk {
public:
    Akk();
    ~Akk();

    void setInitialStateSpin(int doubledSpin);
    void setIntermediateStateSpin(int doubledSpin);
    void setFinalStateSpin(int doubledSpin);
    void setPopulatingGammaMixing(double delta);
    void setDepopulatingGammaMixing(double delta);

    double a22();
    double a24();
    double a42();
    double a44();

private:
    AkkPrivate *d;
};

#endif // AKK_H
