#include "xrefdata.ih"

void XrefData::reduceToCount(std::string &symbol) const
{
    size_t end = d_refName.rfind(')');

    if (end == string::npos)               // no closing parenthesis ???
        return;

    size_t nArgs = 0;

    size_t begin = d_nameIndex + 1;

    for (;  begin != end; ++begin)
    {
        switch (d_refName[begin])
        {
            case ' ':           // ignore blanks
            case '\t':
            case ',':           // skip over the comma's
            break;

            default:            // skip argument
                begin = d_refName.find_first_of("<,)", begin);  
                if (begin == end)
                    --begin;
                ++nArgs;
            break;

            case '<':
                begin = skipTemplate(begin);
            break;
        }
    }

    if (nArgs)
        symbol = d_refName.substr(d_nameIndex,  + 1) + X2a(nArgs) + ")";
}

