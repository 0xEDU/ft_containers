#include "vector.hpp"
#include "test_utils.hpp"
#include <cstddef>
#include <memory>
#define DEBUG(x) std::cout << "[DEBUG] " << x << std::endl;
// TEST_F(vectorBegin) {
//   ft::vector<int> v;
//   ft::vector<int>::iterator it = v.begin();
//
// }

TEST_F(vectorInstantiation) {
  // given
  ft::vector<int> v;

  // then
  assert(v.empty() == true, "Vector is empty");
  assert(v.size() == 0, "Vector has no size");
}

TEST_F(vectorInstantiationWithSize) {
  // given
  ft::vector<int> v1(5);
  ft::vector<int>::iterator it = v1.begin();

  // then
  assert(v1.empty() == false, "Vector is not empty");
  assert(v1.size() == 5, "Vector has size 5");
  assert(*it++ == 0, "Vector is filled with 0 at begin");
  assert(*it == 0, "Vector is filled with 0 at begin + 1");
}

TEST_F(vectorInstantiationWithCustomAllocator) {
  // given
  std::allocator<int> alloc;
  ft::vector<int> v(alloc);

  // then
  assert(v.empty() == true, "Vector is empty");
  assert(v.size() == 0, "Vector has no size");
}

TEST_F(vectorInstantiationWithSizeAndValue) {
  // given
  ft::vector<int> v(1, 42);
  ft::vector<int>::iterator it = v.begin();

  // then
  assert(v.empty() == false, "Vector is not empty");
  assert(v.size() == 1, "Vector has size 1");
  assert(*it == 42, "Vector is filled with the right value");
}

TEST_F(vectorInstantiationWithSizeAndValueAndCustomAllocator) {
  // given
  std::allocator<int> alloc;
  ft::vector<int> v(1, 42, alloc);
  ft::vector<int>::iterator it = v.begin();

  // then
  assert(v.empty() == false, "Vector is not empty");
  assert(v.size() == 1, "Vector has size 1");
  assert(*it == 42, "Vector is filled with the right value");
}

TEST_F(vectorInstantiationIterators) {
  // given
  ft::vector<int> v1(3, 42);
  ft::vector<int> v2(v1.begin(), v1.end());
  ft::vector<int>::iterator it = v2.begin();

  // then
  assert(v2.empty() == false, "Vector is not empty");
  assert(v2.size() == 3, "Vector has size 3");
  assert(*it++ == 42, "Vector is filled with 42 at 0");
  assert(*it++ == 42, "Vector is filled with 42 at 1");
  assert(*it == 42, "Vector is filled with 42 at 2");
}

TEST_F(vectorCopyConstructor) {
  // given
  ft::vector<int> v1(3, 42);
  ft::vector<int> v2(v1);
  ft::vector<int>::iterator it = v2.begin();

  // then
  assert(v2.empty() == false, "Vector is not empty");
  assert(v2.size() == 3, "Vector has size 3");
  assert(*it++ == 42, "Vector is filled with 42 at 0");
  assert(*it++ == 42, "Vector is filled with 42 at 1");
  assert(*it == 42, "Vector is filled with 42 at 2");
}

TEST_F(vectorAssignWithSizeAndValue) {
  // given
  ft::vector<char> v;
  v.assign(1, 'a');
  ft::vector<char>::iterator it = v.begin();

  // then
  assert(v.empty() == false, "Vector is not empty");
  assert(v.size() == 1, "Vector has size 1");
  assert(*it == 'a', "Vector is filled with the right value");

  // when
  v.assign(3, 'b');
  it = v.begin();

  // then
  assert(v.empty() == false, "Vector is not empty");
  assert(v.size() == 3, "Vector has size 1");
  assert(*it++ == 'b', "Vector is filled with the right value at 0");
  assert(*it++ == 'b', "Vector is filled with the right value at 1");
  assert(*it == 'b', "Vector is filled with the right value at 2");
}

TEST_SUITE {
  RUN_TEST(vectorInstantiation);
  RUN_TEST(vectorInstantiationWithSize);
  RUN_TEST(vectorInstantiationWithCustomAllocator);
  RUN_TEST(vectorInstantiationWithSizeAndValueAndCustomAllocator);
  RUN_TEST(vectorInstantiationIterators);
  RUN_TEST(vectorCopyConstructor);
  RUN_TEST(vectorAssignWithSizeAndValue);
}
