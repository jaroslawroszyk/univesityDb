#include "database.hpp"

bool Database::add(const Student &s)
{
    if (isAdded)
    {
        return false;
    }
    else
    {
        isAdded = true;
        return true;
    }
}