#include "cBasicShape.h"

#include <iostream>
#include <sstream>

unsigned int cBasicShape::ShapeCount = 1u;

cBasicShape::cBasicShape(double vBase, double vHeight) : Base(vBase), Height(vHeight)
{
  ShapeID = ShapeCount++;

  // Notice parent ID function is not called.
  std::cout << "Creating: " << ID() << std::endl;

  return;
}

cBasicShape::~cBasicShape(void)
{
  // Notice parent ID function is not called.
  std::cout << "Destroying: " << ID() << std::endl;

  return;
}

double cBasicShape::Area(void) const
{
  std::cerr << "This should never have been called." << std::endl;

  return -1.0;
}

std::string cBasicShape::ID(void) const
{
  std::ostringstream oss;
  oss << "BasicShape[id:" << ShapeID << ", base:" << Base << ", height:" << Height << "]";

  return oss.str();
}


std::ostream &operator<<(std::ostream &Stream, const cBasicShape &BasicShape)
{
  Stream << BasicShape.ID();

  return Stream;
}
