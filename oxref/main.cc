#include "main.ih"


namespace   // the anonymous namespace can be used here
{
    Arg::LongOption longOptions[] =
    {
        {"help", 'h'},
        {"objdump", Arg::Required},
        {"objectfiles", 'o'},
        {"sort-by", 's'},       // may be multiply used
        {"version", 'v'},
    };

    Arg::LongOption const *const longEnd =
                    longOptions +
                    sizeof(longOptions) / sizeof(Arg::LongOption);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("hos:v", longOptions, longEnd, argc, argv);
    arg.versionHelp(usage, version, 1);

    ObjDump odump;
    Storage storage;

    odump.start();          // generate objdump's output

                            // insert into Storage
    copy(odump.begin(), odump.end(), back_inserter(storage));

                            // display the results
    cout << storage << '\n';

}
catch (...)
{
    return 1;
}


