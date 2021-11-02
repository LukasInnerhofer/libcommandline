#include "libcommandline/flag.h"

namespace LibCommandLine
{

Flag::Flag(char identifier) :
    Option{identifier},
    m_set{false}
{

}

void Flag::parse(std::string_view string)
{
    m_set = true;
}

Flag::operator bool() const
{
    return m_set;
}

}