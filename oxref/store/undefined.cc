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
                
    auto iter = find_if(
                    d_xrefData.begin(), d_xrefData.end(),
                    [&](XrefData const &xrefData)
                    {
                        return xrefData.hasSymbol(symbol);
                    }
                );
                  //  FnWrap::unary(XrefData::hasSymbol, symbol));

    size_t index = iter - d_xrefData.begin();   // index of this symbol

    if (iter == d_xrefData.end())               // symbol not yet defined
    {
        index = d_xrefData.size();
        d_xrefData.push_back(XrefData(symbol)); // define the symbol
    }

    d_xrefData[index].calledFrom(d_currentIdx);
}







