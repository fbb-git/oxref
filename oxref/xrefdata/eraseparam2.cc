#include "xrefdata.ih"

size_t XrefData::eraseParam(size_t begin, size_t len)
{
    size_t next = begin;

    while (true)
    {
        next = d_cooked.find_first_of("*&<,)", next);

        if (d_cooked[next] != '<')
            break;

        next = skipTemplate(next + 1) + 1;
    }

    if (next - begin > len)
    {
        d_cooked.erase(begin + len, next - begin - len);
        begin += len;
        d_cooked.replace(begin - 3, 3, "...", 3);
    }

    return d_cooked.find_first_of(",)", begin);
}
