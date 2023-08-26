#include "iterator.hpp"
#include "vector_iterator.hpp"
#include "test_utils.hpp"

TEST_F(equivalence) {
    // given:
    ft::vector_iterator<int> it1;
    ft::vector_iterator<int> it2 = it1;

    // then :
    assert(it1 == it2, "Equivalence comparison");
}

TEST_F(difference) {
    // given:
    int i[5] = {1, 1, 1, 1, 1};
    int a[5] = {2, 2, 2, 2, 2};
    int *p1 = i;
    int *p2 = a;

    // when:
    ft::vector_iterator<int *> it1(p1);
    ft::vector_iterator<int *> it2(p2);

    // then:
    assert(it1 != it2, "Difference comparison");
}

TEST_F(dereference) {
    // given:
    int i[5] = {1, 2, 3, 4, 5};
    ft::vector_iterator<int> it(i[0]);

    // then:
    assert(*it == i[0], "Dereference comparison");
}

TEST_F(increments) {
    // given:
    int i[5] = {1, 2, 3, 4, 5};
    ft::vector_iterator<int> it(i[0]);

    // then:
    ++it;
    assert(*it == i[1], "Dereference comparison (prefix)");
    it++;
    assert(*it == i[2], "Dereference comparison (postfix)");
}

TEST_SUITE {
    RUN_TEST(equivalence);
    RUN_TEST(difference);
    RUN_TEST(dereference);
    RUN_TEST(increments);
}
