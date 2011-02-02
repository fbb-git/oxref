#include "xrefdata.ih"

XrefData::XrefData(string const &sourceFile, string const &objFile, 
                   bool isFunction, string const &symbol)
:
    d_sourceFile(sourceFile),
    d_objFile(objFile),
    d_isFunction(isFunction),
    d_refName(symbol)
{
    setNameIndex();
}
