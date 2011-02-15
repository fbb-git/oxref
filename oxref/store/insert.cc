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
                    find_if(iter, end, 
                        FnWrap::unary(findName, name, d_xrefData)) 
                :
                    find_if(iter, end, 
                        FnWrap::unary(findSymbolPattern, 
                                                namePattern, d_xrefData));


        if (iter == end)
            break;

        insertDefined(*iter, out, d_xrefData);
        ++iter;
    }
}

