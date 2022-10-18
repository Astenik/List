#pragma once

#include "List.h"
#include "Node.h"

template <typename T>
class NodeList: public List<T>
{
public:
    NodeList();
    NodeList(const NodeList<T>&);
    NodeList(const NodeList<T>&&);
    virtual ~NodeList();
    
public:
    virtual void insert(const T&, int);
    virtual void erase(int);
    virtual void clear();
    
    virtual bool empty() const;
    virtual int size() const;
    virtual int find(const T&, int) const;
    virtual bool full() const;
    virtual T get_elem(int) const;
    virtual void print() const;
    
private:
    Node<T>* move_to_pos(int) const;
    
private:
    int m_size;
    Node<T>* m_head;
};

template <typename T>
NodeList<T>::NodeList()
    : m_size(0)
    , m_head(nullptr)
{}

template <typename T>
NodeList<T>::NodeList(const NodeList<T>& obj)
{
    Node<T>* ptr = obj.m_head;
 
    int i = 0;
    while(ptr)
    {
        insert(ptr->value, i);
        ptr = ptr->next;
        ++i;
    }
}

template <typename T>
NodeList<T>::NodeList(const NodeList<T>&& obj)
{
    m_size = obj.m_size;
    m_head = obj.m_head;
    obj.m_size = 0;
    obj.m_head = nullptr;
}

template <typename T>
NodeList<T>::~NodeList()
{
    clear();
    std::cout << "NodeList destructor" << std::endl;
}

template <typename T>
void NodeList<T>::insert(const T& item, int i)
{
    if(i >= 0 && i <= m_size)
    {
        if(i == 0)
        {
            m_head = new Node<T>(item, m_head);
        }
        else
        {
            Node<T>* ptr = move_to_pos(i - 1);
            ptr->next =  new Node<T>(item, ptr->next);
        }
        ++m_size;
    }
    else
    {
        throw "index out of range";
    }
}

template <typename T>
void NodeList<T>::erase(int i)
{
    if(i >= 0 && i < m_size && !empty())
    {
        if(i == 0)
        {
            Node<T>* ptr = m_head;
            m_head = m_head->next;
            delete ptr;
            ptr = nullptr;
        }
        else
        {
            Node<T>* ptr = move_to_pos(i - 1);
            Node<T>* tmp = ptr->next;
            ptr->next = ptr->next->next;
            delete tmp;
            tmp = nullptr;
        }
        --m_size;
    }
    else
    {
        throw "index out of range";
    }
}

template <typename T>
void NodeList<T>::clear()
{
    while(m_head)
    {
        erase(0);
    }
}

template <typename T>
bool NodeList<T>::empty() const
{
    return m_head == nullptr;
}

template <typename T>
int NodeList<T>::size() const 
{
    return m_size;
}

template <typename T>
int NodeList<T>::find(const T& elem, int ind) const
{
    if(ind >= 0 && ind < m_size)
    {
        Node<T>* ptr = m_head;
        int count = 0;
        
        for(int i = 0; i < m_size; ++i)
        {
            if(ptr->value == elem)
            {
                ++count;
                if(count == ind)
                {
                    return i;
                }
            }
            ptr = ptr -> next;
        }
        return -1;
    }
    else 
    {
        throw "index out of range";
    }
}

template <typename T>
bool NodeList<T>::full() const 
{
    return false;
}

template <typename T>
T NodeList<T>::get_elem(int i) const
{
    if(i >= 0 && i < m_size)
    {
        return move_to_pos(i)->value;
    }
    else
    {
        throw "index out of range";
    }
}

template <typename T>
void NodeList<T>::print() const
{
    Node<T>* ptr = m_head;
    for(int i = 0; i < m_size; ++i)
    {
        std::cout << ptr->value << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

template <typename T>
Node<T>* NodeList<T>:: move_to_pos(int ind) const
{
    Node<T>* ptr = m_head;
    for(int i = 0; i < ind; ++i)
    {
        ptr = ptr -> next;
    }
    return ptr;
}
