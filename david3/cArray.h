#ifndef cArray_h
#define cArray_h

#include <cassert>
#include <algorithm>
#include <initializer_list>
#include <ostream>
#include <iomanip>
#include <vector>
#include <string.h>

template<typename Type>
class cArray : public std::vector<Type>
{
public:

  // Default constructor
  cArray(void) : nRows(0u), nCols(0u)
    {
      return;
    };

  // Copy constructor
  cArray(const cArray<Type> &Array)
    {
      // Size array.
      resize(Array.GetnRows(), Array.GetnCols());

      // Copy data.
      std::copy(Array.begin(), Array.end(), std::vector<Type>::begin());

      return;
    };

  // Dimensional constructor, initialize to a value
  cArray(size_t ValnRows, size_t ValnCols, Type Val = Type(0)) :
    // Note the order of initializers is important.  Base class must come first.
    std::vector<Type>(ValnRows * ValnCols), nRows(ValnRows), nCols(ValnCols)
    {
      std::fill(std::vector<Type>::begin(), std::vector<Type>::end(), Val);

      return;
    };

  // Dimensional constructor, initialize from list
  cArray(size_t ValnRows, size_t ValnCols, const std::vector<Type> &InitialValues) :
    std::vector<Type>(ValnRows * ValnCols), nRows(ValnRows), nCols(ValnCols)
    {
      Conforms(ValnRows, ValnCols);

      std::copy(InitialValues.begin(), InitialValues.end(), std::vector<Type>::begin());

      return;
    };

  virtual ~cArray(void)
  {
    return;
  };

protected:
  inline void Conforms(size_t ValnRows, size_t ValnCols) const
  {
    assert((ValnRows == nRows) && (ValnCols == nCols));

    return;
  }

  inline void Conforms(const cArray<Type> &Temp) const
  {
    assert((Temp.nRows == nRows) && (Temp.nCols == nCols));

    return;
  }

public:
  inline size_t GetnRows(void) const
  {
    return nRows;
  }

  inline size_t GetnCols(void) const
  {
    return nCols;
  }

  inline void resize(size_t ValnRows, size_t ValnCols)
  {
    nRows = ValnRows;
    nCols = ValnCols;

    std::vector<Type>::resize(size());

    return;
  }

  inline size_t size(void) const
  {
    return nRows * nCols;
  }

  // Operators
public:
  inline cArray<Type> &operator =(const cArray<Type> &rhs)
  {
    // Resize current array.
    resize(rhs.GetnRows(), rhs.GetnCols());

    // Copy data
    std::copy(rhs.begin(), rhs.end(), std::vector<Type>::begin());

    return *this;
  }

  inline bool operator ==(const cArray<Type> &rhs)
  {
    // Ensure conformity
    Conforms(rhs);

    return memcmp(this->data(), rhs.data(), size() * sizeof(Type)) == 0;
  }

  inline bool operator !=(const cArray<Type> &rhs)
  {
    // Ensure conformity
    Conforms(rhs);

    return memcmp(this->data(), rhs.data(), size() * sizeof(Type)) != 0;
  }

  // Pre-increment
  inline cArray<Type> &operator ++(void)
  {
    // Pre-increment
    for (auto &Element : *this)
    {
      ++Element;
    }

    return *this;
  }

  // Post-increment -- Note the dummy int arg to signal post inc
  inline cArray<Type> operator ++(int)
  {
    // Remember value before increment
    cArray<Type> Temp(*this);

    // Increment
    for (auto &Element : *this)
    {
      ++Element;
    }

    // Return value before increment
    return Temp;
  }

  // Pre-decrement
  inline cArray<Type> &operator --(void)
  {
    // Pre-decrement
    for (auto &Element : *this)
    {
      --Element;
    }

    return *this;
  }

