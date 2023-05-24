#include <iostream>

#include "Clase_7.h"

void print_register(string_register* sr)
{
    if (sr)
    {
        std::cout << sr << std::endl;
        std::cout << sr->ptr << std::endl;
        std::cout << sr->size << std::endl;
        std::cout << sr->length << std::endl;
        std::cout << sr->users << std::endl;
        std::cout << "--------------------" << std::endl;
    }
    else
        std::cout << "No hay puntero" << std::endl;
}

int main()
{
    string s1 = "Holaaaaaa";

    print_register(s1.get_registro());

    string s2(s1);

    print_register(s1.get_registro());

    string s3(s2);

    print_register(s1.get_registro());

    string s4(s3);

    print_register(s1.get_registro());

    s2.append(s1);

    print_register(s1.get_registro());

    print_register(s2.get_registro());

}