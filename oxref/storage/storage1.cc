#include "storage.ih"

Storage::Storage()
{
    string arg;
    if (Arg::instance().option(&arg, "simplify") == 0)
        d_simplifyPtr = &Storage::dontSimplify;
    else
    {
        ifstream in;
        Exception::open(in, arg);

        while (getline(in, arg))    // read a line
        {
            size_t pos = arg.find("->");    // find the separator

            if (pos == string::npos)        // not found, try the next line
                continue;

            d_simplify.push_back(
                { String::trim(arg.substr(0, pos)),
                  String::trim(arg.substr(pos + 2)) }
            );
        }

        d_simplifyPtr = &Storage::simplify;
    }                
}
