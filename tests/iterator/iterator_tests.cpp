/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorTests.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:32:37 by etachott          #+#    #+#             */
/*   Updated: 2023/07/19 15:24:07 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iterator.hpp"
#include "vector_iterator.hpp"
#include "test_utils.hpp"

int main(void) {
	ft::vector_iterator<int> i1;
	ft::vector_iterator<int> i2 = i1;
	ft::vector_iterator<int> i3(i2);

	assert(i1 == i2, "Equivalence comparison");
	return (0);
}
