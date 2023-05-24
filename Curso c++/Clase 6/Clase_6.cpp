#include <iostream>

#include "Clase_6.h"

string::string()
{
    ptr = new char[128];
    size = 128;
    length = 0;
    ptr[0] = 0;
}

string::string(const char* new_value)
{
    ptr = nullptr;
    set_string(new_value);
}

string::string(const string &new_value)
{
    ptr = nullptr;
    set_string(new_value);
}

string::string(char c, unsigned times)
{
    size = times + 1;
    ptr = new char[size];
    for (unsigned i = 0; i < times; i++)
        ptr[i] = c;
    length = times;
    ptr[size] = 0;
}

string::~string()
{
    delete[] ptr;
}

void 
string::set_string(const string &new_value)
{
    if (!ptr || new_value.length >= size)
    {
        delete[] ptr;
        size = new_value.length + 1;
        ptr = new char[size];
    }

    for (unsigned i = 0; i < new_value.length; i++)
    {
        ptr[i] = new_value.ptr[i];
    }

    ptr[new_value.length] = 0;
    length = new_value.length;
}

void 
string::set_string(const char* what)
{
    unsigned new_length = 0;
    while(what[new_length])
        new_length++;
    
    if (!ptr || new_length >= size)
    {
        delete[] ptr;
        size = new_length + 1;
        ptr = new char[size];
    }

    for (unsigned i = 0; i < new_length; i++)
    {
        ptr[i] = what[i];
    }

    ptr[new_length] = 0;
    length = new_length;
}

void 
string::append(const string &new_value)
{
    if (length + new_value.length >= size)
    {
        size = length + new_value.length + 1;
        char* aux_ptr = new char[size];
        for(unsigned i = 0; i < size; i++)
            aux_ptr[i] = ptr[i];
        delete[] ptr;
        ptr = aux_ptr;
    }

    for (unsigned i = 0; i < new_value.length; i++)
        ptr[length++] = new_value.ptr[i];
    ptr[length] = 0;

}

void 
string::append(const char* what)
{
    unsigned new_length = 0;
    while(what[new_length])
        new_length++;

    if (length + new_length >= size)
    {
        size = length + new_length + 1;
        char* aux_ptr = new char[size];
        for(unsigned i = 0; i < size; i++)
            aux_ptr[i] = ptr[i];
        delete[] ptr;
        ptr = aux_ptr;
    }
    for (unsigned i = 0; i < new_length; i++)
        ptr[length++] = what[i];
    ptr[length] = 0;
}

void 
string::append(const char what)
{
    if (length + 1 >= size)
    {
        size = length + 1;
        char* aux_ptr = new char[size];
        for(unsigned i = 0; i < size; i++)
            aux_ptr[i] = ptr[i];
        delete[] ptr;
        ptr = aux_ptr;
    }
    ptr[length++] = what;
    ptr[length] = 0;
}

void 
string::swap(string &s)
{
    string auxStr(*this);
    set_string(s);
    s.set_string(auxStr);
}

bool
string::is_equal(const char* s) const
{
    unsigned s_length = 0;
    while(s[s_length])
        s_length++;

    if (length != s_length)
        return false;

    for (unsigned i = 0; i <= length; i++)
    {
        if (ptr[i] != s[i]) return false;
    }
    return true;
}

bool
string::is_equal(const string &s) const
{
    if (length != s.length)
        return false;
    
    for (unsigned i = 0; i <= length; i++)
    {
        if (ptr[i] != s.ptr[i]) return false;
    }
    return true;
}

bool 
string::contains(const char* s) const
{
    unsigned s_length = 0;
    while(s[s_length])
        s_length++;

    if (s_length > length)
    {
        std::cout << "Es mas largo" << std::endl;
        return false;
    }
    
    for (unsigned i = 0; i < length; i++)
    {
        if(ptr[i] == s[0])
        {
            std::cout << "Encontro una coincidencia" << std::endl;
            bool contains = true;
            for (unsigned j = 0; j < s_length; j++)
            {
                std::cout << ptr[i + j] << std::endl;
                if(ptr[i + j] != s[j])
                {
                    contains = false;
                }
            }
            if(contains)
                return true;
        }
    }
    return false;
}

void 
string::invert_case()
{
    for (unsigned i = 0; i < length; i++)
    {
        if(ptr[i] >= 65 && ptr[i] <= 90) //Mayus
        {
            std::cout << ptr[i] << std::endl;
            ptr[i] += 32;
            continue;
        }

        if(ptr[i] >= 97 && ptr[i] <= 122) //Minus
        {
            std::cout << ptr[i] << std::endl;
            ptr[i] -= 32;
        }
    }

}

string &
string::operator=(const string &right)
{
    set_string (right);
    return *this;
}

string &
string::operator=(const char *right)
{
    set_string (right);
    return *this;
}

string &
string::operator+=(const char *s)
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

string &
string::operator+=(const char s)
{
    append(s);
    return *this;
}

bool 
string::operator==(const string &right) const
{
    return is_equal(right);
}
bool 
string::operator==(const char *right) const
{
    return is_equal(right);
}
bool 
string::operator!=(const string &right) const
{
    return !is_equal(right);
}
bool 
string::operator!=(const char *right) const
{
    return !is_equal(right);
}

string 
string::substring(unsigned from, unsigned length) const
{
    char* auxPtr = new char[length + 1]; 
    for (unsigned i = 0; i < length; i++)
        auxPtr[i] = ptr[i + from];

    string returnable(auxPtr);
    delete[] auxPtr;
    return returnable;
}

void 
print_screen(const string &s)
{
    std::cout << s.get_string() << std::endl;
}

void 
print_screen(const char *s)
{
    std::cout << s << std::endl;
}

string 
operator+(const string &left, const char *right)
{
    string aux_left(left);
    aux_left.append(right);
    return aux_left;
}

string 
operator+(const char *left, const string &right)
{
    string aux_left(left);
    aux_left.append(right);
    return aux_left;
}

string 
operator+(const string &left, const string &right)
{
    string aux_left(left);
    aux_left.append(right);
    return aux_left;
}
