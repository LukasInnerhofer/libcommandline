#include "libcommandline/args.h"

namespace LibCommandLine
{

Args::Args(int argc, char const *argv[]) :
        m_iterator{1},
        m_argc{argc}, 
        m_argv{argv}
{
}

std::string_view Args::get(size_t offset) const
{
    if (m_iterator + offset >= m_argc)
    {
        return {};
    }
    return m_argv[m_iterator + offset];
}

void Args::next()
{
    ++m_iterator;
}

bool Args::last() const
{
    return m_iterator == m_argc - 1;
}

bool Args::end() const
{
    return m_iterator >= m_argc;
}

}