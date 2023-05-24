#include <iostream>

#include <vector>


void tabla_tres()
{
    std::vector<unsigned> v;
    
    for (unsigned i = 0; i < 10; i++)
    {
        v.push_back(i * 3);
        std::cout << v.capacity() << std::endl;
    }
    
    std::cout << "////////////////////////" << std::endl;
    
    for (auto i : v)
        std::cout << i << std::endl;
    
}

int main()
{
    tabla_tres();
    return 0;
}