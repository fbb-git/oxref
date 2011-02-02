#include "storage.ih"

void Storage::sourceFile(std::string const &fname)
{
    //d_sourceFile = fname;
    //cout << "SOURCE FILE: " << d_sourceFile << '\n';

    d_store.setSource(fname);
}
