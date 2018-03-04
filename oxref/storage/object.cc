#include "storage.ih"

void Storage::object(std::string const &symbol)
{
    d_store.setObject((this->*d_simplifyPtr)(symbol));
}
