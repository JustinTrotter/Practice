#ifndef cRectangle_h
#define cRectangle_h
#include "cBasicShape.h"

class cRectangle : public cBasicShape
{
public:
  cRectangle(void) = delete;
  cRectangle(const cRectangle &Rect) = delete;
  cRectangle(double vBase, double vHeight);

  virtual ~cRectangle();

  // Identify basic shape.
  virtual std::string ID(void) const;

  // This is a virtual function that compute the area of a rectangle.
  virtual double Area(void) const;
};

// Interface with I/O system
std::ostream& operator<<(std::ostream &Stream, const cRectangle &Rectangle);

#endif
