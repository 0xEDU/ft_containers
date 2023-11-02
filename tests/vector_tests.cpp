#include "vector.hpp"
#include "test_utils.hpp"
#include <cstddef>

TEST_F(vectorInstantiation) {
  ft::vector<int> v;
}

TEST_SUITE {
    RUN_TEST(vectorInstantiation);
}
