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
    ft::vector_iterator<int> it1;
    ft::vector_iterator<int> it2 = it1;

    assert(it1 == it2, "Equivalence comparison");
}

void test_difference() {
    int i[5] = {1, 1, 1, 1, 1};
    int a[5] = {2, 2, 2, 2, 2};
    int *p1 = i;
    int *p2 = a;

    ft::vector_iterator<int *> it1(p1);
    ft::vector_iterator<int *> it2(p2);

    assert(it1 == it2, "Difference comparison");
}

void test_dereference() {
    int i[5] = {1, 1, 1, 1, 1};
    ft::vector_iterator<int> it(i[0]);

    assert(*it != i[0], "Dereference comparison");
}

int main() {
    test_equivalence();
    test_difference();
    test_dereference();
	return (0);
}
