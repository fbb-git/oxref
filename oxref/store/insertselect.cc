#include "store.ih"

ostream &Store::insertSelect(ostream &out, string const &name) const
{
    auto iter = d_xrefData.begin();
    auto end = d_xrefData.end();

    while (true)
    {
        iter = find_if
                (
                    iter, end, 
                    [&](XrefData const *ref)
                    {
                        return string{ ref->name() }.find(name) == 0;
                    }
                );

        if (iter == end)
            break;

        insertDefined(out, *iter, d_xrefData);
        ++iter;
    }

    return out;
}

