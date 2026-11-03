#ifndef SINGLELIST_HPP
#define SINGLELIST_HPP

#include <iostream>
#include <cassert>

template <typename T>
struct SingleNode {
    T value;
    SingleNode *next;
    SingleNode() : value(T()), next(nullptr) {}
    SingleNode(const T& item, SingleNode *ptr=nullptr) : value(item), next(ptr) {}
    ~SingleNode() = default;
};

template <typename T>
class SingleList {
    SingleNode<T> *head, *tail;
public:
    SingleList() : head(nullptr), tail(nullptr) {}
    ~SingleList();
    SingleList(const SingleList& other);
    SingleList& operator=(const SingleList& other);
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
};

template <typename T>
SingleList<T>::~SingleList() {
    for (SingleNode<T> *node; !empty(); ) {
        node = head->next;
        delete head;
        head = node;
    }
}

template <typename T>
SingleList<T>::SingleList(const SingleList& other) : head(nullptr), tail(nullptr) {
    for (SingleNode<T> *node = other.head; node != nullptr; node = node->next) {
        push_back(node->value);
    }
}

template <typename T>
SingleList<T>& SingleList<T>::operator=(const SingleList& other) {
    if (this == &other) {
        return *this;
    }
    clear();
    for (SingleNode<T> *node = other.head; node != nullptr; node = node->next) {
        push_back(node->value);
    }
    return *this;
}

template <typename T>
std::size_t SingleList<T>::size() const {
    std::size_t counter = 0;
    for (SingleNode<T> *node = head; node != nullptr; node = node->next) {
        ++counter;
    }
    return counter;
}

template <typename T>
void SingleList<T>::push_front(const T& item) {
    if (!empty()) {
        head = new SingleNode<T>(item, head);
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::push_back(const T& item) {
    if (!empty()) {
        tail->next = new SingleNode<T>(item);
        tail = tail->next;
    } else {
        head = tail = new SingleNode<T>(item);
    }
}

template <typename T>
void SingleList<T>::display() const {
    SingleNode<T> *node = head;
    while (node != nullptr){
        std::cout << node->value << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SingleList<T>::pop_front() {
    assert(!empty());
    SingleNode<T> *node = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
    }
    delete node;
}

template <typename T>
void SingleList<T>::pop_back() {
    assert(!empty());
    SingleNode<T> *node = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        SingleNode<T> *before=head;
        while (before->next != tail) {
            before = before->next;
        }
        tail = before;
        tail->next = nullptr;
    }
    delete node;
}

template <typename T>
void SingleList<T>::clear() {
    while (!empty()) {
        pop_front();
    }
}

#endif
