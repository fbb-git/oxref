#include "store.ih"

void Store::insertDefined(size_t idx, ostream &out, XrefVector const &xref)
{
    XrefData const &ref = xref[idx];

    auto begin = ref.usedBy().begin();
    auto end = ref.usedBy().end();

    if (begin != end)
    {
        ref.defined(out);
        for_each(begin, end, FnWrap::unary(usedBy, out, xref));
    }
    out << '\n';
}
