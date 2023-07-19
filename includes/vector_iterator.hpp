/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:16:39 by etachott          #+#    #+#             */
/*   Updated: 2023/07/19 15:21:36 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	vector_iterator(const value_type &value) : _v(value) {};
	vector_iterator(const vector_iterator &rhs) {
		if (this != &rhs)
			*this = rhs;
		return ;
	};
	vector_iterator &operator=(const vector_iterator &rhs) {
		if (this != &rhs)
			this->_v = rhs.base();
		return *this;
	};
	~vector_iterator() {};

	// Accessor
	const value_type &base(void) const { return this->_v; };

// Interal variable(s)
private:
	value_type	_v;
};

// Overloads
template <typename T>
bool operator==(const vector_iterator<T> &lhs, const vector_iterator<T> &rhs) {
	return lhs.base() == rhs.base();
}

}

#endif // !VECTOR_ITERATOR_HPP
