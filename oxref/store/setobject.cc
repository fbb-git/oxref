#include "store.ih"

void Store::setObject(string const &symbol)
{
    d_symbol = symbol;

    define(symbol, false);   // false: define an object
}
