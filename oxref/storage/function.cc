#include "storage.ih"

void Storage::function(std::string const &symbol)
{
    // Note: symbols may repeatedly appear in objfiles
    d_store.setFunction((this->*d_simplifyPtr)(symbol));
}
