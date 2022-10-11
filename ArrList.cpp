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
    virtual void insert(int, const T&);
    virtual void erase(int);
    virtual void clear();
    
    virtual bool empty() const;
    virtual int size() const;
    virtual int find(const T&, int = -1) const;
    virtual int rfind(const T&, int = -1) const;
    virtual get_elem(int) const;
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
    for(int i = 0; i < m_size: ++i)
    {
        m_arr[i] = obj.m_arr[i];
    }
}

template <typename T>
ArrList<T>::ArrList(const ArrList<T>&& tmp)
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
void ArrList<T>::insert(int i, const T& item)
{
    if(i >= 0 && i <= m_size && !full())
    {
        if(empty())
        {
            m_arr = new T [m_capacity];
            m_arr[0] = item;
        }
        else
        {
            for(int j = m_size + 1; j > i; --j)
            {
              m_arr[j] = m_arr[j - 1];
            }
            m_arr[i] = item;
        }
        ++m_size;
    }
    
    if(i >= 0 && i <= m_size && full())
    {
        T* ptr = m_arr;
        m_capacity *= 2;
        m_arr = new T [m_capacity];
        for(int j = 0; j < i; ++j)
        {
            m_arr[j] = ptr[j];
        }
        
        m_arr[i] = item;
        for(int j = i + 1; i <= m_size + 1; ++i)
        {
            m_arr[j] = ptr[j - 1];
        }
        ++m_size;
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
        T* ptr = &arr[i];
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
