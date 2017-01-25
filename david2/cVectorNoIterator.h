#ifndef cVectorNoIterator_h
#define cVectorNoIterator_h

#include <cassert>
#include <initializer_list>

template<typename Type>
class cVectorNoIterator
{
public:
  // No default constructor
  cVectorNoIterator(void) = delete;

  // No copy constructor
  cVectorNoIterator(const cVectorNoIterator<Type> &VectorNoIterator) = delete;

  // Default constructor
  cVectorNoIterator(std::initializer_list<Type> Initializer)
  {
    // Remember vector size.
    nElements = Initializer.size();

    // Allocate space for data.
    data = new Type[nElements];

    // Ensure we got the space.
    assert(data);

    // Simple copy loop.
    typename std::initializer_list<Type>::const_iterator it = Initializer.begin();
    for (auto i = 0u; i < nElements; ++i)
    {
      data[i] = *it++;
    }

    return;
  };

  virtual ~cVectorNoIterator(void)
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
