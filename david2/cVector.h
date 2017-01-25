#ifndef cVector_h
#define cVector_h

#include <algorithm>
#include <cassert>
#include <initializer_list>
#include <iterator>

template<typename Type>
class cVector
{
  // For each of the four iterators, implement the operators required for a forward iterator.
  // Use std::iterator to create the standard typedefs used by the standard library.

  // Forward iterator.
public:
  class iterator : public std::iterator<std::forward_iterator_tag, Type>
  {
  public:
      iterator(typename std::iterator<std::forward_iterator_tag, Type>::pointer ptr) : Pointer(ptr) {return;};
      inline iterator &operator=(const iterator &rhs) {Pointer = rhs.Pointer; return *this;};
      inline iterator operator++(int) {iterator Temp = *this; ++Pointer; return Temp;};
      inline iterator &operator++(void) {++Pointer; return *this;};
      inline typename std::iterator<std::forward_iterator_tag, Type>::reference operator*(void) {return *Pointer;};
      inline typename std::iterator<std::forward_iterator_tag, Type>::pointer operator->(void) {return Pointer;};
      inline bool operator==(const iterator &rhs) const {return Pointer == rhs.Pointer;};
      inline bool operator!=(const iterator &rhs) const {return Pointer != rhs.Pointer;};
  private:
      typename std::iterator<std::forward_iterator_tag, Type>::pointer Pointer;
  };

  // Constant forward iterator.
  class const_iterator : public std::iterator<std::forward_iterator_tag, Type>
   {
     public:
       const_iterator(typename std::iterator<std::forward_iterator_tag, Type>::pointer ptr) : Pointer(ptr) {return;};
       inline const_iterator &operator=(const const_iterator &rhs) {Pointer = rhs.Pointer; return *this;};
       inline const_iterator operator++(int) {const_iterator Temp = *this; ++Pointer; return Temp;};
       inline const_iterator &operator++(void) {++Pointer; return *this;};
       inline const typename std::iterator<std::forward_iterator_tag, Type>::reference operator*(void) {return *Pointer;};
       inline const typename std::iterator<std::forward_iterator_tag, Type>::pointer operator->(void) {return Pointer;};
       inline bool operator==(const const_iterator &rhs) const {return Pointer == rhs.Pointer;};
       inline bool operator!=(const const_iterator &rhs) const {return Pointer != rhs.Pointer;};
     private:
       typename std::iterator<std::forward_iterator_tag, Type>::pointer Pointer;
   };

  // Reverse iterator
  class reverse_iterator : public std::iterator<std::forward_iterator_tag, Type>
  {
  public:
      reverse_iterator(typename std::iterator<std::forward_iterator_tag, Type>::pointer ptr) : Pointer(ptr) {return;};
      inline reverse_iterator &operator=(const reverse_iterator &rhs) {Pointer = rhs.Pointer; return *this;};
      inline reverse_iterator operator++(int) {reverse_iterator Temp = *this; --Pointer; return Temp;};
      inline reverse_iterator &operator++(void) {--Pointer; return *this;};
      inline typename std::iterator<std::forward_iterator_tag, Type>::reference operator*(void) {return *Pointer;};
      inline typename std::iterator<std::forward_iterator_tag, Type>::pointer operator->(void) {return Pointer;};
      inline bool operator==(const reverse_iterator &rhs) const {return Pointer == rhs.Pointer;};
      inline bool operator!=(const reverse_iterator &rhs) const {return Pointer != rhs.Pointer;};
  private:
      typename std::iterator<std::forward_iterator_tag, Type>::pointer Pointer;
  };

