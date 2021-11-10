#include "libcommandline/args.h"

namespace LibCommandLine
{

Args::Args(int argc, char const *argv[]) :
        m_iterator{0},
        m_argc{argc}, 
        m_argv{argv}
{
}

std::string_view Args::get() const
{
    if (m_iterator >= m_argc)
    {
        return {};
    }
    return m_argv[m_iterator];
}

void Args::next()
{
    ++m_iterator;
}

bool Args::end() const
{
    return m_iterator >= m_argc;
}

}