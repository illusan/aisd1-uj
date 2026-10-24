#include <cassert>
#include <iostream>
#include <string>
#include "arraylist.hpp"

void test_constructor() {
    ArrayList<int> L;
    assert(L.empty());
    assert(!L.full());
    assert(L.size() == 0);
    assert(L.max_size() == 10);

    ArrayList<int> M(3);
    assert(M.empty());
    assert(M.max_size() == 3);
}

void test_push_pop() {
    ArrayList<int> L(5);
    L.push_back(2);
    L.push_back(3);
    L.push_front(1);
    assert(L.size() == 3);
    assert(L.front() == 1);
    assert(L.back() == 3);

    L.push_back(4);
    L.push_front(0);
    assert(L.full());
    assert(L.size() == 5);

    L.pop_front();
    assert(L.front() == 1);
    L.pop_back();
    assert(L.back() == 3);
    assert(L.size() == 3);

    L.pop_front();
    L.pop_front();
    L.pop_back();
    assert(L.empty());
}

void test_front_back_access() {
    ArrayList<int> L(3);
    L.push_back(1);
    L.push_back(2);
    L.front() = 10;
    L.back() = 20;
    assert(L.front() == 10);
    assert(L.back() == 20);
}

void test_clear() {
    ArrayList<int> L(4);
    L.push_back(1);
    L.push_back(2);
    L.clear();
    assert(L.empty());
    assert(L.size() == 0);
    L.push_back(7);
    assert(L.front() == 7);
}

void test_copy() {
    ArrayList<int> L1(4);
    L1.push_back(1);
    L1.push_back(2);

    ArrayList<int> L2(L1);
    assert(L2.size() == 2);
    assert(L2.max_size() == 4);
    L2.front() = 5;
    assert(L1.front() == 1);

    ArrayList<int> L3(8);
    L3 = L1;
    assert(L3.size() == 2);
    assert(L3.max_size() == 4);
    assert(L3.back() == 2);
    L3.pop_back();
    assert(L1.size() == 2);
}

void test_strings() {
    ArrayList<std::string> L(3);
    L.push_back("ma");
    L.push_front("ala");
    L.push_back("kota");
    assert(L.front() == "ala");
    assert(L.back() == "kota");
    L.display();
}

int main() {
    test_constructor();
    test_push_pop();
    test_front_back_access();
    test_clear();
    test_copy();
    test_strings();
    std::cout << "Wszystkie testy zakończone pomyślnie." << std::endl;
    return 0;
}
