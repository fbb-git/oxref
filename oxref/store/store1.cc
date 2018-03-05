#include "store.ih"

Store::Store()
:
    d_noData(Arg::instance().option(0, "no-data")),
    d_dontRepeat(Arg::instance().option(0, "dont-repeat"))
{}
