#pragma once;
//List.h

template <typename T>
class List 
{
public:
    List() {}
    virtual ~List();
    
    virtual void insert(const T&, int) = 0;
    virtual void erase(int) = 0;
    virtual void clear() = 0;
    
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual int find(const T&, int) const = 0;
    virtual bool full() const = 0;
    virtual void print() const = 0;
    virtual T get_elem(int) const = 0;
};

template <typename T>
List<T>::~List()
{
    std::cout << "List destructor" << std::endl;
}
 
