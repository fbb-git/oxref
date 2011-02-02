#include "storage.ih"

void Storage::object(std::string const &symbol)
{
    d_store.setObject(symbol);
}
