#include "xrefdata.ih"

voi XrefData::reduceCount()
{
    size_t last = d_refName.rfind(')');

    if (last == string::npos)               // no closing parenthesis ???
        return;

    size_t nArgs = 0;

    for 
    (
        auto begin = d_refName.begin() + d_nameIndex, 
             end   = d_refName.begin() + last;
        begin != end;
            // no inc. here
    )
    {
        switch (*begin)
        {
            case ' ':           // ignore blanks
            case '\t':
            case ',':           // skip over the comma's
                ++begin;
            break;

            default:
                begin = d_refName.find_first_of(begin, 
                                                "<, \t)");  // skip argument
                ++nArgs;
            break;

            case '<':
                begin = skipTemplate(begin);
            break;
        }
    }
}

