#include "store.ih"

std::ostream &Store::insertInto(std::ostream &out) const
{
    cerr << "insert store: insertinto\n";

    Arg &arg = Arg::instance();

    if (arg.option(0, 's'))
        sort(d_defIdx.begin(), d_defIdx.end(), 
                               FnWrap::binary(name, d_xrefData));
    
    for_each(d_defIdx.begin(), d_defIdx.end(),
        FnWrap::unary(insertDefined, out, d_xrefData));

    return out;
}
