#include <iostream>
#include <string>
#include <bitset>

#include "Clase_10.h"

//á == 160 
//é == 130
//í == 161
//ó == 162
//ú == 163

//Á == 181
//É == 144
//Í == 214
//Ó == 224
//Ú == 233

void diacritic_tolower(unsigned char &c)
{
    switch (c)
        {
            case 129: c = 'á'; std::cout << "Una aa" << std::endl; break;
            case 'É': c = 'é'; break;
            case 'Í': c = 'í'; break;
            case 'Ó': c = 'ó'; break;
            case 'Ú': c = 'ú'; break;
            case 'Ü': c = 'ü'; break;
            case 'Ñ': c = 'ñ'; break;
        }
}

bool comparar_ignorando_diacriticos(char caracter_1, char caracter_2)
{
    if (caracter_1 == caracter_2)
        return true;

    if ((caracter_1 > 127 && caracter_2 > 127) || (caracter_1 < 127 && caracter_2 < 127))
        return false;

    if (caracter_1 == 'Á' || caracter_1 == 'É' || caracter_1 == 'Í' || caracter_1 == 'Ó' || caracter_1 == 'Ú' || caracter_1 == 'Ü' || caracter_1 == 'Ñ')
        switch (caracter_1)
        {
            case 'Á': caracter_1 = 'á'; break;
            case 'É': caracter_1 = 'é'; break;
            case 'Í': caracter_1 = 'í'; break;
            case 'Ó': caracter_1 = 'ó'; break;
            case 'Ú': caracter_1 = 'ú'; break;
            case 'Ü': caracter_1 = 'ü'; break;
            case 'Ñ': caracter_1 = 'ñ'; break;
        }

    switch (caracter_1)
    {
        case 'á': return caracter_2 == 'a';
            break;
        case 'é': return caracter_2 == 'e';
            break;
        case 'í': return caracter_2 == 'i';
            break; 
        case 'ó': return caracter_2 == 'o';
            break;
        case 'ú': return caracter_2 == 'u' || caracter_2 == 'ü';
            break;
    }
}

std::string latin1_to_utf8(const std::string_view &latin1)
{
    std::string result;

    unsigned char byte1 = 0b11000000;
    unsigned char byte2 = 0b10000000;

    for (unsigned char c : latin1)
    {
        if (c < 0x80)
            result += c;
        else
        {
            result += byte1 | (c >> 6);
            result += byte2 | (c & ~byte2);
        }
    }

    return result;
}

std::string utf8_to_latin1(const std::string_view &utf8)
{
    std::string result;

    unsigned char byte = 0b00000000;

    for (unsigned char c : utf8)
    {
        if (c >> 7 == 0)
        {
            result += c;
            byte = 0b00000000;
        }
        else
        {
            if (byte == 0)
                byte = c << 6;
            else
                result += byte | (c & 0b00111111) ;
        }
    }
    return result;
}

bool es_primo(int n)
{
    unsigned c = 0 ;

    for(unsigned i = 1; i <= n; i++)
    {
        if (n % i == 0)
            c++;
    }
    return c <= 2;
}

void primos_en_binario(int cantidad)
{
    cantidad++;
     for (unsigned i = 2; i <= cantidad; i++)
     {
        if(es_primo(i))
            std::cout << std::bitset<8>(i) << std::endl;
        else
            cantidad++;
     }
}

void primos_en_decimal(int cantidad)
{
    cantidad++;
     for (unsigned i = 2; i <= cantidad; i++)
     {
        if(es_primo(i))
            std::cout << i << std::endl;
        else
            cantidad++;
     }
}

void primos_en_hexa(int cantidad)
{
    cantidad++;
     for (unsigned i = 2; i <= cantidad; i++)
     {
        if(es_primo(i))
            std::cout << std::hex << std::uppercase << i << std::endl;
        else
            cantidad++;
     }
}

int count_utf8_glyphs(const std::string_view &utf8)
{
    unsigned i = 0;
    for(unsigned char c : utf8)
        if(c >> 6 != 0b00000010) i++;

    return i;

}

bool is_equal(const std::string_view &str1, const std::string_view &str2)
{
    for(unsigned i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}