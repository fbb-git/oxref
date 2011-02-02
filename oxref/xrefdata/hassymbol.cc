#include "xrefdata.ih"

bool XrefData::hasSymbol(XrefData const &data, string const &symbol)
{
    return data.d_refName == symbol;
}
        
