#include "storage.ih"

string Storage::simplify(string const &symbol)
{
    string ret = symbol;

    for (auto pair: d_simplify)
    {
        size_t pos = ret.length();
        size_t length = pair.first.length();

        while (true)
        {
            pos = ret.rfind(pair.first, pos);
            if (pos == string::npos)
                break;
            ret.replace(pos, length, pair.second);
        }
    }
    return ret;
}