  // Post-decrement -- Note the dummy int arg to signal post dec
  inline cArray<Type> operator --(int)
  {
    // Remember value before decrement
    cArray<Type> Temp(*this);

    // Decrement
    for (auto &Element : *this)
    {
      --Element;
    }

    // Return value before decrement
    return Temp;
  }

  // Index operation
  inline Type &operator () (size_t Row, size_t Col)
  {
    return std::vector<Type>::operator[](Row * nCols + Col);
  }

  // Index operation
  inline const Type &operator () (size_t Row, size_t Col) const
  {
    return std::vector<Type>::operator[](Row * nCols + Col);
  }

  // Scalar operations

  inline cArray<Type> operator +(const Type Val) const
  {
    // Remember value before decrement
    cArray<Type> Temp(*this);

    // Add scalar to each element.
    for (auto &Element : Temp)
    {
      Element += Val;
    }

    // Return sum
    return Temp;
  }

  inline cArray<Type> &operator +=(const Type Val)
  {
    // Add scalar to each element.
    for (auto &Element : *this)
    {
      Element += Val;
    }

    // Return sum
    return *this;
  }

  inline cArray<Type> operator -(const Type Val) const
  {
    // Remember value before decrement
    cArray<Type> Temp(*this);

    // Subtract scalar from each element.
    for (auto &Element : Temp)
    {
      Element -= Val;
    }

    // Return sum
    return Temp;
  }

  inline cArray<Type> &operator -=(const Type Val)
  {
    // Subtract scalar from each element.
    for (auto &Element : *this)
    {
      Element += Val;
    }

    // Return sum
    return *this;
  }

  // Element-wise operations

  inline cArray<Type> operator +(const cArray<Type> rhs) const
  {
    // Ensure conformity.
    Conforms(rhs);
    
    // Remember value before summing
    cArray<Type> Temp(*this);

    // iterator for rhs starting at beginning
    // Note clarification syntax.  Sometime the compiler needs help recognizing a type.
    // Try removing "typename" and note the error.  This is how you fix it.
    typename std::vector<Type>::const_iterator it = rhs.begin();
    
    // Perform element-wise add
    for (auto &Element : Temp)
    {
      Element += *it++;
    }

    // Return sum
    return Temp;
  }

  inline cArray<Type> &operator +=(const cArray<Type> rhs)
  {
    // Ensure conformity.
    Conforms(rhs);

    // iterator for rhs starting at beginning
    typename std::vector<Type>::const_iterator it = rhs.begin();
    
    // Perform element-wise add
    for (auto &Element : *this)
    {
      Element += *it++;
    }

    // Return sum
    return *this;
  }

  inline cArray<Type> operator -(const cArray<Type> rhs) const
  {
    // Ensure conformity.
    Conforms(rhs);

    // Remember value before subtracting
    cArray<Type> Temp(*this);

    // iterator for rhs starting at beginning
    typename std::vector<Type>::const_iterator it = rhs.begin();

    // Perform element-wise subtraction
    for (auto &Element : Temp)
    {
      Element -= *it++;
    }

    // Return sum
    return Temp;
  }

  inline cArray<Type> &operator -=(const cArray<Type> rhs)
  {
    // Ensure conformity.
    Conforms(rhs);

    // iterator for rhs starting at beginning
    typename std::vector<Type>::const_iterator it = rhs.begin();

    // Perform element-wise subtraction
    for (auto &Element : *this)
    {
      Element -= *it++;
    }

    // Return difference
    return *this;
  }


protected:
  size_t nRows;
  size_t nCols;
};


// Interface with I/O system
template<typename Type>
std::ostream &operator <<(std::ostream &Stream, const cArray<Type> &Array)
{
  size_t nElements = 0u;

  // Remember field width.
  std::streamsize FieldWidth = Stream.width();

  for (const auto &Element : Array)
  {
    // Set width for each element.w
    Stream.width(FieldWidth);
    Stream << Element << ((++nElements % Array.GetnCols()) == 0u ? "\n" : "," );
  }

  return Stream;
}
#endif
