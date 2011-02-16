#include "xrefdata.ih"

void XrefData::defined(std::ostream &out) const
{
    out << name() << '\n';

    if (d_fullSymbol)
        out  << "  Full name: " << symbol() << '\n';

    if (d_source) 
        out << "   Source: " << d_sourceFile << ' ';

    if (d_object)
        out << '(' << d_objFile << ')';

    if (d_source || d_object)
        out << '\n';
}
