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

void test_equivalence() {
    ft::vector_iterator<int> i1;
    ft::vector_iterator<int> i2 = i1;

    assert(i1 == i2, "Equivalence comparison");
}

void test_difference() {
    int i[5] = {1, 1, 1, 1, 1};
    int a[5] = {2, 2, 2, 2, 2};
    int *p1 = i;
    int *p2 = a;

    ft::vector_iterator<int *> i1(p1);
    ft::vector_iterator<int *> i2(p2);

    assert(i1 != i2, "Difference comparison");
}

int main() {
    test_equivalence();
    test_difference();
	return (0);
}
