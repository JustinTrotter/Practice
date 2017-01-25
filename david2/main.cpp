#include <iostream>
#include <map>
#include <string>

#include "cVector.h"
#include "cVectorManualIterator.h"
#include "cVectorNoIterator.h"
#include "cVectorSimpleIterator.h"

int main(int argc, char *argv[])
{
  cVectorNoIterator<unsigned int> VectorNoIterator{1u, 2u, 3u};

  std::cout << "cVectorNoIterator for (size_t i = 0u; i < VectorNoIterator.size(); ++i):";
  for (size_t i = 0u; i < VectorNoIterator.size(); ++i)
  {
    std::cout << " " << VectorNoIterator[i];
  }
  std::cout << std::endl;


  cVectorSimpleIterator<unsigned int> VectorSimpleIterator{4u, 5u, 6u};

  std::cout << "cVectorSimpleIterator for (typename cVectorSimpleIterator<unsigned int>::iterator it = VectorSimpleIterator.begin(); it != VectorSimpleIterator.end(); ++it):";
  for (typename cVectorSimpleIterator<unsigned int>::iterator it = VectorSimpleIterator.begin(); it != VectorSimpleIterator.end(); ++it)
  {
    std::cout << " " << *it;
  }
  std::cout << std::endl;

  std::cout << "cVectorSimpleIterator for (auto &Element : VectorSimpleIterator):";
  for (auto &Element : VectorSimpleIterator)
  {
    std::cout << " " << Element;
  }
  std::cout << std::endl;


  cVectorManualIterator<unsigned int> VectorManualIterator{7u, 8u, 9u};

  std::cout << "cVectorManualIterator for (typename cVectorManualIterator<unsigned int>::iterator it = Vector.begin(); it != Vector.end(); ++it):";
  for (typename cVectorManualIterator<unsigned int>::iterator it = VectorManualIterator.begin(); it != VectorManualIterator.end(); ++it)
  {
    std::cout << " " << *it;
  }
  std::cout << std::endl;

  std::cout << "cVectorManualIterator for (auto &Element : Vector):";
  for (auto &Element : VectorManualIterator)
  {
    std::cout << " " << Element;
  }
  std::cout << std::endl;

  std::cout << "cVectorManualIterator for (const auto &Element : Vector):";
  for (const auto &Element : VectorManualIterator)
  {
    std::cout << " " << Element;
  }
  std::cout << std::endl;

  std::cout << "cVectorManualIterator for (typename cVectorManualIterator<unsigned int>::reverse_iterator it = Vector.rbegin(); it != Vector.rend(); ++it):";
  for (typename cVectorManualIterator<unsigned int>::reverse_iterator it = VectorManualIterator.rbegin(); it != VectorManualIterator.rend(); ++it)
  {
    std::cout << " " << *it;
  }
  std::cout << std::endl;

  std::cout << "cVectorManualIterator for (typename cVectorManualIterator<unsigned int>::reverse_iterator it = Vector.rbegin(); it != Vector.rend();):";
  for (typename cVectorManualIterator<unsigned int>::reverse_iterator it = VectorManualIterator.rbegin(); it != VectorManualIterator.rend();)
  {
    std::cout << " " << *it++;
  }
  std::cout << std::endl;


  cVector<double> Vector{1.1, 2.2, 3.3};

  std::cout << "cVector for (typename cVector<double>::iterator it = Vector.begin(); it != Vector.end(); ++it):";
  for (typename cVector<double>::iterator it = Vector.begin(); it != Vector.end(); ++it)
  {
    std::cout << " " << *it;
  }
  std::cout << std::endl;

  std::cout << "cVector for (auto &Element : Vector):";
  for (auto &Element : Vector)
  {
    std::cout << " " << Element;
  }
  std::cout << std::endl;

  std::cout << "cVector for (const auto &Element : Vector):";
  for (const auto &Element : Vector)
  {
    std::cout << " " << Element;
  }
  std::cout << std::endl;

  std::cout << "cVector for (typename cVector<double>::reverse_iterator it = Vector.rbegin(); it != Vector.rend(); ++it):";
  for (typename cVector<double>::reverse_iterator it = Vector.rbegin(); it != Vector.rend(); ++it)
  {
    std::cout << " " << *it;
  }
  std::cout << std::endl;

  std::cout << "cVector for (typename cVector<double>::reverse_iterator it = Vector.rbegin(); it != Vector.rend();):";
  for (typename cVector<double>::reverse_iterator it = Vector.rbegin(); it != Vector.rend();)
  {
    std::cout << " " << *it++;
  }
  std::cout << std::endl;

  // Example of iterator on an associative container.

  // Declare an ordered map with string keys and values.
  std::map<std::string, std::string> States;
  States["MS"] = "Mississippi";
  States["LA"] = "Louisiana";

  std::cout << "States ordered mapping:" << std::endl;
  for (const auto &State : States)
  {
    // Note that State is a std::pair.
    std::cout << "Key(first): " << State.first << ", Value(second): " << State.second << std::endl;
  }

	return 0;
}
