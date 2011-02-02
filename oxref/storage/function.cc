#include "storage.ih"

void Storage::function(std::string const &symbol)
{
    // Note: symbols may multiply appear in objfiles
    d_store.setFunction(symbol);
}
