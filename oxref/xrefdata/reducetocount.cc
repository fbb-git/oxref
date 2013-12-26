#include "xrefdata.ih"

void XrefData::reduceToCount(size_t openParIdx, size_t end)
{
    size_t nArgs = 0;

    for (size_t begin = openParIdx + 1;  begin != end; ++begin)
    {
        switch (d_cooked[begin])
        {
            case ' ':           // ignore blanks
            case '\t':
            case ',':           // skip over the comma's
            break;

            default:            // skip argument
                begin = d_cooked.find_first_of("<,)", begin);  
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
    {
        auto iter = d_cooked.begin();
        d_cooked.replace(iter + openParIdx + 1, iter + end, to_string(nArgs));
    }
}

