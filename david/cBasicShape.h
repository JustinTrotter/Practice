#ifndef cBasicShape_h
#define cBasicShape_h

#include <string>

class cBasicShape
{
  // We need to give public access.
public:
  // Do not autogenerate default constructor.
  cBasicShape(void) = delete;

  // Do not autogenerate default copy constructor;
  cBasicShape(const cBasicShape &Shape) = delete;

  // This is the constructor use by parent classes.  It initialized the Base and Height attribute.
  // The body of the constructor is simple and declared inline.
  cBasicShape(double vBase, double vHeight);

  // Destructor.  Notice execution difference if this is virtual.
  virtual ~cBasicShape(void);

  // Identify basic shape.
  virtual std::string ID(void) const;

  // This is a virtual function that redirects to the parent.
  virtual double Area(void) const;

  // Base and Height are accessible to parents, but nobody else.
protected:
  double Base;
  double Height;
  unsigned int ShapeID;

  static unsigned int ShapeCount;
};

// Interface with I/O system
std::ostream& operator<<(std::ostream &Stream, const cBasicShape &BasicShape);
#endif
