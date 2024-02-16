#include <deque>
#include <vector>
#include <iostream>
#define println(x) std::cout << x << std::endl;

int main() {
	std::deque<int> l(1, 32);
	std::vector<int> v(l.begin(), l.end());
	println(v[0])
	return 0;
}
