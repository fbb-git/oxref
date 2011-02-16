//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << '\n' <<
    progname << " by " << Icmbuild::author << '\n' <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::years << "\n"
    "\n"
    "Usage: " << progname << " [options] args\n"
    "Where:\n"
    "   [options] - optional arguments (short options between parentheses):\n"
    
    "      --arg (-a) ...\n"
    "              count - display function argument counts only\n"
    "              first - only display the first word of the parameter "
                                                                "types\n"
    "              <len> - restrict parameter types to the first <len> "
                                                                "characters\n"
    "      --full-symbol (-f)      - display the full symbol names (e.g.,\n"
    "                                including class name prefixes)\n"
    "      --help (-h)             - provide this help\n"
    "      --object-files (-o)     - display the object file names\n"
    "      --select name           - only display the cross-reference of "
                                                                "`name',\n"
    "                                where `name' is the (initial substring "
                                                            "of an)\n"
    "                                entity's name.\n"
    "      --select-pattern regex  - only display the cross-reference of "
                                                                "`regex',\n"
    "                                where `regex' is a regular expression\n"
    "                                against which (full) symbols are "
                                                                "matched\n"
    "      --source-files (-s)     - display the source file names\n"
    "      --xref-source-files (-x)- display the source file names in the \n"
    "                                cross-reference lists\n"
    "      --version (-v)          - show version information and terminate\n"
    "\n"
    "   args   - non-stripped .o or libraries whose symbols must be\n"
    "            cross-referenced.\n"
    "\n";
}
