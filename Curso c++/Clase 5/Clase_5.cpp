#include <iostream>

struct string
{
    char* ptr;
    unsigned size;
    unsigned length;

    string()
    {
        ptr = new char[128];
        size = 128;
        length = 0;
        ptr[0] = 0;
    }

    string(const char* new_value)
    {
        ptr = nullptr;
        assign(new_value);
    }

    string(const string &new_value)
    {
        ptr = nullptr;
        assign(new_value);
    }

    ~string()
    {
        delete[] ptr;
    }

    void assign(const string &new_value)
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

    void assign(const char* what)
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

    void append(const string &new_value)
    {
        if (length + new_value.length >= size)
        {
            size = length + new_value.length + 1;
            char* aux_ptr = new char[size];
            for(unsigned i = 0; i < size; i++)
                ptr[i] = aux_ptr[i];
            delete[] ptr;
            ptr = aux_ptr;
        }

        for (unsigned i = 0; i < new_value.length; i++)
            ptr[length++] = new_value.ptr[i];
        ptr[length] = 0;

    }

    void append(const char* what)
    {
        unsigned new_length = 0;
        while(what[new_length])
            new_length++;

        if (length + new_length >= size)
        {
            size = length + new_length + 1;
            char* aux_ptr = new char[size];
            for(unsigned i = 0; i < size; i++)
                ptr[i] = aux_ptr[i];
            delete[] ptr;
            ptr = aux_ptr;
        }
        for (unsigned i = 0; i < new_length; i++)
            ptr[length++] = what[i];
        ptr[length] = 0;
    }

    bool is_equal(const char* s)
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

    bool is_equal(const string &s)
    {
        if (length != s.length)
            return false;
        
        for (unsigned i = 0; i <= length; i++)
        {
            if (ptr[i] != s.ptr[i]) return false;
        }
        return true;
    }

    bool contains(const char* s)
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

    void invert_case()
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
};



int main()
{
    string s("Buenos - Dias");

    std::cout << s.ptr << std:: endl;

    s.invert_case();

    std::cout << s.ptr << std:: endl;

}