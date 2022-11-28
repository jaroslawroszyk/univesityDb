#include <iostream>
#include "../include/student.hpp"
#include "../include/database.hpp"

template<typename T>
void print(const T& vec)
{
    for(const auto& el : vec)
    {
        std::cout << el << ' ';
    }
    std::cout << '\n';
}

int main() 
{
    Database db;
    Student none{
            "none",
            "none",
            "none",
            1111,
            "24142",
            Gender::None
    };
    Student Ania{
            "Ania",
            "Kos",
            "ul.Bogatynska 12 00-201 Radom",
            6951,
            "1695678912",
            Gender::Female
    };
    db.initDatabase(db,Ania,none);
//    db.initDatabase(db,none);
//db.add(Ania);
//db.add(none);
//std::cout << db.show();
std::cout <<std::boolalpha<< db.searchByName("none");
db.show();
//    auto it = db.show();
//    print(it);
}
