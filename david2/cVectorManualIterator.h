#ifndef cVectorManualIterator_h
#define cVectorManualIterator_h

#include <algorithm>
#include <cassert>
#include <initializer_list>

template<typename Type>
class cVectorManualIterator
{
  // For each of the four iterators, implement the operators required for a forward iterator.
  // Also manually create the standard typedefs used by the standard library.

  // Forward iterator.
public:
  class iterator
  {
  public:
      typedef Type value_type;
      typedef Type& reference;
      typedef Type* pointer;
      typedef std::forward_iterator_tag iterator_category;
      typedef int difference_type;
      iterator(pointer ptr) : Pointer(ptr) {return;};
      inline iterator &operator=(const iterator &rhs) {Pointer = rhs.Pointer; return *this;};
      inline iterator operator++(int) {iterator Temp = *this; ++Pointer; return Temp;};
      inline iterator &operator++(void) {++Pointer; return *this;};
      reference operator*(void) {return *Pointer;};
      inline pointer operator->(void) {return Pointer;};
      inline bool operator==(const iterator &rhs) const {return Pointer == rhs.Pointer;};
      inline bool operator!=(const iterator &rhs) const {return Pointer != rhs.Pointer;};
  private:
      pointer Pointer;
  };

  // Constant forward iterator.
  class const_iterator
   {
     public:
       typedef Type value_type;
       typedef Type& reference;
       typedef Type* pointer;
       typedef int difference_type;
       typedef std::forward_iterator_tag iterator_category;
       const_iterator(pointer ptr) : Pointer(ptr) {return;};
       inline const_iterator &operator=(const const_iterator &rhs) {Pointer = rhs.Pointer; return *this;};
       inline const_iterator operator++(int) {const_iterator Temp = *this; ++Pointer; return Temp;};
       inline const_iterator &operator++(void) {++Pointer; return *this;};
       inline const reference operator*(void) {return *Pointer;};
       inline const pointer operator->(void) {return Pointer;};
       inline bool operator==(const const_iterator &rhs) const {return Pointer == rhs.Pointer;};
       inline bool operator!=(const const_iterator &rhs) const {return Pointer != rhs.Pointer;};
     private:
         pointer Pointer;
   };

  // Reverse iterator
  class reverse_iterator
  {
  public:
      typedef Type value_type;
      typedef Type& reference;
      typedef Type* pointer;
      typedef std::forward_iterator_tag iterator_category;
      typedef int difference_type;
      reverse_iterator(pointer ptr) : Pointer(ptr) {return;};
      inline reverse_iterator &operator=(const reverse_iterator &rhs) {Pointer = rhs.Pointer; return *this;};
      inline reverse_iterator operator++(int) {reverse_iterator Temp = *this; --Pointer; return Temp;};
      inline reverse_iterator &operator++(void) {--Pointer; return *this;};
      inline reference operator*(void) {return *Pointer;};
      inline pointer operator->(void) {return Pointer;};
      inline bool operator==(const reverse_iterator &rhs) const {return Pointer == rhs.Pointer;};
      inline bool operator!=(const reverse_iterator &rhs) const {return Pointer != rhs.Pointer;};
  private:
      pointer Pointer;
  };

  // Constant reverse iterator.
  class const_reverse_iterator
   {
     public:
       typedef Type value_type;
       typedef Type& reference;
       typedef Type* pointer;
       typedef int difference_type;
       typedef std::forward_iterator_tag iterator_category;
       const_reverse_iterator(pointer ptr) : Pointer(ptr) {return;};
       inline const_reverse_iterator &operator=(const const_reverse_iterator &rhs) {Pointer = rhs.Pointer; return *this;};
       const_reverse_iterator operator++(int) {const_reverse_iterator Temp = *this; --Pointer; return Temp;};
       const_reverse_iterator &operator++(void) {--Pointer; return *this;};
       const reference operator*(void) {return *Pointer;};
       const pointer operator->(void) {return Pointer;};
       bool operator==(const const_reverse_iterator &rhs) const {return Pointer == rhs.Pointer;};
       bool operator!=(const const_reverse_iterator &rhs) const {return Pointer != rhs.Pointer;};
     private:
         pointer Pointer;
   };

public:
  // No default constructor
  cVectorManualIterator(void) = delete;

  // No copy constructor
  cVectorManualIterator(const cVectorManualIterator<Type> &Vector) = delete;

  // Initialize constructor
  cVectorManualIterator(std::initializer_list<Type> Initializer)
  {
    // Remember vector size.
    nElements = Initializer.size();

    // Allocate space for data.
    data = new Type[nElements];

    // Ensure we got the space.
    assert(data);

    // Copy data.
    std::copy(Initializer.begin(), Initializer.end(), begin());

    return;
  };

  virtual ~cVectorManualIterator(void)
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

  // Forward iterator support.
  inline iterator begin(void) const {return iterator(data + 0u);};
  inline iterator end(void) const {return iterator(data + nElements);};
  inline const_iterator cbegin(void) const {return const_iterator(data + 0u);};
  inline const_iterator cend(void) const {return const_iterator(data + nElements);};

  // Reverse iterator support.
  inline reverse_iterator rbegin(void) const {return reverse_iterator(data + nElements - 1u);};
  inline reverse_iterator rend(void) const {return reverse_iterator(data - 1u);};
  inline const_reverse_iterator crbegin(void) const {return const_reverse_iterator(data + nElements - 1u);};
  inline const_reverse_iterator crend(void) const {return const_reverse_iterator(data -1u);};

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
