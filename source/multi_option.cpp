#include "libcommandline/multi_option.h"

namespace LibCommandLine
{

MultiOption::MultiOption(char identifier) : 
    OptionWithArgument{identifier},
    m_arguments{}
{
}

void MultiOption::parse(Args &args, Badge<Parser>)
{
    m_arguments.push_back(parseArgument(args));
}

std::vector<std::string_view> const &MultiOption::getArguments() const
{
    return m_arguments;
}

}