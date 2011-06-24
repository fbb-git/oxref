#include "xrefdata.ih"

bool XrefData::hasSymbol(string const &symbol) const
{
    return d_refName == symbol;
}
        
