#include "cTriangle.h"

#include <iostream>
#include <ostream>
#include <sstream>

cTriangle::cTriangle(double vBase, double vHeight) : cBasicShape(vBase, vHeight)
{
  std::cout << "Creating: " << ID() << std::endl;

  return;
}

cTriangle::~cTriangle(void)
{
  std::cout << "Destroying: " << ID() << std::endl;

  return;
}

double cTriangle::Area(void) const
{
  return 0.5 * Base * Height;
}

std::string cTriangle::ID(void) const
{
  std::ostringstream oss;
  oss << "Triangle:" << cBasicShape::ID();

  return oss.str();
}

std::ostream &operator<<(std::ostream &Stream, const cTriangle &Triangle)
{
  Stream << Triangle.ID();

  return Stream;
}
