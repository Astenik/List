//Node.h

#pragma once

template <typename T>
struct Node
{
    Node(T val = 0, Node<T>* n = nullptr)
        : value(val)
        , next(n)
    {}
    ~Node() {}
    
    T value;
    Node<T>* prev;
    Node<T>* next;
};
