#include <iostream>

#include "ArrList.h"

int main()
{
    ArrList<int> ob;
    ob.insert(34, -1);
    ob.insert(12, -1);
    ob.insert(90, -1);
    std::cout << ob.find(12, 1) << std::endl;
    for(int i = 0; i < ob.size(); ++i)
    {
        std::cout << ob.get_elem(i) << std::endl;
    }
    return 0;
    
}
