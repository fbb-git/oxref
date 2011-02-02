#include "store.ih"

bool Store::name(size_t left, size_t right, XrefVector const &xrefVector)
{
    return strcasecmp(xrefVector[left].name(), xrefVector[right].name()) < 0;
}



