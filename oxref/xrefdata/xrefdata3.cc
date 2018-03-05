#include "xrefdata.ih"

XrefData::XrefData(string const &symbol)
:
    d_refName(symbol)
{
    init();
}
