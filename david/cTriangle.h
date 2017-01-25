#ifndef cTriangle_h
#define cTriangle_h
#include "cBasicShape.h"

class cTriangle : public cBasicShape
{
public:
  cTriangle(void) = delete;
  cTriangle(const cTriangle &Triangle) = delete;
  cTriangle(double vBase, double vHeight);

  virtual ~cTriangle();

  // Identify basic shape.
  virtual std::string ID(void) const;

  // This is a virtual function that compute the area of a Triangle.
  virtual double Area(void) const;
};

// Interface with I/O system
std::ostream& operator<<(std::ostream &Stream, const cTriangle &Triangle);

#endif
