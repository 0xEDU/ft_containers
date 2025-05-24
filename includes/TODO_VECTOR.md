# Vector

## Constructors

1. vector(); **DONE**

2. explicit vector( const Allocator& alloc ); **DONE**

3. explicit vector( size_type count,
                 const T& value = T(),
                 const Allocator& alloc = Allocator()); **DONE**

4. template< class InputIt >
	vector( InputIt first, InputIt last,
        const Allocator& alloc = Allocator() ); **DONE**

5. vector( const vector& other ); **DONE**

6. vector( const vector& other, const Allocator& alloc ); **DONE**

## Destructors

1. ~vector(); **DONE**

## Member types

- value_type	T **DONE**
- allocator_type	Allocator **DONE**
- size_type	Unsigned integer type (usually std::size_t) **DONE**
- difference_type	Signed integer type (usually std::ptrdiff_t) **DONE**
- reference	value_type& **DONE**
- const_reference	const value_type& **DONE**
- pointer  Allocator::pointer **DONE**
- const_pointer	 Allocator::const_pointer **DONE**
- iterator Vector iterator **DONE**
- const_iterator        Const Vector iterator
- reverse_iterator      Reverse Vector iterator
- const_reverse_iterator        Const Reverse Vector iterator

## Member functions

- operator= assigns values to the container **DONE**
- assign assigns values to the container // Here atm
- get_allocator returns the associated allocator

### Element access

- at access specified element with bounds checking
- operator[] access specified element
- front access the first element
- back access the last element
- data direct access to the underlying contiguous storage

### Capacity

- empty checks wheter the container is empty
- size returns the number of elements
- max_size returns the maximum possible number of elements (PDF note: Since the max_size() value is different in each implementations, you don’t need to have the same return values as the STL for this method.)
- reserve reserves storage
- capacity returns the number of elements that can be held in currently allocated storage
- shrink_to_fit reduces memory usage by freeing unused memory

### Modifiers

- clear clears the contents
- insert inserts elements
- erase erases elements
- push_back adds an element to the end
- pop_back removes the last element
- resize changes the number of elements stored
- swap swap the contents

## Non-member functions

- operator==
- operator!=
- operator<
- operator<=    Lexicographically compares two vectors
- operator>
- operator>=

- std::swap(std::vector)  specializes the std::swap algorithm
