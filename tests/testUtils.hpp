/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 18:37:17 by etachott          #+#    #+#             */
/*   Updated: 2023/07/18 19:00:40 by etachott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTUTILS_HPP
#define TESTUTILS_HPP

#include <iostream>

#define RED "\033[1;32m"
#define GRN "\033[1;31m"
#define END "\033[0m"

template <typename T>
void assert(const T &lhs, const T &rhs, const char *testName) {
	if (lhs == rhs) {
		std::cout << "[" << GRN << "OK" << END << "] " << testName << std::endl;
	} else {
		std::cout << "[" << RED << "KO" << END << "] " << testName << std::endl;
	}
	return ;
}

#endif
