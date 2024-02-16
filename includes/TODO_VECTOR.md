# Constructors

DONE
1. vector();

DONE
2. explicit vector( const Allocator& alloc );

DONE
3. explicit vector( size_type count,
                 const T& value = T(),
                 const Allocator& alloc = Allocator());

DONE
4. template< class InputIt >
	vector( InputIt first, InputIt last,
        const Allocator& alloc = Allocator() );

DONE
5. vector( const vector& other );

DONE
6. vector( const vector& other, const Allocator& alloc );

# Destructors

DONE
1. ~vector();

# Member types

* value_type	T DONE
* allocator_type	Allocator DONE
* size_type	Unsigned integer type (usually std::size_t) DONE
* difference_type	Signed integer type (usually std::ptrdiff_t) DONE
* reference	value_type& DONE
* const_reference	const value_type& DONE
* pointer  Allocator::pointer DONE
* const_pointer	 Allocator::const_pointer DONE
* iterator Vector iterator DONE
* const_iterator        Const Vector iterator
* reverse_iterator      Reverse Vector iterator
* const_reverse_iterator        Const Reverse Vector iterator

# Member functions

* operator= assigns values to the container DONE
* assign assigns values to the container // Here atm
* get_allocator returns the associated allocator

[...]
