# Constructors

1. vector();

2. explicit vector( const Allocator& alloc );

3. explicit vector( size_type count,
                 const T& value = T(),
                 const Allocator& alloc = Allocator());
                 
4. template< class InputIt >
	vector( InputIt first, InputIt last,
        const Allocator& alloc = Allocator() );
        
5. vector( const vector& other );

6. vector( const vector& other, const Allocator& alloc );

# Destructors

1. ~vector();

# Member types

value_type	T
allocator_type	Allocator
size_type	Unsigned integer type (usually std::size_t)
difference_type	Signed integer type (usually std::ptrdiff_t)
reference	value_type&
const_reference	const value_type&
pointer	 Allocator::pointer
const_pointer	 Allocator::const_pointer

[...]
