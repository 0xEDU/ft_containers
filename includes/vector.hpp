#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "vector_iterator.hpp"
#include <string>
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
  typedef vector_iterator<T *> iterator;
  typedef vector_iterator<const T *> const_iterator;
  // reverse_iterator
  // const_reverse_iterator

public:
  vector() : _ptr(NULL), _allocator(), _size(0) {
    // this->ptr = this->allocator.allocate(this->vector_size);
  };
  ~vector() { /* this->allocator.deallocate(this->ptr, this->vector_size); */ };

  size_t size() {
    return this->_size;
  }

  bool empty() {
    return this->_size == 0;
  }

  // iterator begin() {
  //   return typename ft::vector<T>::iterator(_ptr);
  // };

private:
  pointer _ptr;
  allocator_type _allocator;
  size_t _size;
};

} // namespace ft

#endif
