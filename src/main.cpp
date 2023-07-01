#include <iostream>
#include "Student.hpp"
#include "Database.hpp"

int main()
{
    Database db;
    Student none{
            "none",
            "none",
            "none",
            1111,
            "24142",
            Gender::Other
    };
    Student Ania{
            "Ania",
            "Kos",
            "ul.Bogatynska 12 00-201 Radom",
            6951,
            "1695678912",
            Gender::Female
    };
    db.add(Ania);
    db.add(none);
    db.printByGender(Gender::Other);
    // // db.show();
    // db.deleteByIndex(1111);
    // db.show();
}
