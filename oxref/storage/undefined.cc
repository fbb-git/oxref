#include "storage.ih"

void Storage::undefined(std::string const &symbol)
{
    //cout << "UNDEF'D: " << symbol << '\n';

    d_store.undefined((this->*d_simplifyPtr)(symbol));
}
