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
    std::string d_cooked;               // name as processed by -a

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
   
        bool isDefined(std::string const &symbol) const;
        bool hasSymbol(std::string const &symbol) const;
    
        void calledFrom(size_t currentIdx);

        void defined(std::ostream &out) const;
        std::string const &symbol() const;// returns d_cooked
        char const *name() const;         // returns d_cooked[d_nameIndex] 

        std::string const &sourceFile() const;

        std::vector<size_t> const &usedBy() const;

    private:
        void ctor();
        void setCooked();
        void keepFirst(size_t openParIdx);
        void reduceLen(size_t openParIdx, size_t len);
        void reduceToCount(size_t openParIdx, size_t end);
        size_t skipTemplate(size_t begin) const;    // index of 1st '<'
                                                    // returns idx of last '>'

        size_t eraseParam(size_t begin);    // returns , or ) position
        size_t eraseParam(size_t begin, size_t len);
};

inline std::vector<size_t> const &XrefData::usedBy() const
{
    return d_calledFrom;
}

inline  char const *XrefData::name() const
{
    return d_cooked.c_str() + d_nameIndex;
}

inline std::string const &XrefData::sourceFile() const
{
    return d_sourceFile;
}

inline  std::string const &XrefData::symbol() const
{
    return d_cooked;
}

#endif
