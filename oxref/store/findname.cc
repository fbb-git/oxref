#include "store.ih"

bool Store::findName(size_t idx, string const &name, 
                                                XrefVector const &xrefVector)
{
    return string(xrefVector[idx].name()).find(name) == 0;
}



