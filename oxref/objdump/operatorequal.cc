#include "objdump.ih"

bool ObjDump::const_iterator::operator==(const_iterator const &other) const
{
    return d_iterate == other.d_iterate && d_process == other.d_process;
}
