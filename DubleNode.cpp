//DubleNode.h

#pragma once

template <typename T>
struct DubleNode
{
  DubleNode(T val, DubleNode<T>* p, DubleNode<T>* n)
    : value(val)
    , prev(p)
    , next(n)
    {}
  ~DubleNode() {}
  
  T value;
  DubleNode<T>* prev;
  DubleNode<T>* next;
};
