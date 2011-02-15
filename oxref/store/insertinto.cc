#include "store.ih"

std::ostream &Store::insertInto(std::ostream &out) const
{
    //cerr << "insert store: insertinto\n";

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
        sort(d_defIdx.begin(), d_defIdx.end(), 
                                            FnWrap::binary(name, d_xrefData));
    
        for_each(d_defIdx.begin(), d_defIdx.end(),
            FnWrap::unary(insertDefined, out, d_xrefData));
    }

    return out;
}
