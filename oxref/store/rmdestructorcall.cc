#include "store.ih"

void Store::rmDestructorCall(size_t idx)
{
    XrefData &xrefData = *d_xrefData[idx];

    if (xrefData.keepDestrCall())
        return;

    for (
        auto iter = xrefData.calledFrom().begin(), 
             end =  xrefData.calledFrom().end();
                iter != end;
                    ++iter
    )
    {
                                                    // destructor found
        if (d_xrefData[*iter]->symbol().find("::~") != string::npos)
        {
            xrefData.rmFrom(iter);                  // rm the destructor idx
            d_xrefData[*iter]->rmCall(idx);         // the destructor doesn't
                                                    // call this fun. anymore
            return;
        }
    }
}
