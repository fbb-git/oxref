#include "store.ih"

bool Store::find(size_t *idxPtr, string const &startSymbol) const
{
    auto iter = d_symbolMap.find(startSymbol);

    if (iter == d_symbolMap.end())
        return false;

    *idxPtr = iter->second;
    return true;
}
