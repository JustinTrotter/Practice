#include <iostream>
#include <iomanip>

#include "cArray.h"

int main(int argc, char *argv[])
{
  cArray<unsigned int> a( 3u, 3u, { 1u, 2u, 3u,
                                    4u, 5u, 6u,
                                    7u, 8u, 9u});
  cArray<unsigned int> b;
  cArray<unsigned int> c(3u, 3u, 0u);


  b = a;

  std::cout << "a:" << std::endl;
  std::cout.width(3);
  std::cout << a;

  b(1,1) = 9u;

  std::cout << std::endl;
  std::cout << "b:" << std::endl;
  std::cout << b;

  std::cout << std::endl;
  std::cout << "a==b:" << std::endl;
  std::cout << (a==b) << std::endl;

  std::cout << std::endl;
  std::cout << "a!=b:" << std::endl;
  std::cout << (a!=b) << std::endl;

  std::cout << std::endl;
  std::cout << "c++:" << std::endl;
  std::cout << c++;

  std::cout << std::endl;
  std::cout << "c:" << std::endl;
  std::cout << c;

  std::cout << std::endl;
  std::cout << "--c:" << std::endl;
  std::cout << --c;

  std::cout << std::endl;
  std::cout << "a+2:" << std::endl;
  std::cout.width(3);
  std::cout << a+2;

	return 0;
}
