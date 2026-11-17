#ifndef DOUBLELIST_HPP
#define DOUBLELIST_HPP

#include <iostream>
#include <cassert>

template <typename T>
struct DoubleNode {
    T value;
    DoubleNode *next, *prev;
    DoubleNode() : value(T()), next(nullptr), prev(nullptr) {}
    DoubleNode(const T& item, DoubleNode *nptr=nullptr, DoubleNode *pptr=nullptr)
        : value(item), next(nptr), prev(pptr) {}
    ~DoubleNode() = default;
};

template <typename T>
class DoubleList {
    DoubleNode<T> *head, *tail;
public:
    DoubleList() : head(nullptr), tail(nullptr) {}
    ~DoubleList() { clear(); }
    DoubleList(const DoubleList& other);
    DoubleList& operator=(const DoubleList& other);
    bool empty() const { return head == nullptr; }
    bool full() const { return false; }
    std::size_t size() const;
    void push_front(const T& item);
    void push_back(const T& item);
    T& front() { assert(!empty()); return head->value; }
    T& back() { assert(!empty()); return tail->value; }
    void pop_front();
    void pop_back();
    void clear();
    void display() const;
    void display_reversed() const;
};

template <typename T>
DoubleList<T>::DoubleList(const DoubleList& other) : head(nullptr), tail(nullptr) {
    for (DoubleNode<T> *node = other.head; node != nullptr; node = node->next) {
        push_back(node->value);
    }
}

template <typename T>
DoubleList<T>& DoubleList<T>::operator=(const DoubleList& other) {
    if (this == &other) {
        return *this;
    }
    clear();
    for (DoubleNode<T> *node = other.head; node != nullptr; node = node->next) {
        push_back(node->value);
    }
    return *this;
}

template <typename T>
std::size_t DoubleList<T>::size() const {
    std::size_t counter = 0;
    for (DoubleNode<T> *node = head; node != nullptr; node = node->next) {
        ++counter;
    }
    return counter;
}

template <typename T>
void DoubleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new DoubleNode<T>(item, head);
        head->next->prev = head;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail = new DoubleNode<T>(item, nullptr, tail);
        tail->prev->next = tail;
    } else {
        head = tail = new DoubleNode<T>(item);
    }
}

template <typename T>
void DoubleList<T>::pop_front() {
    assert(!empty());
    DoubleNode<T> *node = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete node;
}

template <typename T>
void DoubleList<T>::pop_back() {
    assert(!empty());
    DoubleNode<T> *node = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete node;
}

template <typename T>
void DoubleList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

template <typename T>
void DoubleList<T>::display() const {
    DoubleNode<T> *node = head;
    while (node != nullptr) {
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void DoubleList<T>::display_reversed() const {
    DoubleNode<T> *node = tail;
    while (node != nullptr) {
        std::cout << node->value << " ";
        node = node->prev;
    }
    std::cout << std::endl;
}

#endif
