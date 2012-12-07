#include "main.ih"

namespace
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
    cout << 
        arg.basename() << " by " << Icmbuild::author << '\n' <<
        arg.basename() << " V" << Icmbuild::version << ' ' << 
                                                    Icmbuild::years << "\n"
        "\n"
        "CREATED " << DateTime().rfc2822() << "\n"
        "CROSS REFERENCE FOR: ";

    copy(argv + 1, argv + argc, ostream_iterator<char const *>(cout, " "));

    cout << '\n' <<
        setfill('-') << setw(70) << '-' << setfill(' ') << "\n"
        "\n" <<
        storage << '\n';
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
    return Arg::instance().option("hv")) ? 0 : x;
}
catch (...)
{
    cout << "Caught unaccounted for exception\n";
    return 1;
}


