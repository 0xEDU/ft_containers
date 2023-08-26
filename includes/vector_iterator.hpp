#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP

#include <vector>
#include "iterator.hpp"

namespace ft {

template <typename T>
class vector_iterator : public ft::iterator<ft::random_access_iterator_tag, T> {
private: // Typedef used internally for abbreviation
	typedef typename ft::iterator<ft::random_access_iterator_tag, T> _iterator;

// Default typedef's
public:
	typedef typename _iterator::value_type			value_type;
	typedef typename _iterator::difference_type		difference_type;
	typedef typename _iterator::pointer				pointer;
	typedef typename _iterator::reference			reference;
	typedef typename _iterator::iterator_category	iterator_category;

// Canonical form
public:
	vector_iterator() : _v() {};
	explicit vector_iterator(value_type &value) : _v(value) {};
	vector_iterator(const vector_iterator &rhs) {
		if (this != &rhs)
			*this = rhs;
	};
	vector_iterator &operator=(const vector_iterator &rhs) {
		if (this != &rhs)
			this->_v = rhs.base();
		return *this;
	};
	~vector_iterator() {};

	// Accessor
	const value_type &base() const { return this->_v; };

    // Overloads
    bool operator==(const vector_iterator<T> &rhs) {
        return this->base() == rhs.base();
    }

    bool operator!=(const vector_iterator<T> &rhs) {
        return this->base() != rhs.base();
    }

    reference operator*() {
        return _v;
    }

// Internal variable(s)
private:
	value_type	_v;
};

}

#endif // !VECTOR_ITERATOR_HPP
