#include "storage.ih"

void Storage::calltree(string const &startSymbol)
{
    if (size_t idx; not d_store.find(&idx, startSymbol))
        cout << "\n"
                "CALLTREE: construction failed.\n"
                "           No start symbol `" << startSymbol << "'\n";
    else
    {
        cout << "\n"
                "CALLTREE for " << startSymbol << "\n"
                "\n";

        d_store.calltree(idx);
    }
}
