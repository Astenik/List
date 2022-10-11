template <typename T>
class List 
{
public:
    List() {}
    virtual ~List();
    
    virtual void insert(int, const T&) = 0;
    virtual void erase(int) = 0;
    virtual void clear() = 0;
    
    virtual bool empty() const = 0;
    virtual int size() const = 0;
    virtual int find(const T&, int = -1) const = 0;
    virtual int rfind(const T&, int = -1) const = 0;
    virtual get_elem(int) const = 0;
};

template <typename T>
List<T>::~List()
{
    std::cout << "List destructor" << std::endl;
}
