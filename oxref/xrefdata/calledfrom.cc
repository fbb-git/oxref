#include "xrefdata.ih"

void XrefData::calledFrom(size_t currentIdx)
{
    d_calledFrom.push_back(currentIdx);
}
