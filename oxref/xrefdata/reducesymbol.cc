#include "xrefdata.ih"

string  XrefData::reduceSymbol(string const &symbol) const
{
    string ret(symbol);

    Arg &arg = Arg::instance();

    string option;
    if (not arg.option(&option, 'a'))
        return ret;

    if (option == "count")
        reduceToCount(ret);
    else if (option == "first")
        keepFirst();
    else
    {
        size_t len = A2x(option);
        if (A2x::lastFail())
            throw Errno(1, arg.basename().c_str()) << " -a: invalid argument";

        reduceLen(len);
    }

    return ret;
}
