#include <iostream>
#include <map>
#include <string>
#include <algorithm>

struct class_assistant
{
    std::string first_name;
    std::string last_name;
    
    bool operator<(const class_assistant &p) const
    {
        if (last_name == p.last_name)
            return first_name < p.first_name;
        return last_name < p.last_name;
    }
};

bool descending (const class_assistant &a, const class_assistant &b)
{
    return b < a;
}

int main()
{
    std::vector<class_assistant> v =
    {
        { "Facundo", "Cabral" }, { "Dante", "Cocciolo"},
        { "Bruno", "Lisanti" }, { "Mauro", "Losanto" },
        { "Lucas", "De Lary" }, { "Leandro", "Binetti" },
        { "Ricardo", "Cárdenes" }, { "Marcelo", "Bartolomé" },
        { "Pedro", "Sosa" }
    };
    
    //std::sort(v.begin(), v.end(), descending); //
    
    std::sort (v.begin(), v.end(), 
        [](const class_assistant &a, const class_assistant &b) { return b < a; });
    
    for (auto i : v)
        std::cout << i.first_name << " / " << i.last_name << std::endl;
}