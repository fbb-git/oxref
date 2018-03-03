#include "storage.ih"

void Storage::push_back(string const &line)
{
    if (s_reject << line)
        return;

    if (s_objFile << line)      // 1st line of a record, like 
        objFile(s_objFile[1]);  //      tmp/main.o:  file format ...

    else if (s_abs << line)     // the source filename (if available)
        sourceFile(s_abs[1]);

    else if (s_UND << line)     // *UND* entries are stored in 
        undefined(s_UND[1]);    // Store::d_xrefData: entities referred to by
                                // the current function

    else if (s_g_F << line)     // 'g   F .text' entries define symbols
        function(s_g_F[1]);     // in d_xrefData

    else if (s_g_O << line)     // 'g   O .data' entries  define global data
        object(s_g_O[1]);       // in d_xrefData
}




