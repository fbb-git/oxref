#include "store.ih"

bool Store::findSymbolPattern(size_t idx, Pattern &namePattern, 
                                                XrefVector const &xrefVector)
{
    return namePattern << xrefVector[idx].symbol();
}



