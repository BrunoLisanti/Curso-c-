#include <iostream>
#include <bitset>
#include <string>
#include "Clase_10.h"

int main()
{
    unsigned char c = (char)'Á';

    std::cout << (int)c << std::endl;

    diacritic_tolower(c);

    std::cout << (int)c << std::endl;
}