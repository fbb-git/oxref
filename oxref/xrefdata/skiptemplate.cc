#include "xrefdata.ih"

string::iterator XrefData::skipTemplate(string::iterator begin)
{
    begin = d_refname.find_first_of(begin, "<>");

    if (begin == 
}
