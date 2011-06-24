#include "xrefdata.ih"

bool XrefData::isDefined(string const &symbol) const
{
    return not d_sourceFile.empty() && d_refName == symbol;
}
        
