#include "store.ih"

void Store::fromToCall(size_t calleR, bool isDestructor, size_t callEE)
{
    d_xrefData[calleR]->calls(callEE);
    d_xrefData[callEE]->calledFrom(calleR);

    if (isDestructor)
        d_xrefData[callEE]->setKeepDestrCall();
}
