/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 02:42:15 by edu               #+#    #+#             */
/*   Updated: 2023/07/17 00:16:26 by edu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <string>

namespace ft {

template <
	typename T,
	class Allocator = std::allocator<T>
>
class vector {
public:
	typedef T value_type;
	typedef Allocator allocator_type;
	typedef std::size_t size_type;
	typedef value_type& reference;
	typedef const value_type& const_reference;
	typedef typename Allocator::pointer pointer;
	typedef const typename Allocator::const_pointer const_pointer;
	// iterator
	// const_iterator
	// reverse_iterator
	// const_reverse_iterator

public:

	vector() {
		return ;
	};
	~vector() {
		return ;
	};
};

}

#endif
