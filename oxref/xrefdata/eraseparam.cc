#include "xrefdata.ih"

size_t XrefData::eraseParam(size_t begin)
{
    size_t next = begin;

    while (true)
    {
        next = d_cooked.find_first_of("*&<,)", next);

        if (d_cooked[next] != '<')
            break;

        next = skipTemplate(next + 1) + 1;
    }
    
    d_cooked.erase(begin, next - begin);

    return d_cooked.find_first_of(",)", begin);
}
