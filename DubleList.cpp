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
    if(ind == 0)
    {
        m_head = new DoubleList<T>(item, nullptr, m_head);
    }
    else
    {
        DubleNode<T>* ptr = move_to_pos(ind - 1);
        DubleNode<T>* tmp = new DubleNode<T>(item, ptr, ptr->next);
        ptr->next = ptr->next->prev = tmp;
        ptr = nullptr;
    }
    ++m_size;
}

template <typename T>
void DoubleList<T>::erase(int ind) 
{
    if(empty())
    {
        throw "your list is empty";
    }
    if(ind <= 0 || ind >= m_size)
    {
        throw "index out of range";
    }
    else if(ind == 0)
    {
        m_head = m_head->next;
        delete m_head-> prev;
        m_head->prev = nullptr;
    }
    else
    {
        DubleNode<T>* ptr = move_to_pos(ind - 1);
        DubleNode<T>* k = ptr->next->next;
        ptr->next = k;
        delete ptr->next;
        k->prev = ptr;
        ptr = nullptr;
        k = nullptr;
    }
    --m_size;
}

void DoubleList<T>::clear()
{
    while(m_head)
    {
        erase(m_size - 1);
    }
}

