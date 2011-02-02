#include "storage.ih"

void Storage::push_back(string const &line)
{
    if (s_reject << line)
        return;

    if (s_objFile << line)
        objFile(s_objFile[1]);

    else if (s_abs << line)
        sourceFile(s_abs[1]);

    else if (s_UND << line)
        undefined(s_UND[1]);

    else if (s_g_F << line)
        function(s_g_F[1]);

    else if (s_g_O << line)
        object(s_g_O[1]);
}




