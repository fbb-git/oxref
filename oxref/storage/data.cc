#include "storage.ih"

Pattern Storage::s_reject
(
    "^.*\\*UND\\*\\s+\\d+\\s+_"
    "|"
    "vtable for"
    "|"
    "typeinfo for"
    "|"
    "virtual thunk to"
);

Pattern Storage::s_objFile("^(.*):\\s+file format");
Pattern Storage::s_abs("^.*\\*ABS\\*\\s+[[:alnum:]]+\\s(.*)");

    // 00000000         *UND*  00000000 std::ios_base::Init::Init()
Pattern Storage::s_UND("^[[:alnum:]]+\\s+\\*UND\\*\\s+[[:alnum:]]+\\s(.*)");

    // 00000090 g     F .text  0000047f main
    // 00000090 g     F .text  00000165 usage(std::string const&)
Pattern Storage::s_g_F(
            "^[[:alnum:]]+\\s+g\\s+F\\s+\\S+\\s+[[:alnum:]]+\\s(.*)");

    // 00000000 g     O .data  00000008 Icmbuild::version
Pattern Storage::s_g_O(
            "^[[:alnum:]]+\\s+g\\s+O\\s+\\S+\\s+[[:alnum:]]+\\s(.*)");


