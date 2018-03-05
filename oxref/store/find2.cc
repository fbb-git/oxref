#include "store.ih"

size_t Store::find(string const &declaration)
{
    auto iter = d_symbolMap.find(declaration);
    
    return iter == d_symbolMap.end() ? ~0UL : iter->second;
}
