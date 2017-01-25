#include "cRectangle.h"

#include <iostream>
#include <ostream>
#include <sstream>

cRectangle::cRectangle(double vBase, double vHeight) : cBasicShape(vBase, vHeight)
{
  std::cout << "Creating: " << ID() << std::endl;

  return;
}

cRectangle::~cRectangle(void)
{
  std::cout << "Destroying: " << ID() << std::endl;

  return;
}

double cRectangle::Area(void) const
{
  return Base * Height;
}

std::string cRectangle::ID(void) const
{
  std::ostringstream oss;
  oss << "Rectangle:" << cBasicShape::ID();

  return oss.str();
}

std::ostream &operator<<(std::ostream &Stream, const cRectangle &Rectangle)
{
  Stream << Rectangle.ID();

  return Stream;
}
