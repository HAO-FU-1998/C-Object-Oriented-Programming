#include "Number.h"
#include <iostream>
#include <cmath>
using namespace std;

bool Number::operator==(const Number& number) const
{
    if (abs(this -> getRealPart() - number.getRealPart()) < INFINITELY_SMALL && abs(this -> getImaginaryPart() - number.getImaginaryPart()) < INFINITELY_SMALL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Number::operator!=(const Number& number) const
{
    if (abs(this -> getRealPart() - number.getRealPart()) < INFINITELY_SMALL && abs(this -> getImaginaryPart() - number.getImaginaryPart()) < INFINITELY_SMALL)
    {
        return false;
    }
    else
    {
        return true;
    }
}
