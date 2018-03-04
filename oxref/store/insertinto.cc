#include "store.ih"

std::ostream &Store::insertInto(std::ostream &out)
{
    Arg &arg = Arg::instance();

    string entity;
    if 
    (
        bool doSelect = arg.option(&entity, "select");
        doSelect || arg.option(&entity, "select-pattern")
    )
        return doSelect ?
                    insertSelect(out, entity)
                :
                    insertPattern(out, entity);

    vector<size_t> support(d_xrefData.size());
    for (size_t idx = 0, end = support.size(); idx != end; ++idx)
        support[idx] = idx;

    sort(
        support.begin(), support.end(), 
        [&](size_t lhs, size_t rhs)
        {
            return strcasecmp(d_xrefData[lhs]->name(), 
                              d_xrefData[rhs]->name()) < 0;
        }
    );

    for (size_t idx: support)    
        insertDefined(out, d_xrefData[idx], d_xrefData);

    return out;
}



