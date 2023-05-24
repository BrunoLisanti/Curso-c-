#include <iostream>
#include <vector>
#include <algorithm>


int main()
{
    unsigned next = 0;
    std:: vector<unsigned> v(10); //Vector de diez espacios
    
    std::generate(v.begin(), v.end(), [&next] { return next += 3; });
}