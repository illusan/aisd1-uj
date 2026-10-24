#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
#include <cassert>

template <typename T>
class ArrayList {
    T* tab;
    std::size_t msize;
    std::size_t last;
public:
    ArrayList(std::size_t s=10) : msize(s), last(0) {
        assert( s > 0 );
        tab = new T[s];
        assert( tab != nullptr );
    }
    ~ArrayList() { delete [] tab; }

    ArrayList(const ArrayList& other) : msize(other.msize), last(other.last) {
        tab = new T[msize];
        assert( tab != nullptr );
        for (std::size_t i = 0; i < last; ++i) {
            tab[i] = other.tab[i];
        }
    }

    ArrayList& operator=(const ArrayList& other) {
        if (this == &other) {
            return *this;
        }
        if (msize != other.msize) {
            delete [] tab;
            msize = other.msize;
            tab = new T[msize];
            assert( tab != nullptr );
        }
        last = other.last;
        for (std::size_t i = 0; i < last; ++i) {
            tab[i] = other.tab[i];
        }
        return *this;
    }

    bool empty() const { return last == 0; }
    bool full() const { return last == msize; }
    std::size_t size() const { return last; }
    std::size_t max_size() const { return msize; }

    void push_front(const T& item) {
        assert( !full() );
        for (std::size_t i = last; i > 0; --i) {
            tab[i] = tab[i - 1];
        }
        tab[0] = item;
        ++last;
    }

    void push_back(const T& item) {
        assert( !full() );
        tab[last] = item;
        ++last;
    }

    T& front() {
        assert( !empty() );
        return tab[0];
    }

    T& back() {
        assert( !empty() );
        return tab[last - 1];
    }

    void pop_front() {
        assert( !empty() );
        for (std::size_t i = 1; i < last; ++i) {
            tab[i - 1] = tab[i];
        }
        --last;
    }

    void pop_back() {
        assert( !empty() );
        --last;
    }

    void clear() { last = 0; }

    void display() { std::cout << *this << std::endl; }

    friend std::ostream& operator<<(std::ostream& os, const ArrayList& L) {
        for (std::size_t i=0; i < L.last; ++i) {
            os << L.tab[i] << " ";
        }
        return os;
    }
};

#endif
