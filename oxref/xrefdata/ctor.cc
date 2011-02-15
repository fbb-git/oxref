#include "xrefdata.ih"

void XrefData::ctor()
{
    Arg &arg = Arg::instance();

    d_source = arg.option('s');
    d_object = arg.option('o');
    d_fullSymbol = arg.option('f');

    d_nameIndex = d_refName.find('(');  // find 1st opening '('

    if (d_nameIndex == string::npos)        // not found: search fm the end
        d_nameIndex = d_refName.length();

    d_nameIndex = d_refName.rfind(':', d_nameIndex);   // find SRO
    d_nameIndex = 
        d_nameIndex == string::npos ?   // none found: use full d_refName
            0
        :
            d_nameIndex + 1;            // otherwise: d_refName starts beyond :
}


