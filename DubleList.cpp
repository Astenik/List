//DubleList.h

#include "List.h"
#include "DubleNode.h"

template <typename T>
class DoubleList: public List<T>
{
public:
    DoubleList();
    DoubleList(const DoubleList<T>&);
    DoubleList(const DoubleList<T>&&);
    ~DoubleList();
    
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
    DubleNode<T>* move_to_pos(int);
    
private:
    DubleNode<T>* m_head;
    int m_size;
};

template <typename T>
DoubleList<T>::DoubleList() 
    : m_head(nullptr)
    , m_size(0)
{}

template <typename T>
DoubleList<T>::DoubleList(const DoubleList<T>& obj)
    : m_size(0)
{
    DubleNode<T>* ptr = obj.m_head;
    while(ptr)
    {
        insert(ptr->value, m_size);
    }
}

template <typename T>
DoubleList<T>::DoubleList(const DoubleList<T>&& tmp)
    : m_head(tmp.m_head)
    , m_size(tmp.m_size)
{
    tmp.m_size = 0;
    tmp.m_head = nullptr;
}

template <typename T>
DoubleList<T>::~DoubleList()
{
    clear();
    std::cout << "DoubleList destructor" << std::endl;
}

template <typename T>
void DoubleList<T>::insert(const T& item, int ind)
{
    if(ind < 0 || ind > m_size)
    {
        throw "index out of range";
    }
    if(ind == 0)
    {
        m_head = new DubleNode<T>(item, nullptr, m_head);
    }
    else
    {
        DubleNode<T>* ptr = move_to_pos(ind - 1);
        DubleNode<T>* tmp = new DubleNode<T>(item, ptr, ptr->next);
        if(ptr->next)
        {
            ptr->next = ptr->next->prev = tmp;
        }
        else
        {
            ptr->next = tmp;
        }
    }
    ++m_size;
}

template <typename T>
void DoubleList<T>::erase(int ind) 
{
    if(!empty() && ind >= 0 && ind < m_size)
    {
        if(ind == 0)
        {
            if(m_head->next)
            {
                m_head = m_head->next;
                delete m_head->prev;
            }
            else
            {
                delete m_head;
                m_head = nullptr;
            }
        }
        else
        {
            DubleNode<T>* ptr = move_to_pos(ind);
            if(ptr->next)
            {
                ptr->prev->next = ptr->next;
                ptr->next->prev = ptr->prev;
                
            }
            else
            {
                ptr->prev->next = ptr->next;
            }
            delete ptr;
        }
    }
    else
    {
        throw "index out of range";
    }
    --m_size;
}

template <typename T>
void DoubleList<T>::clear()
{
    while(m_head)
    {
        erase(m_size - 1);
    }
}

template <typename T>
bool DoubleList<T>::empty() const
{
    return size() == 0;
}

template <typename T>
int DoubleList<T>::size() const 
{
    return m_size;
}

template <typename T>
int DoubleList<T>::find(const T& elem, int k) const 
{
    DubleNode<T>* ptr = m_head;
    int count = 1;
    for(int i = 0; i < m_size; ++i)
    {
        if(ptr->value == elem)
        {
            if(count == k)
            {
                return i;
            }
            ++count;
        }
        ptr = ptr->next;
    }
    if(count != 1)
    {
        std::cout << "there is only" << count << "elems that equal to that elem" << std::endl;
    }
    return -1;
}

template <typename T>
bool DoubleList<T>::full() const
{
    return false;
}

template <typename T>
T DoubleList<T>::get_elem(int ind) const 
{
    if(ind >= 0 && ind < m_size && !empty())
    {
        DubleNode<T>* ptr = m_head;
        for(int i = 0; i < ind; ++i)
        {
            ptr = ptr->next;
        }
        return ptr->value;
    }
    else 
    {
        throw "index out of range";
    }
}

template <typename T>
void DoubleList<T>::print() const
{
    DubleNode<T>* ptr = m_head;
    for(int i = 0; i < m_size; ++i)
    {
        std::cout << ptr->value << " ";
        ptr = ptr->next;
    }
    std::cout << std::endl;
}

template <typename T>
DubleNode<T>* DoubleList<T>::move_to_pos(int i)
{
    DubleNode<T>* ptr = m_head;
    for(int k = 0; k < i; ++k)
    {
        ptr = ptr->next;
    }
    return ptr;
}
