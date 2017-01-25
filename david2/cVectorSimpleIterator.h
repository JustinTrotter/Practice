#ifndef cVectorSimpleIterator_h
#define cVectorSimpleIterator_h

#include <algorithm>
#include <cassert>
#include <initializer_list>

template<typename Type>
class cVectorSimpleIterator
{
public:
  // No default constructor
  cVectorSimpleIterator(void) = delete;

  // No copy constructor
  cVectorSimpleIterator(const cVectorSimpleIterator<Type> &VectorNoIterator) = delete;

  // Default constructor
  cVectorSimpleIterator(std::initializer_list<Type> Initializer)
  {
    // Remember vector size.
    nElements = Initializer.size();

    // Allocate space for data.
    data = new Type[nElements];

    // Ensure we got the space.
    assert(data);

    // Now that we have an iterator, we can use std::copy
    std::copy(Initializer.begin(), Initializer.end(), begin());

    return;
  };

  virtual ~cVectorSimpleIterator(void)
  {
    // Return space.
    delete [] data;

    data = nullptr;

    nElements = 0u;

    return;
  };

  // Operators
  inline Type &operator[](size_t Index) {return data[Index];};
  inline const Type &operator[](size_t Index) const {return data[Index];};

  // Simple iterator implementation.  Only these three lines are needed.
  typedef Type *iterator;
  inline iterator begin(void) const {return data + 0u;};
  inline iterator end(void) const {return data + nElements;};

public:
  inline size_t size(void) const
  {
    return nElements;
  }

protected:
  size_t nElements;
  Type *data;
};
#endif
