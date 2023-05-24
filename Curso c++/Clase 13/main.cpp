#include <iostream>
#include <string>
#include <map>

template <typename FIRST, typename SECOND>
struct pair
{
    pair(FIRST f, SECOND s) : first(f), second(s) {}
    FIRST first;
    SECOND second;
};

using employee_data = pair<std::string, unsigned>; 

//USING = DEFINIR UN ALIAS DE TIPO

std::string
get_employee_name(unsigned age)
{
    return "Nombre copado";
}

unsigned
get_employee_age(unsigned age)
{
    return 1;
} 

auto
get_employee_data(unsigned employeeId)
{
    std::string name = get_employee_name(employeeId);
    unsigned age = get_employee_age(employeeId);
    return pair { name, age }; //Esto es como llamar al constructor de pair<std::string, unsigned>
}


int main()
{
    employee_data data = get_employee_data(1234);
    std::cout << "Name: " << data.first << ", Age: " << data.second << std::endl;
}