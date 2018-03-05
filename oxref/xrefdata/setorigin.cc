#include "xrefdata.ih"

void XrefData::setOrigin(string const &sourceFile, string const &objFile, 
                         bool isFunction)
{
    d_sourceFile = sourceFile;
    d_objFile = objFile;
    d_isFunction = isFunction;
}
