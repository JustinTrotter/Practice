#include <iostream>

#include "cTimer.h"
#include "cRectangle.h"
#include "cTriangle.h"

int main(int argc, char *argv[])
{
  tHighResTimer Timer;

	{
    // Notice order of construction and destruction.
	  cRectangle Rectangle(3.0, 4.0);

	  std::cout << "Area of : " << Rectangle << " is: " << Rectangle.Area() << std::endl;
	}

	std::cout << std::endl;

	{
    cBasicShape *Shape = new cTriangle(3.0, 4.0);
    std::cout << "Area of : " << *Shape << " is: " << Shape->Area() << std::endl;

    // Notice the triangle class is not destroyed.  Try making cBasicShape destructor virtual and see what happens.
    // Always make destructors virtual.
    delete Shape;
	}

  std::cout << std::endl;

	std::cout << "Duration: " << Timer.GetDuration() << "s." << std::endl;

	return 0;
}
