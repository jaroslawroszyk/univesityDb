#include <iostream>
#include "Student.hpp"
#include "Database.hpp"
#include "Utils.hpp"

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
    db.initDatabase(db, Ania, none);
    //    db.initDatabase(db,none);
    //db.add(Ania);
    //db.add(none);
    //std::cout << db.show();
    std::cout << std::boolalpha << db.searchByName("none");
    //    auto it = db.show();
    //    print(it);
}
