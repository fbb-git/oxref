#include "store.ih"

void Store::usedBy(size_t idx, std::ostream &out, XrefVector const &xref)
{
    XrefData const &ref = xref[idx];

    out << "    ";
    if (Arg::instance().option('x'))
        out << ref.sourceFile() << ": ";

    out << ref.symbol() << '\n';
}
