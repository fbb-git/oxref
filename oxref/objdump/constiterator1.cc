#include "objdump.ih"

ObjDump::const_iterator::const_iterator(Process *process, bool iterate)
:
    d_process(process),
    d_iterate(iterate)
{
    ++*this;    
}
