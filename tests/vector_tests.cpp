#include "vector.hpp"
#include "test_utils.hpp"
#include <cstddef>

// TEST_F(vectorBegin) {
//   ft::vector<int> v;
//   ft::vector<int>::iterator it = v.begin();
//
// }

TEST_F(vectorInstantiation) {
  ft::vector<int> v;

  assert(v.empty() == true, "Vector is empty");
  assert(v.size() == 0, "Vector has no size");
}

TEST_F(vectorInstantiationWithSize) {
  ft::vector<int> v1(5);

  assert(v1.empty() == true, "Vector is empty");
  assert(v1.size() == 5, "Vector has size 5");

  ft::vector<int> v2(10);

  assert(v2.empty() == true, "Vector is empty");
  assert(v2.size() == 10, "Vector has size 10");
}

TEST_F(vectorInstantiationWithCustomAllocator) {
  std::allocator<int> alloc;
  ft::vector<int> v(alloc);

  assert(v.empty() == true, "Vector is empty");
  assert(v.size() == 0, "Vector has no size");
}

TEST_SUITE {
  RUN_TEST(vectorInstantiation);
  RUN_TEST(vectorInstantiationWithSize);
  RUN_TEST(vectorInstantiationWithCustomAllocator);
  // RUN_TEST(vectorBegin);
}
