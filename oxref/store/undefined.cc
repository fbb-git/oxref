#include "store.ih"

    // 00000000         *UND*  00000000 std::ios_base::Init::Init()
    //                                  ---------------------------

void Store::undefined(std::string const &symbol)
{
    // find 'symbol' in d_xrefData. 
    // If not yet available add it to xrefData.
    // Determine the symbol's index in xrefData
    // The function currently handled has a currentIdx and from that index
    // the current *UND* symbol is called.
                
    auto iter = d_symbolMap.find(symbol);
    
    if (iter == d_symbolMap.end())          // new entity: add to d_xrefData
    {
        iter = d_symbolMap.insert( { symbol, d_xrefData.size() } ).first;
                                            // define the symbol, add it to
                                            // symbolMap and update iter
        d_xrefData.push_back(new XrefData{ symbol });   

    }

    xrefData(iter).calledFrom(d_functionIdx);
}
