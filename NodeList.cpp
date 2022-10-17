template <typename T>
class NodeList: public List
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
    virtual int rfind(const T&, int) const;
    virtual bool full() const;
    T get_elem(int) const;
    
private:
    int m_size;
    Node<T>* m_head;
};

template <typename T>
NodeList<T>::NodeList()
    : m_size(0)
    , m_head(nullptr)
{}
