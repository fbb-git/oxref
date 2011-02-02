#include "objdump.ih"

ObjDump::ObjDump()
:
    d_process(Process::COUT)
{
    Arg &arg = Arg::instance();

    string odump;
    if (!arg.option(&odump, "objdump"))
        odump = "/usr/bin/objdump -C -t";

    d_process.setCommand(odump);

    for_each(arg.argPointers(), arg.argPointers() + arg.nArgs(), 
        FnWrap::unary(addObject, d_process));
}
