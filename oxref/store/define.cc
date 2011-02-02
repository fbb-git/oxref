#include "store.ih"

void Store::define(std::string const &symbol, bool isFunction)
{
    auto iter = find_if(d_xrefData.begin(), d_xrefData.end(),
                    FnWrap::unary(XrefData::isDefined, symbol));

    if (iter != d_xrefData.end())
        return;                         // symbol already defined

    iter = find_if(d_xrefData.begin(), d_xrefData.end(),
                   FnWrap::unary(XrefData::hasSymbol, symbol));

    size_t currentIdx;

    if (iter != d_xrefData.end())
    {
        currentIdx = iter - d_xrefData.begin();
        d_xrefData[currentIdx].setLocation(d_sourceFile, d_objFile);
        d_defIdx.push_back(currentIdx);
    }
    else
    {

                            // new symbol: defined at index currentIdx, 
                            // any *UND* elements are for function currentIdx
                            // if not a function, then d_currentIdx isn't 
                            // used with *UND* elements
        d_defIdx.push_back(currentIdx = d_xrefData.size());

        d_xrefData.push_back(
                XrefData(d_sourceFile, d_objFile, isFunction, symbol)
        );
    }

    if (isFunction)
        d_currentIdx = currentIdx;
}
