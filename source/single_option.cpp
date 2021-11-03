#include "libcommandline/single_option.h"
#include "libcommandline/option_with_argument.h"

namespace LibCommandLine
{

SingleOption::SingleOption(char identifier) : 
    OptionWithArgument{identifier},
    m_argument{}
{
}

void SingleOption::parse(Args &args, Badge<Parser>)
{
    m_argument = parseArgument(args);
}

std::string_view SingleOption::getArgument() const
{
    return m_argument;
}

}