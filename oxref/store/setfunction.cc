#include "store.ih"

void Store::setFunction(string const &symbol)
{
    d_symbol = symbol;

    define(symbol, true);   // true: define a function
}
