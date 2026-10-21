#ifndef SORTOWANIE_HPP
#define SORTOWANIE_HPP

#include <algorithm>
#include <iterator>
#include <utility>

template<typename Iterator>
void bubblesort(Iterator first, Iterator last) {
    if (first == last) {
        return;
    }
    bool swapped = true;
    while (swapped) {
        swapped = false;
        Iterator current = first;
        Iterator next = std::next(first);
        while (next != last) {
            if (*next < *current) {
                std::swap(*current, *next);
                swapped = true;
            }
            ++current;
            ++next;
        }
    }
}

template<typename Iterator>
void mergesort(Iterator first, Iterator last) {
    typename std::iterator_traits<Iterator>::difference_type n =
        std::distance(first, last);
    if (n < 2) {
        return;
    }
    Iterator middle = first;
    std::advance(middle, n / 2);
    mergesort(first, middle);
    mergesort(middle, last);
    std::inplace_merge(first, middle, last);
}

#endif
