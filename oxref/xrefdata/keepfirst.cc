#include "xrefdata.ih"

void XrefData::keepFirst(size_t openParIdx)
{
//cout << d_cooked << "\n";

    size_t begin = openParIdx;
  
    while (d_cooked[begin] != ')')
    {
        ++begin;                                    // beyond the separator

        if (d_cooked[begin] == ' ')                 // keep blank after sep.
            ++begin;

        size_t next = d_cooked.find_first_not_of(" \t", begin); // erase extra
        d_cooked.erase(begin, next - begin);                    // blanks

                                                    // find end of 1st word:
                                                    //  < begins template
                                                    //  , ends argument
                                                    //  ) ends parlist
                                                    //  blank ends 1st word
        begin = d_cooked.find_first_of("*&<,) \t", begin);
        
        begin = eraseParam(begin);                  // erase the param. from
                                                    // 'begin', return , or )
                                                    // position
    }
}
