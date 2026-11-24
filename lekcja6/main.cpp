#include <cassert>
#include <iostream>
#include <string>
#include "mydeque.hpp"

void test_constructor() {
    MyDeque<int> Q;
    assert(Q.empty());
    assert(!Q.full());
    assert(Q.size() == 0);
    assert(Q.max_size() == 10);

    MyDeque<int> R(4);
    assert(R.empty());
    assert(R.max_size() == 4);
}

void test_push() {
    MyDeque<int> Q;
    for (auto item : {1, 3, 5}) {
        Q.push_front(item);
    }
    for (auto item : {2, 4, 6}) {
        Q.push_back(item);
    }
    assert(Q.front() == 5);
    assert(Q.back() == 6);
    assert(Q.size() == 6);
    Q.front() = 55;
    Q.back() = 66;
    assert(Q.front() == 55);
    assert(Q.back() == 66);
    Q.clear();
    assert(Q.empty());
}

void test_full() {
    MyDeque<int> Q(4);
    Q.push_back(11);
    Q.push_back(22);
    Q.push_front(33);
    assert(Q.size() == 3);
    assert(!Q.full());
    Q.push_front(44);
    assert(Q.full());
    assert(Q.size() == 4);
    assert(Q.front() == 44);
    assert(Q.back() == 22);
}

void test_pop() {
    MyDeque<int> Q(4);
    Q.push_back(11);
    Q.push_back(22);
    Q.push_front(33);
    Q.push_front(44);

    Q.pop_front();
    assert(Q.front() == 33);
    Q.pop_back();
    assert(Q.back() == 11);
    assert(Q.size() == 2);

    Q.pop_front();
    assert(Q.front() == 11);
    assert(Q.back() == 11);
    Q.pop_back();
    assert(Q.empty());
    assert(Q.size() == 0);

    Q.push_front(7);
    assert(Q.front() == 7);
    assert(Q.back() == 7);
}

void test_cyclic() {
    MyDeque<int> Q(3);
    for (int i = 0; i < 20; ++i) {
        Q.push_back(i);
        Q.push_back(i + 1);
        assert(Q.front() == i);
        assert(Q.back() == i + 1);
        Q.pop_front();
        Q.pop_front();
        assert(Q.empty());
    }
    for (int i = 0; i < 20; ++i) {
        Q.push_front(i);
        assert(Q.front() == i);
        assert(Q.back() == i);
        Q.pop_back();
        assert(Q.empty());
    }
}

void test_clear() {
    MyDeque<int> Q(4);
    Q.push_back(1);
    Q.push_front(2);
    Q.clear();
    assert(Q.empty());
    assert(Q.size() == 0);
    Q.push_back(7);
    assert(Q.front() == 7);
    assert(Q.back() == 7);
}

void test_copy() {
    MyDeque<int> Q1(4);
    Q1.push_back(1);
    Q1.push_back(2);
    Q1.push_front(0);

    MyDeque<int> Q2(Q1);
    assert(Q2.size() == 3);
    assert(Q2.max_size() == 4);
    assert(Q2.front() == 0);
    assert(Q2.back() == 2);
    Q2.front() = 5;
    assert(Q1.front() == 0);

    MyDeque<int> Q3(8);
    Q3.push_back(9);
    Q3 = Q1;
    assert(Q3.size() == 3);
    assert(Q3.max_size() == 4);
    assert(Q3.front() == 0);
    assert(Q3.back() == 2);
    Q3.pop_back();
    assert(Q1.size() == 3);

    MyDeque<int> Q4(4);
    Q4 = Q3;
    Q4.push_back(3);
    assert(Q4.size() == 3);
    assert(Q3.size() == 2);
}

void test_strings() {
    MyDeque<std::string> Q(3);
    Q.push_back("ma");
    Q.push_front("ala");
    Q.push_back("kota");
    assert(Q.full());
    assert(Q.front() == "ala");
    assert(Q.back() == "kota");
    Q.display();
    Q.display_reversed();
}

int main() {
    test_constructor();
    test_push();
    test_full();
    test_pop();
    test_cyclic();
    test_clear();
    test_copy();
    test_strings();
    std::cout << "Wszystkie testy zakończone pomyślnie." << std::endl;
    return 0;
}
