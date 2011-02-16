#include "main.ih"


namespace   // the anonymous namespace can be used here
{
    Arg::LongOption longOptions[] =
    {
        {"arg",                 'a'},
        {"help",                'h'},
        {"objdump",             Arg::Required},
        {"object-files",        'o'},
        {"source-files",        's'},
        {"full-symbol",         'f'},
        {"select-pattern",      Arg::Required},
        {"select",              Arg::Required},
        {"xref-source-files",   'x'},
        {"version",             'v'},
    };

    Arg::LongOption const *const longEnd =
                    longOptions +
                    sizeof(longOptions) / sizeof(Arg::LongOption);
}

int main(int argc, char **argv)
try
{
    Arg &arg = Arg::initialize("a:fhosvx", longOptions, longEnd, argc, argv);
    arg.versionHelp(usage, version, 1);

    ObjDump odump;
    Storage storage;


    odump.start();          // generate objdump's output

                            // insert into Storage
    copy(odump.begin(), odump.end(), back_inserter(storage));

                            // display the results
    cout << storage << '\n';
}
catch (Errno const &e)
{
    cout << e.why() << '\n';
    return 1;
}
catch (std::exception const &e)
{
    cout << e.what() << '\n';
    return 1;
}
catch (int x)
{
    return x;
}
catch (...)
{
    cout << "Caught unaccounted for exception\n";
    return 1;
}


