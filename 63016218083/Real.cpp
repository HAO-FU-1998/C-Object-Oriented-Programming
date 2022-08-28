#include "Real.h"
#include <iostream>

using namespace std;

const double Real::getImaginaryPart() const
{
  return Zero;
}

bool Real::operator < (const Real& real)
{
  if (this -> getRealPart() < real.getRealPart())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Real::operator <= (const Real& real)
{
  if (this -> getRealPart() <= real.getRealPart())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Real::operator > (const Real& real)
{
  if (this -> getRealPart() > real.getRealPart())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool Real::operator >= (const Real& real)
{
  if (this -> getRealPart() >= real.getRealPart())
  {
    return true;
  }
  else
  {
    return false;
  }
}
