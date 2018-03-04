#include "store.ih"

ostream &Store::insertPattern(ostream &out, string const &name) const
{
    auto iter = d_xrefData.begin();
    auto end = d_xrefData.end();

    Pattern namePattern{ name };

    while (true)
    {
        iter = find_if
                (
                    iter, end, 
                    [&](XrefData const *ref)
                    {
                        return namePattern << ref->symbol();
                    }
                );
        if (iter == end)
            break;

        insertDefined(out, *iter, d_xrefData);
        ++iter;
    }

    return out;
}

