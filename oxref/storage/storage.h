#ifndef INCLUDED_STORAGE_
#define INCLUDED_STORAGE_

#include <iosfwd>
#include <string>

#include <bobcat/pattern>

#include "../store/store.h"

class Storage
{
    friend std::ostream &operator<<(std::ostream &out, 
                                    Storage const &storage);
    static FBB::Pattern s_reject;
    static FBB::Pattern s_objFile;
    static FBB::Pattern s_abs;
    static FBB::Pattern s_UND;
    static FBB::Pattern s_g_F;
    static FBB::Pattern s_g_O;

    Store d_store;

    public:
        typedef std::string value_type;
        typedef value_type const &const_reference;

        Storage();
        void push_back(std::string const &line);

    private:
        void function(std::string const &symbol);    
        void objFile(std::string const &fname);
        void sourceFile(std::string const &fname);
        void undefined(std::string const &symbol);
        void object(std::string const &symbol);
};

inline std::ostream &operator<<(std::ostream &out, Storage const &storage)
{
    return out << storage.d_store;
}

#endif
