#include "store.ih"

void Store::define(std::string const &symbol, bool isFunction)
{
    auto iter = d_symbolMap.find(symbol);

    if (iter != d_symbolMap.end() and xrefData(iter).complete())
        return;                             // record already available


    if (iter != d_symbolMap.end())              // complete it by specifying
        xrefData(iter).setOrigin(d_sourceFile,  // remaining details
                                 d_objFile, isFunction);
    else                                        // or a completely new record
    {
        iter = d_symbolMap.insert( {symbol, d_xrefData.size() } ).first;

        d_xrefData.push_back(
            new XrefData{ d_sourceFile, d_objFile, isFunction, symbol }
        );
    }

    if (isFunction)
        d_functionIdx = iter->second;
}
