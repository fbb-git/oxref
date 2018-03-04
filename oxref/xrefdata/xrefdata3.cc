#include "xrefdata.ih"

XrefData::XrefData(string const &symbol)
:
    d_refName(symbol),
    d_isFunction(false)         // actually: not yet known
{
    init();
}
