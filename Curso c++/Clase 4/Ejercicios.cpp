#include <iostream>
// Escribir una versión alternativa de string_length()
int string_length(char* string)
{
    char* ptr = string;
    for(; *ptr++;);
    return ptr - string - 1;
}
// Escribir una versión alternativa de copy_string_with_size()
void copy_string_with_size(char* to&, unsigned from_size, const char* from)
{
    delete[] to;
    to = new char[from_size];
    for(unsigned i = 0; i < from_size; i++)
    {
        to[i] = from[i]; 
    }
}
// ¿Se podría modificar de alguna manera get_string() para que no vuelva
// a pedir memoria si con la memoria que tiene le alcanza para copiar el
// string que se le pide?
// Escribir una función para determinar si dos strings son iguales.
// ¿Qué hace el siguiente código?
    // const unsigned n = 26;
    // char s[n+1];
    // for (unsigned i = 0; i < n; i++)
    // s[i] = 'a' + i;
    // s[n] = 0;
// ¿Se podría reescribir el código sin usar el caracter literal 'a'?
// ¿Se podría reescribir el código sin usar la constante n?

int main()
{
    char string[5];

    copy_string_with_size(string, 11, "0123456789");

    std::cout << "El string es: " << string << std::endl; 

    return 0;    
}
