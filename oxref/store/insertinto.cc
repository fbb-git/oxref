#include "store.ih"

std::ostream &Store::insertInto(std::ostream &out) const
{
    Arg &arg = Arg::instance();

    bool doSelect;

    string entity;
    if 
    (
        (doSelect = arg.option(&entity, "select"))
        || 
        arg.option(&entity, "select-pattern")
    )
        insert(out, entity, doSelect);
    else
    {
        sort(
            d_defIdx.begin(), d_defIdx.end(), 
            [&](size_t left, size_t right)
            {
                return 
                    strcasecmp(d_xrefData[left].name(), 
                               d_xrefData[right].name()) < 0;
            }
        );

        for (auto idx: d_defIdx)    
            insertDefined(idx, out, d_xrefData);
    }

    return out;
}



