#ifndef INCLUDED_XREFDATA_
#define INCLUDED_XREFDATA_

#include <iostream>
#include <string>
#include <vector>

class XrefData
{
    std::string d_sourceFile;           // defined, unless empty
    std::string d_objFile;

    bool d_isFunction;                  // true: function, false: object

    std::string d_refName;              // full name of object or function

    size_t d_nameIndex;                 // index where the proper name (after
                                        // its class/namespace) starts

    std::vector<size_t> d_calledFrom;

    bool d_source;
    bool d_object;
    bool d_fullSymbol;

    public:
        XrefData();
        XrefData(std::string const &sourceFile, 
                 std::string const &objFile, 
                 bool isFunction, std::string const &symbol);
        XrefData(std::string const &symbol);

        void setLocation(std::string const &sourceFile, 
                 std::string const &objFile);
   
        static bool isDefined(XrefData const &data, 
                              std::string const &symbol);
        static bool hasSymbol(XrefData const &data, 
                              std::string const &symbol);
    
        void calledFrom(size_t currentIdx);

        void defined(std::ostream &out) const;
        std::string const &symbol() const;      // returns d_refName
        char const *name() const;
        std::string const &sourceFile() const;

        std::vector<size_t> const &usedBy() const;

    private:
        void ctor();
};

inline std::vector<size_t> const &XrefData::usedBy() const
{
    return d_calledFrom;
}

inline  std::string const &XrefData::symbol() const
{
    return d_refName;
}

inline  char const *XrefData::name() const
{
    return d_refName.c_str() + d_nameIndex;
}

inline std::string const &XrefData::sourceFile() const
{
    return d_sourceFile;
}

#endif





