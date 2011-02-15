#include "xrefdata.ih"

inline  std::string XrefData::symbol() const
{
    return reduceSymbol(d_refName);
}


