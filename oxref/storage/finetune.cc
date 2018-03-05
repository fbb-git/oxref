#include "storage.ih"

void Storage::fineTune()
{
    ifstream in("finetune.txt");
    if (not in)
        return;

    size_t funIdx = ~0UL;       // index of the function matching the last
                                // encountered //f line
    bool destructor = false;

    string line;
    while (getline(in, line))
    {
        size_t pos = line.find("//f:");
        if (pos != string::npos)
        {
                                // find the calling function, and determine
                                // whether it is a destructor.
            funIdx = d_store.find(String::trim(line.substr(pos + 4)));
            if (funIdx != ~0UL)
                destructor = d_store.isDestructor(funIdx);
            continue;
        }
        
        if (funIdx == ~0UL)
            continue;

        pos = line.find("//c:");
        if (pos != string::npos)
            fineTuneCall(funIdx, destructor, line.substr(pos + 4));
    }        
}



