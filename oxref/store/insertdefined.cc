#include "store.ih"

void Store::insertDefined(ostream &out, XrefData const *ref, 
                                        XrefVector const &xref)
{
    if (not ref->complete())
        return;

    auto begin = ref->usedBy().begin();
    auto end = ref->usedBy().end();

    if (begin != end)
    {
        ref->defined(out);
        out << "  Used By:\n";
        for (auto idx: ranger(begin, end))
            usedBy(idx, out, xref);

        out << '\n';
    }
}


