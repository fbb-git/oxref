#include "xrefdata.ih"

XrefData::XrefData(string const &symbol)
:
    d_isFunction(false),        // actually: not yet known
    d_refName(symbol)
{
    setNameIndex();
}
