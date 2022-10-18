#include <iostream>

#include "NodeList.h"

int main()
{
    NodeList<int> obj;
    for(int i = 1; i < 6; ++i)
    {
        obj.insert(i, i - 1);
    }
    obj.print();
    
    obj.erase(1);
    obj.print();
    
    obj.erase(0);
    obj.print();
    
    obj.erase(2);
    obj.print();
    
    std::cout << obj.find(3, 1) << std::endl;
    std::cout << obj.get_elem(1) << std::endl;
    
    return 0;
}
