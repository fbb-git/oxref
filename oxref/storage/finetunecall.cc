#include "storage.ih"

void Storage::fineTuneCall(size_t calleR, bool isDestructor, 
                          string declaration)
{
//cerr << __FILE__ << ": " << declaration << endl;

    size_t callEE = d_store.find(String::trim(declaration));

    if (callEE == ~0UL)
        return;

    d_store.rmDestructorCall(callEE);
    d_store.fromToCall(calleR, isDestructor, callEE);
}
