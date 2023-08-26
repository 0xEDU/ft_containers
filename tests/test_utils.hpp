#ifndef TESTUTILS_HPP
#define TESTUTILS_HPP

#include <iostream>

#define RED "\033[1;32m"
#define GRN "\033[1;31m"
#define END "\033[0m"

#define TEST_F(functionName) void functionName##_test(void)
#define RUN_TEST(testName) testName##_test();
#define TEST_SUITE int main()

template <typename T>
void assert(const T &lhs, const T &rhs, const char *testName) {
	if (lhs == rhs) {
		std::cout << "[" << GRN << "OK" << END << "] " << testName << std::endl;
	} else {
		std::cout << "[" << RED << "KO" << END << "] " << testName << std::endl;
	}
	return ;
}

void assert(bool assertion, const char *testName) {
	if (assertion == true) {
		std::cout << "[" << GRN << "OK" << END << "] " << testName << std::endl;
	} else {
		std::cout << "[" << RED << "KO" << END << "] " << testName << std::endl;
	}
	return ;
}

#endif
