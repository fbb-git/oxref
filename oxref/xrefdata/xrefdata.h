#ifndef INCLUDED_XREFDATA_
#define INCLUDED_XREFDATA_

#include <iostream>
#include <string>
#include <vector>

class XrefData
{
    std::string d_refName;              // full name of object or function

    size_t d_nameIndex = 0;             // index where the entity's proper
                                        // name (beyond its class/namespace
                                        // specification) starts  

    std::string d_cooked;               // name as processed by the -a option

    std::string d_sourceFile;           // d_refName's definition is
                                        // available, otherwise (if empty)
                                        // d_refName is referred to, but its
                                        // definition record is not available
                                        // from objdump's output. 

    std::string d_objFile;              // name of the objfile containing
                                        // d_refName

    bool d_isFunction = false;          // true: function, false: object

    std::vector<size_t> d_calledFrom;   // Indices in Store's d_xrefData
                                        // vector of entities that call the
                                        // current entity

    std::vector<size_t> d_calls;        // indices in d_xrefData of entities
                                        // called by the current entity

    bool d_source = false;
    bool d_object = false;
    bool d_fullSymbol;

    size_t d_lineNr = 0;                // used with call trees (to determine
                                        // whether an entrie has already been
                                        // reported)
    public:

        XrefData(std::string const &sourceFile,             // 2
                 std::string const &objFile, 
                 bool isFunction, std::string const &symbol);
        XrefData(std::string const &symbol);                // 3

        void setOrigin(std::string const &sourceFile, 
                 std::string const &objFile, bool isFunction);

        bool complete() const;
        bool isFunction() const;
        bool hasSymbol(std::string const &symbol) const;
    
        void calledFrom(size_t currentIdx);

        void calls(size_t idx);
        std::vector<size_t> const &calls() const;

        void defined(std::ostream &out) const;
        std::string const &symbol() const;  // returns d_cooked
        char const *name() const;           // returns d_cooked[d_nameIndex] 

        std::string const &sourceFile() const;

        std::vector<size_t> const &usedBy() const;

        void lineNr(size_t nr);             // sets d_lineNr
        size_t lineNr() const;              // returns it.

    private:
        void init();
        void setCooked();
        void keepFirst(size_t openParIdx);
        void reduceLen(size_t openParIdx, size_t len);
        void reduceToCount(size_t openParIdx, size_t end);
        size_t skipTemplate(size_t begin) const;    // index of 1st '<'
                                                    // returns idx of last '>'

        size_t eraseParam(size_t begin);    // returns , or ) position
        size_t eraseParam(size_t begin, size_t len);
};

inline size_t XrefData::lineNr() const
{
    return d_lineNr;
}

inline void XrefData::lineNr(size_t lineNr) 
{
    d_lineNr = lineNr;
}

inline std::vector<size_t> const &XrefData::calls() const
{
    return d_calls;
}

inline bool XrefData::complete() const
{
    return not d_sourceFile.empty();
}

inline bool XrefData::isFunction() const
{
    return d_isFunction;
}

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
