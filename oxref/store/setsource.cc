#include "store.ih"

void Store::setSource(std::string const &fname)
{
    d_sourceFile = fname;

//    cout << "Sourcefile: " << d_sourceFile << '\n';

    d_currentIdx = d_xrefData.size();
    define("GLOBALS " + fname + " " + d_objFile, false);
}
