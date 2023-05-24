#include <cctype> // for std::toupper/tolower
#include <locale> // for std::locale
#include <codecvt> // for std::wstring_convert

#include "case_toupper.h"

std::string 
international::to_upper(const std::string &s, const std::string &locale)
{
    std::wstring wide = std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().from_bytes(s);
    std::wstring result;
    for (wchar_t c : wide)
        result += std::toupper(c, std::locale(locale));
    return std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t>().to_bytes(result);
}