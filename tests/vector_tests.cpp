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
  assert(v.size() == 0, "Vector has no elements");
}

TEST_SUITE {
    RUN_TEST(vectorInstantiation);
    // RUN_TEST(vectorBegin);
}
