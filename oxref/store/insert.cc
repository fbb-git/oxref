#include "store.ih"

void Store::insert(ostream &out, string const &name, bool doSelect) const
{
    auto iter = d_defIdx.begin();
    auto end = d_defIdx.end();

    Pattern namePattern;

    if (not doSelect)
        namePattern.setPattern(name);

    while (true)
    {
        iter = doSelect ?
                    find_if(
                        iter, end, 
                        [&](size_t idx)
                        {
                            return string(d_xrefData[idx].name()).find(name) 
                                    == 0;
                        }
                    )
                :
                    find_if(
                        iter, end, 
                        [&](size_t idx)
                        {
                            return namePattern << d_xrefData[idx].symbol();
                        }
                    );

        if (iter == end)
            break;

        insertDefined(*iter, out, d_xrefData);
        ++iter;
    }
}

