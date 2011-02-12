//                     usage.cc

#include "main.ih"

void usage(std::string const &progname)
{
    cout << "\n" <<
    progname << " by " << Icmbuild::author << "\n" <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::years << "\n"
    "\n"
    "Usage: " << progname << " [options] args\n"
    "Where:\n"
    "   [options] - optional arguments (short options between parentheses):\n"
    
    "      --arg (-a) ...\n"
    "              count - display function's argument counts only\n"
    "              <len> - restrict parameter names to the first <len> "
                                                                "characters\n"
    "      --help (-h)             - provide this help\n"
    "      --no-object-files (-o)  - suppress the object file names\n"
    "      --no-source-files (-s)  - suppress the source file names\n"
    "      --select name           - only display the cross-reference of "
                                                                "`name',\n"
    "                                where `name' can be a substring of the "
                                                            "function(s)\n"
    "                                to display.\n"
    "      --version (-v)          - show version information and terminate\n"
    "   args   - explain additional arguments.\n"
    "\n";
}
