#include "xrefdata.ih"

void XrefData::reduceLen(size_t openParIdx, size_t len)
{
    size_t begin = openParIdx;
  
    while (d_cooked[begin] != ')')
    {
        ++begin;                                    // beyond the separator

        if (d_cooked[begin] == ' ')                 // keep blank after sep.
            ++begin;

        size_t next = d_cooked.find_first_not_of(" \t", begin); // erase extra
        d_cooked.erase(begin, next - begin);                    // blanks

        begin = eraseParam(begin, len);             // erase the param. from
                                                    // 'begin', return , or )
                                                    // position
    }
}
