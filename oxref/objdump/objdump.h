#ifndef INCLUDED_OBJDUMP_
#define INCLUDED_OBJDUMP_

#include <iterator>
#include <bobcat/process>

class ObjDump
{
    FBB::Process d_process;

    public:
        class const_iterator;

        const_iterator begin();
        const_iterator end();

        class const_iterator: 
                public std::iterator<std::input_iterator_tag, std::string>
        {
            friend const_iterator ObjDump::begin();
            friend const_iterator ObjDump::end();

            FBB::Process *d_process;

            mutable bool d_iterate;
            mutable std::string d_line;

            const_iterator(FBB::Process *process, bool iterate);

            public:
                const_iterator &operator++();
                bool operator==(const_iterator const &other) const;
                bool operator!=(const_iterator const &other) const;
                std::string const &operator*() const;
                std::string const *operator->() const;
        };

        ObjDump();
        void start();

    private:
        static void addObject(std::string const &arg, FBB::Process &process);
};

inline void ObjDump::start()
{
    d_process.start();
}

inline ObjDump::const_iterator ObjDump::begin()
{
    return const_iterator(&d_process, true);
}

inline ObjDump::const_iterator ObjDump::end()
{
    return const_iterator(&d_process, false);
}

inline bool ObjDump::const_iterator::operator!=(const_iterator const &rhs)
                                                                        const
{
    return not (*this == rhs);
}

inline std::string const &ObjDump::const_iterator::operator*() const
{
    return d_line;
}

inline std::string const *ObjDump::const_iterator::operator->() const
{
    return &d_line;
}

        
#endif
