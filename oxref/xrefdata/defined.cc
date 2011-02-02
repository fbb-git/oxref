#include "xrefdata.ih"

void XrefData::defined(std::ostream &out) const
{
    out << name() << '\n' <<
            "    " << d_refName << ":\n" << 
            "       " << d_sourceFile << " (" << d_objFile << ")\n";
}
