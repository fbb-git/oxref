#include "xrefdata.ih"

size_t XrefData::skipTemplate(size_t begin) const
{
    size_t level = 1;

    while (true)
    {
        begin = d_cooked.find_first_of("<>", begin);

        if (begin == string::npos)
            throw Errno(1, "skipTemplate: invalid template spec. in ") <<
                                                                    d_cooked;
        if (d_cooked[begin] == '<')
            ++level;
        else
            --level;
    
        if (level == 0)
            return begin;

        ++begin;
    }
}
