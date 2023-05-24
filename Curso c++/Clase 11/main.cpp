#include <iostream>
#include <string>

#include "case_tolower.h"
#include "case_toupper.h"

int main()
{
    std::cout << international::to_upper("ñandú") << std::endl;
    return 0;
}