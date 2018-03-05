#include "store.ih"

void Store::calltree(size_t idx, size_t nestLevel) const
{
    XrefData const &ref = *d_xrefData[idx];

    if (
        not ref.complete() 
        or
        (d_noData and not ref.isFunction())
    )
        return;

    cout << setw(2 * nestLevel) << ' ' << ref.symbol() << '\n';

    ++nestLevel;

    for (size_t idx: ref.calls())
        calltree(idx, nestLevel);
}
