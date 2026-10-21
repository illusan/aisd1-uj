#include <algorithm>
#include <cassert>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include "sortowanie.hpp"

void test_bubblesort() {
    int t[] = {5, 2, 8, 1, 9, 3, 7};
    bubblesort(t, t + 7);
    assert(std::is_sorted(t, t + 7));

    std::vector<int> empty;
    bubblesort(empty.begin(), empty.end());
    assert(empty.empty());

    std::vector<int> v = {4, 4, -1, 0, 4, -1};
    bubblesort(v.begin(), v.end());
    assert(std::is_sorted(v.begin(), v.end()));
    assert(v == std::vector<int>({-1, -1, 0, 4, 4, 4}));

    std::vector<std::string> words = {"kot", "ala", "pies", "ma"};
    bubblesort(words.begin(), words.end());
    assert(std::is_sorted(words.begin(), words.end()));

    std::vector<int> big;
    for (int i = 1000; i > 0; --i) {
        big.push_back(i);
    }
    bubblesort(big.begin(), big.end());
    assert(std::is_sorted(big.begin(), big.end()));
}

void test_mergesort() {
    int t[] = {5, 2, 8, 1, 9, 3, 7};
    mergesort(t, t + 7);
    assert(std::is_sorted(t, t + 7));

    std::vector<int> one = {42};
    mergesort(one.begin(), one.end());
    assert(one[0] == 42);

    std::vector<double> d = {2.5, -0.5, 1.0, 2.5, 0.0};
    mergesort(d.begin(), d.end());
    assert(std::is_sorted(d.begin(), d.end()));

    std::list<int> L = {3, 1, 2, 5, 4};
    mergesort(L.begin(), L.end());
    assert(std::is_sorted(L.begin(), L.end()));

    std::vector<int> big;
    for (int i = 0; i < 100000; ++i) {
        big.push_back((i * 7919) % 1000);
    }
    mergesort(big.begin(), big.end());
    assert(std::is_sorted(big.begin(), big.end()));
}

int main() {
    test_bubblesort();
    test_mergesort();
    std::cout << "Testy OK" << std::endl;
    return 0;
}
