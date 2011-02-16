#include "xrefdata.ih"

void  XrefData::setCooked() 
{
    d_cooked = d_refName;

    size_t begin = d_cooked.find('(', d_nameIndex);
    size_t end = d_cooked.rfind(')');

    if (begin == string::npos || end == string::npos)   // no parentheses ???
        return;                                         // so be it...

    Arg &arg = Arg::instance();

    string option;
    if (not arg.option(&option, 'a'))
        return;                                         // no -a option

    if (option == "count")
        reduceToCount(begin, end);
    else if (option == "first")
        keepFirst(begin);
    else
    {
        size_t len = A2x(option);
        if (A2x::lastFail())
            throw Errno(1, arg.basename().c_str()) << " -a: invalid argument";

        if (len < 5)
            len = 5;

        reduceLen(begin, len);
    }
}



