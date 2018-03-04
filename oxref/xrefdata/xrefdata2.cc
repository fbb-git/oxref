#include "xrefdata.ih"

XrefData::XrefData(string const &sourceFile, string const &objFile, 
                   bool isFunction, string const &symbol)
:
    d_refName(symbol),
    d_sourceFile(sourceFile),
    d_objFile(objFile),
    d_isFunction(isFunction)
{
    init();
}
