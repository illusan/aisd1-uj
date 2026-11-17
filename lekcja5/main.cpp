#include <cassert>
#include <iostream>
#include <string>
#include "doublelist.hpp"

void test_constructor() {
    DoubleList<int> L;
    assert(L.empty());
    assert(!L.full());
    assert(L.size() == 0);
}

void test_push_pop() {
    DoubleList<int> L;
    L.push_back(2);
    L.push_back(3);
    L.push_front(1);
    assert(L.size() == 3);
    assert(L.front() == 1);
    assert(L.back() == 3);

    L.push_back(4);
    L.push_front(0);
    assert(L.size() == 5);
    assert(!L.full());

    L.pop_front();
    assert(L.front() == 1);
    L.pop_back();
    assert(L.back() == 3);
    assert(L.size() == 3);

    L.pop_front();
    L.pop_front();
    assert(L.front() == 3);
    assert(L.back() == 3);
    L.pop_back();
    assert(L.empty());
    assert(L.size() == 0);

    L.push_front(9);
    assert(L.front() == 9);
    assert(L.back() == 9);
}

void test_pop_back_all() {
    DoubleList<int> L;
    for (int i = 0; i < 5; ++i) {
        L.push_back(i);
    }
    for (int i = 4; i >= 0; --i) {
        assert(L.back() == i);
        L.pop_back();
    }
    assert(L.empty());
    L.push_back(1);
    L.push_back(2);
    assert(L.front() == 1);
    assert(L.back() == 2);
}

void test_front_back_access() {
    DoubleList<int> L;
    L.push_back(1);
    L.push_back(2);
    L.front() = 10;
    L.back() = 20;
    assert(L.front() == 10);
    assert(L.back() == 20);
}

void test_clear() {
    DoubleList<int> L;
    L.push_back(1);
    L.push_back(2);
    L.clear();
    assert(L.empty());
    assert(L.size() == 0);
    L.push_back(7);
    assert(L.front() == 7);
    assert(L.back() == 7);
}

void test_copy() {
    DoubleList<int> L1;
    L1.push_back(1);
    L1.push_back(2);

    DoubleList<int> L2(L1);
    assert(L2.size() == 2);
    assert(L2.front() == 1);
    assert(L2.back() == 2);
    L2.front() = 5;
    assert(L1.front() == 1);

    DoubleList<int> L3;
    L3.push_back(8);
    L3.push_back(9);
    L3.push_back(10);
    L3 = L1;
    assert(L3.size() == 2);
    assert(L3.front() == 1);
    assert(L3.back() == 2);
    L3.pop_back();
    assert(L1.size() == 2);

    DoubleList<int> L4;
    L4 = L3;
    L4.push_back(3);
    assert(L4.size() == 2);
    assert(L3.size() == 1);
}

void test_strings() {
    DoubleList<std::string> L;
    L.push_back("ma");
    L.push_front("ala");
    L.push_back("kota");
    assert(L.front() == "ala");
    assert(L.back() == "kota");
    L.display();
    L.display_reversed();
}

int main() {
    test_constructor();
    test_push_pop();
    test_pop_back_all();
    test_front_back_access();
    test_clear();
    test_copy();
    test_strings();
    std::cout << "Wszystkie testy zakończone pomyślnie." << std::endl;
    return 0;
}
