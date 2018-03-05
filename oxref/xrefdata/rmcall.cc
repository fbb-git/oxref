#include "xrefdata.ih"

void XrefData::rmCall(size_t idx)
{
    auto iter = std::find(d_calls.begin(), d_calls.end(), idx);
    if (iter != d_calls.end())
        d_calls.erase(iter);
}
