#include "main.ih"

namespace
{
    Arg::LongOption longOptions[] =
    {
        {"arg",                 'a'},
        {"calltree",            Arg::Required},
        {"dont-repeat",         Arg::None},
        {"help",                'h'},
        {"objdump",             Arg::Required},
        {"object-files",        'o'},
        {"source-files",        's'},
        {"full-symbol",         'f'},
        {"no-data",             Arg::None},
        {"no-xref",             Arg::None},
        {"select-pattern",      Arg::Required},
        {"select",              Arg::Required},
        {"simplify",            Arg::Required},
        {"xref-source-files",   'x'},
        {"version",             'v'},
    };

    Arg::LongOption const *const longEnd = longOptions + size(longOptions);
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
    cout << 
        arg.basename() << " by " << Icmbuild::author << '\n' <<
        arg.basename() << " V" << Icmbuild::version << ' ' << 
                                                    Icmbuild::years << "\n"
        "\n"
        "CREATED " << DateTime().rfc2822() << "\n";

    if (not arg.option(0, "no-xref"))
    {
        cout << "CROSS REFERENCE FOR: ";

        copy(argv + 1, argv + argc, 
             ostream_iterator<char const *>(cout, " "));

        cout << '\n' <<
            setfill('-') << setw(70) << '-' << setfill(' ') << "\n"
            "\n" <<
            storage << '\n';
    }

    string startSymbol;
    if (arg.option(&startSymbol, "calltree"))
        storage.calltree(startSymbol);

}
catch (std::exception const &e)
{
    cout << e.what() << '\n';
    return 1;
}
catch (int x)
{
    return Arg::instance().option("hv") ? 0 : x;
}
catch (...)
{
    cout << "Caught unaccounted for exception\n";
    return 1;
}


