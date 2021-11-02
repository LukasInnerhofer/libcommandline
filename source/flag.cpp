#include "libcommandline/flag.h"

namespace LibCommandLine
{

Flag::Flag(char identifier) :
    Option{identifier},
    m_set{false}
{

}

void Flag::parse(Args &args)
{
    m_set = true;
}

Flag::operator bool() const
{
    return m_set;
}

}