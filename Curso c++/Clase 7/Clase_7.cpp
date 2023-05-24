#include <iostream>

#include "Clase_7.h"

unsigned
string::len(const char* s)
{
    unsigned i = 0;
    while(s[i])
        i++;
    return i;
}

string::string()
{
    registro = nullptr;
}

string::string(const char* s)
{
    set_string(s);
}

string::string(const string &s)
{
    set_string(s);
}

string::~string()
{
    std::cout << "Entra en el destructor" << std::endl;
    std::cout << --registro->users << std::endl;
    std::cout << "El problema no esta en disminuir los usuarios" << std::endl;
    if (registro->users <= 0)
    {
        delete[] registro->ptr;
        delete registro;
    }
}

void
string::set_string(const char* s)
{
    if (registro)
        if (--registro->users <= 0)
        {
            delete[] registro->ptr;
            delete registro;
        }

    string_register* register_Aux = new string_register;
    register_Aux->ptr = new char[len(s) + 1];
    register_Aux->length = len(s);
    register_Aux->size = len(s) + 1;
    register_Aux->users = 1;

    for(unsigned i = 0; i <= register_Aux->length; i++)
        register_Aux->ptr[i] = s[i];

    string_register* auxi = register_Aux;

    if (registro)
        registro->users--;

    this->registro = register_Aux;
}

void
string::set_string(const string &s)
{
    if (registro)
        if (--registro->users <= 0)
        {
            delete[] registro->ptr;
            delete registro;
        }

    this->registro = s.registro;

    this->registro->users++;
}

void
string::append(const char *s)
{

    string_register *new_string = new string_register;

    new_string->length = registro->length;
    new_string->size = registro->size;
    new_string->ptr = new char[registro->length + 1];

    if (--registro->users <= 0)
    {
        delete[] registro->ptr;
        delete registro;
    }

    for (unsigned i = 0; i < registro->length; i++)
        new_string->ptr[i] = registro->ptr[i];
    unsigned new_length = len(s);

    if(new_string->size <= new_length)
    {
        char* auxPtr = new char[new_string->size = new_string->length + new_length + 1];
        for(unsigned i = 0; i <= new_string->length; i++)
            auxPtr[i] = new_string->ptr[i];
        delete[] new_string->ptr; //Cuidar de usar el [] en delete.
        new_string->ptr = auxPtr;
    }
    std::cout << "Prueba 2: " << *registro->ptr << std:: endl;
    for(unsigned i = 0; i < new_length; i++)
        new_string->ptr[new_string->length++] = s[i];
    new_string->ptr[new_string->length] = 0;

    std::cout << "Prueba 3: " <<  *registro->ptr << std:: endl;
    new_string->users = 1;

    registro = new_string;
}

void
string::append(const string &s)
{

    string_register *new_string = new string_register;

    new_string->length = registro->length;
    new_string->size = registro->size;
    new_string->ptr = new char[registro->length + 1];

    for (unsigned i = 0; i < registro->length; i++)
        new_string->ptr[i] = registro->ptr[i];

    if (--registro->users <= 0)
    {
        delete[] registro->ptr;
        delete registro;
    }

    unsigned new_length = s.registro->length;

    std::cout << "Prueba 1: " <<  registro->ptr << std:: endl;
    std::cout << "Prueba 1: " <<  registro->length << std:: endl;

    if(new_string->size <= new_length)
    {
        char* auxPtr = new char[new_string->size = new_string->length + new_length + 1];
        for(unsigned i = 0; i <= new_string->length; i++)
            auxPtr[i] = new_string->ptr[i];
        delete new_string->ptr;
        new_string->ptr = auxPtr;
    }
    std::cout << "Prueba 2: " <<  registro->ptr << std:: endl;
    std::cout << "Prueba 2: " <<  registro->length << std:: endl;
    for(unsigned i = 0; i < new_length; i++)
        new_string->ptr[new_string->length++] = s.registro->ptr[i];
    new_string->ptr[new_string->length] = 0;

    std::cout << "Prueba 3: " <<  registro->ptr << std:: endl;
    std::cout << "Prueba 3: " <<  registro->length << std:: endl;

    new_string->users = 1;

    registro = new_string;
}

string &
string::operator=(const char* s)
{
    set_string(s);
    return(*this);
}

string &
string::operator=(const string &s)
{
    set_string(s);
    return(*this);
}

string
string::operator+(const char* s) const
{
    string left(*this);
    left.append(s);
    return left;
}

string
string::operator+(const string &s) const
{
    string left(*this);
    left.append(s);
    return left;
}

string &
string::operator+=(const char* s)
{
    append(s);
    return *this;
}

string &
string::operator+=(const string &s)
{
    append(s);
    return *this;
}