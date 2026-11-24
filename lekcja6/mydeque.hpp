#ifndef MYDEQUE_HPP
#define MYDEQUE_HPP

#include <iostream>
#include <cassert>

template <typename T>
class MyDeque {
    T* tab;
    std::size_t msize;
    std::size_t head;
    std::size_t tail;
public:
    MyDeque(std::size_t s=10) : msize(s+1), head(0), tail(0) {
        tab = new T[s+1];
        assert( tab != nullptr );
    }
    ~MyDeque() { delete [] tab; }
    MyDeque(const MyDeque& other);
    MyDeque& operator=(const MyDeque& other);
    bool empty() const { return head == tail; }
    bool full() const { return (tail + 1) % msize == head; }
    std::size_t size() const { return (tail - head + msize) % msize; }
    std::size_t max_size() const { return msize-1; }
    void push_front(const T& item);
    void push_back(const T& item);
    T& front() { return tab[head]; }
    T& back() { return tab[(tail + msize -1) % msize]; }
    void pop_front();
    void pop_back();
    void clear();
    void display() const;
    void display_reversed() const;
};

template <typename T>
MyDeque<T>::MyDeque(const MyDeque& other) : msize(other.msize), head(other.head), tail(other.tail) {
    tab = new T[msize];
    assert( tab != nullptr );
    for (std::size_t i = head; i != tail; i=(i+1) % msize) {
        tab[i] = other.tab[i];
    }
}

template <typename T>
MyDeque<T>& MyDeque<T>::operator=(const MyDeque& other) {
    if (this == &other) {
        return *this;
    }
    if (msize != other.msize) {
        delete [] tab;
        msize = other.msize;
        tab = new T[msize];
        assert( tab != nullptr );
    }
    head = other.head;
    tail = other.tail;
    for (std::size_t i = head; i != tail; i=(i+1) % msize) {
        tab[i] = other.tab[i];
    }
    return *this;
}

template <typename T>
void MyDeque<T>::push_front(const T& item) {
    assert(!full());
    head = (head + msize -1) % msize;
    tab[head] = item;
}

template <typename T>
void MyDeque<T>::push_back(const T& item) {
    assert(!full());
    tab[tail] = item;
    tail = (tail + 1) % msize;
}

template <typename T>
void MyDeque<T>::pop_front() {
    assert(!empty());
    head = (head + 1) % msize;
}

template <typename T>
void MyDeque<T>::pop_back() {
    assert(!empty());
    tail = (tail + msize -1) % msize;
}

template <typename T>
void MyDeque<T>::clear() {
    head = tail = 0;
}

template <typename T>
void MyDeque<T>::display() const {
    for (std::size_t i = head; i != tail; i=(i+1) % msize) {
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void MyDeque<T>::display_reversed() const {
    for (std::size_t i = tail; i != head; ) {
        i = (i + msize -1) % msize;
        std::cout << tab[i] << " ";
    }
    std::cout << std::endl;
}

#endif
