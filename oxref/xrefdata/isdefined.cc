#include "xrefdata.ih"

bool XrefData::isDefined(XrefData const &data, string const &symbol)
{
    return not data.d_sourceFile.empty() && data.d_refName == symbol;
}
        
