#ifndef IRRATIONAL_H
#define IRRATIONAL_H

#include "Real.h"

class Irrational : public Real
{
    public:
        Irrational(double value = 0);
        std::string toString()  const ;
        const double getRealPart() const ;
    private:
        double value;
};

#endif // IRRATIONAL_H
