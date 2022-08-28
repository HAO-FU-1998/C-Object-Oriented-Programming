#ifndef REAL_H
#define REAL_H

#include "Number.h"


class Real : public Number
{
    public:
        virtual bool operator<(const Real& real);
        virtual bool operator<=(const Real& real);
        virtual bool operator>(const Real& real);
        virtual bool operator>=(const Real& real);
        const double getImaginaryPart() const;
    private:
        const static int Zero = 0;
};

#endif // REAL_H
