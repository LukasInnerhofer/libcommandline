#include "libcommandline/option.h"

namespace LibCommandLine
{

Option::Option(char identifier) : m_identifier{identifier}
{

}

char Option::getIdentifier() const
{
    return m_identifier;
}

}