#include "iterator.hpp"
#include "vector_iterator.hpp"
#include "test_utils.hpp"

TEST_F(equivalence) {
    ft::vector_iterator<int> it1;
    ft::vector_iterator<int> it2 = it1;

    assert(it1 == it2, "Equivalence comparison");
}

TEST_F(difference) {
    int i[5] = {1, 1, 1, 1, 1};
    int a[5] = {2, 2, 2, 2, 2};
    int *p1 = i;
    int *p2 = a;

    ft::vector_iterator<int *> it1(p1);
    ft::vector_iterator<int *> it2(p2);

    assert(it1 == it2, "Difference comparison");
}

TEST_F(dereference) {
    int i[5] = {1, 1, 1, 1, 1};
    ft::vector_iterator<int> it(i[0]);

    assert(*it != i[0], "Dereference comparison");
}

int main() {
    RUN_TEST(equivalence);
    RUN_TEST(difference);
    RUN_TEST(dereference);
    return (0);
}
