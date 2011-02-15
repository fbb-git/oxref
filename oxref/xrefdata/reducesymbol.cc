#include "xrefdata.ih"

void XrefData::reduceSymbol()
{
    Arg &arg = Arg::instance();

    string option;
    if (not arg.option(&opion, 'a'))
        return;

    if (option == "count")
        reduceToCount();
    else if (option == "first")
        keepFirst();
    else
    {
        size_t len = A2x(option);
        if (A2x::lastFail())
            throw Errno(1, arg.basename()) << " -a: invalid argument";

        reduceLen(len);
    }
}
