#include "objdump.ih"

void ObjDump::addObject(string const &arg, Process &process)
{
    process += " ";
    process += arg;
}
