#ifndef INCLUDED_STORE_
#define INCLUDED_STORE_

#include <iosfwd>
#include <string>
#include <vector>
#include <unordered_map>

#include "../xrefdata/xrefdata.h"

namespace FBB
{
    class Pattern;
}

class Store
{
    friend std::ostream &operator<<(std::ostream &out, Store const &store);

    size_t d_currentIdx;
    std::string d_sourceFile;
    std::string d_objFile;
    std::string d_symbol;

    typedef std::vector<XrefData> XrefVector;

    XrefVector d_xrefData;
    mutable std::vector<size_t> d_defIdx;       // indices of defined 
                                                // functions/objects

//                                            // index in d_xrefData where
//                                            // a symbol is stored
//    std::unordered_map<std::string, size_t> d_symbolMap;

    public:
        Store();

        void setSource(std::string const &fname);
        void setObjfile(std::string const &fname);

        void setFunction(std::string const &function);
        void setObject(std::string const &object);
        void undefined(std::string const &symbol);

    private:
        void define(std::string const &symbol, bool isFunction);
        std::ostream &insertInto(std::ostream &out) const;
        void insert(std::ostream &out, std::string const &name, 
                                                        bool doSelect) const;

        static void insertDefined(size_t idx, std::ostream &out, 
                                  XrefVector const &xref);
        static void usedBy(size_t idx, std::ostream &out, 
                                  XrefVector const &xref);
};

inline std::ostream &operator<<(std::ostream &out, Store const &store)
{
    return store.insertInto(out);   
}
        
#endif





