#include "xrefdata.ih"

size_t XrefData::skipTemplate(size_t begin) const
{
    size_t level = 1;

    while (true)
    {
        begin = d_refName.find_first_of("<>", begin);

        if (begin == string::npos)
            throw Errno(1, "skipTemplate: invalid template spec. in ") <<
                                                                    d_refName;
        if (d_refName[begin] == '<')
            ++level;
        else
            --level;
    
        if (level == 0)
            return begin;

        ++begin;
    }
}
