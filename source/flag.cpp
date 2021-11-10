#include "libcommandline/flag.h"

namespace LibCommandLine
{

Flag::Flag(char identifier) :
    Option{identifier},
    m_set{false}
{

}

void Flag::parse(Args &args, Badge<Parser>)
{
    args.next();
    m_set = true;
}

void Flag::printHelp(std::ostream &stream)
{
    stream << " -" << m_identifier;
}

Flag::operator bool() const
{
    return m_set;
}

}