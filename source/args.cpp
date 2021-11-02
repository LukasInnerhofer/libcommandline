#include "libcommandline/args.h"

namespace LibCommandLine
{

Args::Args(int argc, char const *argv[]) :
        m_iterator{1},
        m_argc{argc}, 
        m_argv{argv}
{
}

std::string_view Args::peek() const
{
    return m_argv[m_iterator];
}

void Args::next()
{
    ++m_iterator;
}

bool Args::done() const
{
    return m_iterator >= m_argc;
}

}