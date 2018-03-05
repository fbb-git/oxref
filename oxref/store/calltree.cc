#include "store.ih"

void Store::calltree(size_t idx)
{
    XrefData &ref = *d_xrefData[idx];

    if (
        not ref.complete() 
        or
        (d_noData and not ref.isFunction())
    )
        return;

    ++d_lineNr;

    if (d_dontRepeat and ref.lineNr() != 0 and ref.calls().size())
    {
        cout << setw(4) << d_lineNr << 
                setw(2 * d_nestLevel) << ' ' << ref.symbol() << 
                        " -> line " << ref.lineNr() << '\n';
        return;
    }

    if (ref.lineNr() == 0)
        ref.lineNr(d_lineNr);

    cout << setw(4) << d_lineNr << setw(2 * d_nestLevel) << ' ' << 
            ref.symbol() << '\n';

    ++d_nestLevel;

    for (size_t idx: ref.calls())
        calltree(idx);

    --d_nestLevel;
}

