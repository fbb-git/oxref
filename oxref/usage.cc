//                     usage.cc

#include "main.ih"

namespace {
    char const info[] = R"(
Where:
   [options] - optional arguments (short options between parentheses):

      --arg (-a) ...
              count - display function argument counts only
              first - only display the first word of the parameter types
              <len> - restrict parameter types to the first <len> characters
      --calltree startsymbol  - write the call-tree to stdout
      --dont-repeat           - don't repeat sections in call-trees, but
                                mark the top-entries of repeated sections
      --full-symbol (-f)      - display the full symbol names (e.g.,
                                including class name prefixes)
      --help (-h)             - provide this help
      --no-data               - do not report data in call-trees
      --no-xref               - do not write the cross-reference listing to
                                stdout
      --object-files (-o)     - display the object file names
      --select name           - only display the cross-reference of `name',
                                where `name' is the (initial substring of an)
                                entity's name.
      --select-pattern regex  - only display the cross-reference of `regex',
                                where `regex' is a regular expression
                                against which (full) symbols are matched
      --simplify path         - path to a file containing lines holding
                                simplified type specifications using the form:
                                    full spec -> simplified spec
      --source-files (-s)     - display the source file names
      --xref-source-files (-x)- display the source file names in the 
                                cross-reference lists
      --version (-v)          - show version information and terminate

   args   - non-stripped .o or libraries whose symbols must be
            cross-referenced.
)";
} // anonymous

void usage(std::string const &progname)
{
    cout << '\n' <<
    progname << " by " << Icmbuild::author << '\n' <<
    progname << " V" << Icmbuild::version << " " << Icmbuild::years << "\n"
    "\n"
    "Usage: " << progname << " [options] args" << info;
}
