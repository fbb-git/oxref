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

    std::string d_objFile;

    std::string d_sourceFile;

    std::string d_symbol;
    size_t d_functionIdx;                   // index in d_xrefData holding
                                            // the current function record:
                                            // UND entities are called from
                                            // this function.

    typedef std::vector<XrefData *> XrefVector;
    typedef XrefVector::const_iterator const_iterator;

    XrefVector d_xrefData;
                                            // entity name to d_defIdx index 
    typedef std::unordered_map<std::string, size_t> SymbolMap;
    typedef SymbolMap::iterator MapIterator;

    SymbolMap d_symbolMap;
    bool d_noData;                          // used with calltree()    

    public:
        Store();
        ~Store();

        void setSource(std::string const &fname);
        void setObjfile(std::string const &fname);

        void setFunction(std::string const &function);
        void setObject(std::string const &object);

        void undefined(std::string const &symbol);

        void calltree(size_t idx, size_t nestLevel) const;

        bool find(size_t *idxPtr, std::string const &startSymbol) const;

    private:
        void define(std::string const &symbol, bool isFunction);

        std::ostream &insertInto(std::ostream &out);

        std::ostream &insertSelect(std::ostream &out, 
                                   std::string const &name) const;
        std::ostream &insertPattern(std::ostream &out, 
                                   std::string const &name) const;

        XrefData &xrefData(MapIterator const &iter);

        static void insertDefined(std::ostream &out, 
                                  XrefData const *ref, 
                                  XrefVector const &xref);

        static void usedBy(size_t idx, std::ostream &out, 
                                  XrefVector const &xref);
};

inline  XrefData &Store::xrefData(MapIterator const &iter)
{
    return *d_xrefData[iter->second];
}

inline std::ostream &operator<<(std::ostream &out, Store const &store)
{
    return const_cast<Store &>(store).insertInto(out);   
}
        
#endif





