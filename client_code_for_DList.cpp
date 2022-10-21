#include <iostream>

#include "DubleList.h"

int main()
{
    DoubleList<int> ob;
    for(int i = 1; i < 11; ++i)
    {
        ob.insert(i, i - 1);
    }
    ob.print();
    ob.erase(2);
    ob.erase(5);
    ob.erase(7);
    ob.print();
    
    std::cout << ob.find(5, 1) << std::endl;
    std::cout << ob.get_elem(3) << std::endl;
    
    return 0;
}
