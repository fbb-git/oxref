#include "store.ih"

Store::~Store()
{
    for (auto &refPtr: d_xrefData)
        delete refPtr;
}
