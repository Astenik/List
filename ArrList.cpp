#pragma once;

#include "List.h"

template <typename T>
class ArrList: public List<T>
{
public:
    ArrList();
    ArrList(const ArrList<T>&);
    ArrList(const ArrList<T>&&);
    virtual ~ArrList();
    
public:
    virtual void insert(const T&, int);
    virtual void erase(int);
    virtual void clear();
    
    virtual bool empty() const;
    virtual int size() const;
    virtual int find(const T&, int) const;
    virtual int rfind(const T&, int) const;
    virtual  T get_elem(int) const;
    virtual bool full() const;
    
private:
    int m_size;
    int m_capacity;
    T* m_arr;
};

template <typename T>
ArrList<T>::ArrList()
    : m_size(0)
    , m_capacity(1)
    , m_arr(nullptr)
{}

template <typename T>
ArrList<T>::ArrList(const ArrList<T>& obj)
    : m_size(obj.m_size)
    , m_capacity(obj.m_capacity)
    , m_arr(new T [m_capacity])
{
    for(int i = 0; i < m_size; ++i)
    {
        m_arr[i] = obj.m_arr[i];
    }
}

template <typename T>
ArrList<T>::ArrList(const ArrList<T>&& obj)
    : m_size(obj.m_size)
    , m_capacity(obj.m_capacity)
    , m_arr(obj.m_arr)
{
    obj.m_arr = nullptr;
    obj.m_size = 0;
    obj.m_capacity = 0;
}

template <typename T>
ArrList<T>::~ArrList()
{
    clear();
    std::cout << "ArrList destructor" << std::endl;
}

template <typename T>
void ArrList<T>::insert(const T& item, int i)
{
    int k;
    if(i == -1)
    {
        k = m_size;
    }
    else
    {
        k = i;
    }
    if(k >= 0 && k <= m_size)
    {
        T* ptr = m_arr;
        if(full())
        {
            m_capacity *= 2;
        }
        m_arr = new T [m_capacity];
        for(int i = 0; i < k; ++i)
        {
            m_arr[i] = ptr[i];
        }
        m_arr[k] = item;
        for(int j = k + 1; j < m_size; ++j)
        {   
            m_arr[j] = ptr[j - 1];
        }
        ++m_size;
        delete [] ptr;
        ptr = nullptr;
    }
    else 
    {
       throw "index out of range";
    }
}

template <typename T>
void ArrList<T>::erase(int i) 
{
    if(!empty())
    {
        T* ptr = &m_arr[i];
        for(int j = i; j <= m_size; ++j)
        {
            m_arr[j] = m_arr[j + 1];
        }
        delete ptr;
        ptr = nullptr;
        --m_size;
    }
    else
    {
        throw "your list is empty";
    }
}

template <typename T>
bool ArrList<T>::empty() const
{
    return size() == 0;
}

template <typename T>
void ArrList<T>::clear()
{
    delete [] m_arr;
    m_size = 0;
    m_capacity = 0;
}

template <typename T>
int ArrList<T>::size() const
{
    return m_size;
}

template <typename T>
int ArrList<T>::find(const T& elem, int ind) const
{
    if(ind == -1)
    {
        for(int i = 0; i < m_size; ++i)
        {
            if(m_arr[i] == elem)
            {
                return i;
            }
        }
    }
    else
    {
        int count = 0;
        for(int i = 0; i < m_size; ++i)
        {
            if(m_arr[i] == elem)
            {
                count++;
            }
            if(count == ind)
            {
                return i;
            }
        }
    }
    return -1;
}

template <typename T>
int ArrList<T>::rfind(const T& elem, int ind) const
{
    if(ind == -1)
    {
        for(int i = m_size - 1; i >= 0; --i)
        {
            if(m_arr[i] == elem)
            {
                return i;
            }
        }
    }
    else
    {
        int count = 0;
        for(int i = m_size - 1; i >= 0; --i)
        {
            if(m_arr[i] == elem)
            {
                count++;
            }
            if(count == ind)
            {
                return i;
            }
        }
    }
    return -1;
}

template <typename T>
T ArrList<T>::get_elem(int ind) const 
{
    if(ind >= 0 && ind < m_size)
    {
        return m_arr[ind];
    }
    else
    {
        throw "index out of range";
    }
}

template <typename T>
bool ArrList<T>:: full() const
{
    return m_size == m_capacity;
}
