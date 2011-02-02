#include "xrefdata.ih"

void XrefData::setLocation(string const &sourceFile, string const &objFile)
{
    d_sourceFile = sourceFile;
    d_objFile = objFile;
}
