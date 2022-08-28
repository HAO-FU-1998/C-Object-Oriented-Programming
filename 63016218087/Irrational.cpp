#include "Irrational.h"
#include <iostream>
#include <sstream>

using namespace std;

Irrational::Irrational(double value)
{
    this -> value = value;
}

std::string Irrational::toString()  const
{
    stringstream ss;
    ss << value;
    return ss.str();
}

const double Irrational::getRealPart() const
{
    return value;
}