  // Constant reverse iterator.
  class const_reverse_iterator : public std::iterator<std::forward_iterator_tag, Type>
   {
     public:
       const_reverse_iterator(typename std::iterator<std::forward_iterator_tag, Type>::pointer ptr) : Pointer(ptr) {return;};
       inline const_reverse_iterator &operator=(const const_reverse_iterator &rhs) {Pointer = rhs.Pointer; return *this;};
       inline const_reverse_iterator operator++(int) {const_reverse_iterator Temp = *this; --Pointer; return Temp;};
       inline const_reverse_iterator &operator++(void) {--Pointer; return *this;};
       inline const typename std::iterator<std::forward_iterator_tag, Type>::reference operator*(void) {return *Pointer;};
       inline const typename std::iterator<std::forward_iterator_tag, Type>::pointer operator->(void) {return Pointer;};
       inline bool operator==(const const_reverse_iterator &rhs) const {return Pointer == rhs.Pointer;};
       inline bool operator!=(const const_reverse_iterator &rhs) const {return Pointer != rhs.Pointer;};
     private:
       typename std::iterator<std::forward_iterator_tag, Type>::pointer Pointer;
   };

public:
  // No default constructor
  cVector(void) = delete;

  // No copy constructor
  cVector(const cVector<Type> &Vector) = delete;

  // Initialize constructor
  cVector(std::initializer_list<Type> Initializer)
  {
    // Remember vector size.
    nElements = Initializer.size();

    // Allocate space for data.
    data = new Type[nElements];

    // Ensure we got the space.
    assert(data);

    // Setup iterator begin/end values.
    pBegin = new iterator(data);
    assert(pBegin);
    pEnd = new iterator(data + nElements);
    assert(pEnd);
    pcBegin = new const_iterator(data);
    assert(pcBegin);
    pcEnd = new const_iterator(data + nElements);
    assert(pcEnd);

    prBegin = new reverse_iterator(data + nElements - 1u);
    assert(prBegin);
    prEnd = new reverse_iterator(data - 1u);
    assert(prEnd);
    pcrBegin = new const_reverse_iterator(data + nElements - 1u);
    assert(pcrBegin);
    pcrEnd = new const_reverse_iterator(data - 1u);
    assert(pcrEnd);

    // Iterators are ready.  Copy data.
    std::copy(Initializer.begin(), Initializer.end(), begin());

    return;
  };

  virtual ~cVector(void)
  {
    // Return space.
    delete [] data;

    data = nullptr;

    nElements = 0u;

    delete pBegin;
    pBegin = nullptr;

    delete pEnd;
    pEnd = nullptr;

    delete pcBegin;
    pcBegin = nullptr;

    delete pcEnd;
    pcEnd = nullptr;

    delete prBegin;
    prBegin = nullptr;

    delete prEnd;
    prEnd = nullptr;

    delete pcrBegin;
    pcrBegin = nullptr;

    delete pcrEnd;
    pcrEnd = nullptr;

    return;
  };

  // Operators
  inline Type &operator[](size_t Index) {return data[Index];};
  inline const Type &operator[](size_t Index) const {return data[Index];};

  // Forward iterator support.
  inline const iterator &begin(void) const {return *pBegin;};
  inline const iterator &end(void) const {return *pEnd;};
  inline const const_iterator &cbegin(void) const {return *pcBegin;};
  inline const const_iterator &cend(void) const {return *pcEnd;};

  // Reverse iterator support.
  inline const reverse_iterator &rbegin(void) const {return *prBegin;};
  inline const reverse_iterator &rend(void) const {return *prEnd;};
  inline const const_reverse_iterator &crbegin(void) const {return *pcrBegin;};
  inline const const_reverse_iterator &crend(void) const {return *pcrEnd;};

public:
  inline size_t size(void) const
  {
    return nElements;
  }

protected:
  size_t nElements;
  Type *data;

  iterator *pBegin;
  iterator *pEnd;
  const_iterator *pcBegin;
  const_iterator *pcEnd;

  reverse_iterator *prBegin;
  reverse_iterator *prEnd;
  const_reverse_iterator *pcrBegin;
  const_reverse_iterator *pcrEnd;
};
#endif
