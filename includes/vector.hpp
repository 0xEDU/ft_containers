#ifndef VECTOR_HPP
#define VECTOR_HPP

#define DEBUG(x) std::cout << "[DEBUG] " << x << std::endl;

#include "vector_iterator.hpp"
#include <sys/types.h>

namespace ft {

template <typename T, class Allocator = std::allocator<T> > class vector {
public:
  typedef T value_type;
  typedef Allocator allocator_type;
  typedef std::size_t size_type;
  typedef value_type &reference;
  typedef const value_type &const_reference;
  typedef typename Allocator::pointer pointer;
  typedef const typename Allocator::const_pointer const_pointer;
  typedef vector_iterator<value_type> iterator;
  // typedef vector_iterator<const T *> const_iterator;
  // reverse_iterator
  // const_reverse_iterator

public:
  // Constructors
  vector() : _ptr(NULL), _allocator(), _size(0), _begin(NULL), _end(NULL){};

  explicit vector(size_type size, const_reference value = value_type(), const Allocator &alloc = Allocator())
      : _ptr(NULL), _allocator(alloc), _size(size), _begin(NULL), _end(NULL) {
    this->_ptr = this->_allocator.allocate(size);
    this->_begin = this->_ptr;
    this->_end = this->_ptr + size;
    while (this->_ptr != this->_end) {
      *this->_ptr = value;
      this->_ptr++;
    }
    this->_ptr = this->_begin;
  };

  explicit vector(const Allocator &alloc)
      : _ptr(NULL), _allocator(alloc), _size(0), _begin(NULL), _end(NULL) {}

  explicit vector(iterator first, iterator last, const Allocator &alloc = Allocator())
    : _ptr(NULL), _allocator(alloc), _size(last - first), _begin(NULL), _end(NULL) {
    this->_ptr = this->_allocator.allocate(this->_size);
    this->_begin = this->_ptr;
    this->_end = this->_ptr + this->_size;
    for (; first != last; first++) {
      *this->_ptr++ = *first;
    }
    this->_ptr = this->_begin;
  }

  // Destructors
  ~vector() {
    if (this->_ptr != NULL)
      this->_allocator.deallocate(this->_ptr, this->_size);
  };

  // Capacity
  size_t size() { return this->_size; }

  bool empty() { return this->_begin == this->_end; }

  // Iterators
  iterator begin() {
    return iterator(*this->_begin);
  };

  iterator end() {
    return iterator(*this->_end);
  };

private:
  pointer _ptr;
  allocator_type _allocator;
  size_type _size;
  pointer _begin;
  pointer _end;
};

} // namespace ft

#endif
