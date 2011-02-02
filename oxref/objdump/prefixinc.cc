#include "objdump.ih"

ObjDump::const_iterator &ObjDump::const_iterator::operator++() 
{
    if (d_iterate)
        d_iterate = std::getline(*d_process, d_line);

    return *this;    
}

/*
    begin: initialize to true
    end: initialize to false

    while (begin != end)    // if d_iterate is true: reassign by 
                            // getline(*d_process, ...), then compare both 
                            // d_iterate-s, 
    {
        cout << *begin;
        ++begin;
    }
*/
