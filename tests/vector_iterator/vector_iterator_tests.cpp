#include "iterator.hpp"
#include "vector_iterator.hpp"
#include "test_utils.hpp"
#include <cstddef>

TEST_F(equivalence) {
    // given:
    ft::vector_iterator<int> it1;
    ft::vector_iterator<int> it2 = it1;

    // then :
    assert(it1 == it2, "Equivalence");
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
    assert(it1 != it2, "Difference");
}

TEST_F(dereference) {
    // given:
    int i[5] = {1, 2, 3, 4, 5};
    ft::vector_iterator<int> it(i[0]);

    // then:
    assert(*it == i[0], "Dereference ");
}

TEST_F(increments) {
    // given:
    int i[5] = {1, 2, 3, 4, 5};
    ft::vector_iterator<int> it(i[0]);

    // then:
    ++it;
    assert(*it == i[1], "Prefix increment");
    it++;
    assert(*it == i[2], "Postfix increment");
}

TEST_F(dereferenceAndIncrement) {
    // given:
    int i[5] = {1, 2, 3, 4, 5};
    ft::vector_iterator<int> it(i[0]);

    // then:
    assert(*it++ == i[0], "Dereference and postfix increment");
    assert(*it == i[1], "Iterator incremented after dereference and postfix");
}

// memberAccess test type
typedef struct data {
    int x;
} data_t;

TEST_F(memberAccess) {
    // given:
    data d[3] = {{.x = 1}, {.x = 2}, {.x = 3}};
    ft::vector_iterator<data_t> it(d[0]);

    // then:
    assert(it->x == d[0].x, "Member access");
    ++it;
    assert(it->x == d[1].x, "Member access after prefix increment");
    it++;
    assert(it->x == d[2].x, "Member access after postfix increment");
}

TEST_F(assignment) {
    // given:
    int i[5] = {1, 2, 3, 4, 5};
    ft::vector_iterator<int> it(i[0]);

    // then:
    *it = 10;
    assert(*it++ == 10, "Assign a value to a iterator with deref and increment");
    *it = 20;
    assert(*it == 20, "Assign a value to a iterator");
    assert((i[0] == 10 && i[1] == 20), "Iterator altered the referenced object");
}

TEST_F(decrements) {
    // given:
    int i[5] = {1, 2, 3, 4, 5};
    ft::vector_iterator<int> it(i[4]);

    // then:
    --it;
    assert(*it == i[3], "Prefix decrement");
    it--;
    assert(*it == i[2], "Postfix decrement");
}

TEST_F(dereferenceAndDecrement) {
    // given:
    int i[5] = {1, 2, 3, 4, 5};
    ft::vector_iterator<int> it(i[4]);

    // then:
    assert(*it-- == i[4], "Dereference and postfix increment");
    assert(*it == i[3], "Iterator incremented after dereference and postfix");
}

TEST_F(incrementMultiplePositions) {
    // given:
    int i[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ft::vector_iterator<int> it(i[0]);

    // then:
    ft::vector_iterator<int> itNew = 1 + it;
    itNew = it + 2;
    assert(*itNew == i[2], "Sum an integer to iterator");
    it += 1;
    assert(*it == i[1], "Increment n positions");
}

TEST_F(decrementMultiplePositions) {
    // given:
    int i[5] = {1, 2, 3, 4, 5};
    ft::vector_iterator<int> it(i[4]);

    // then:
    it -= 2;
    assert(*it == i[2], "Decrement n positions");
    it = it - 2;
    assert(*it == i[0], "Subtract an integer from iterator");
}

TEST_F(randomPositionAccess) {
    // given:
    int i[5] = {10, 21, 32, 43, 54};
    ft::vector_iterator<int> it(i[0]);

    // then:
    int j = it[3];
    assert(i[3] == j, "Access a random position using []");
}

TEST_F(iteratorSubtraction) {
    // given:
    int i[5] = {10, 21, 32, 43, 54};
    ft::vector_iterator<int> it1(i[0]);
    ft::vector_iterator<int> it2(i[3]);
    ft::vector_iterator<int>::difference_type d = it2 - it1;

    // then:
    assert(d, 3, "Difference between iterators");
}

// TEST_F(greaterThan) {
//     // given:
//     int i[5] = {10, 21, 32, 43, 54};
//     ft::vector_iterator<int> it1(i[0]);
//     ft::vector_iterator<int> it2(i[3]);
//
//     // then:
//     assert(it1 < it2, "it1 greater than it2");
// }

TEST_SUITE {
    RUN_TEST(equivalence);
    RUN_TEST(difference);
    RUN_TEST(dereference);
    RUN_TEST(increments);
    RUN_TEST(dereferenceAndIncrement);
    RUN_TEST(memberAccess);
    RUN_TEST(assignment);
    RUN_TEST(decrements);
    RUN_TEST(dereferenceAndDecrement);
    RUN_TEST(incrementMultiplePositions);
    RUN_TEST(decrementMultiplePositions);
    RUN_TEST(randomPositionAccess);
    RUN_TEST(iteratorSubtraction);
    // RUN_TEST(greaterThan);
}
