#include "libcommandline/multi_option.h"
#include <type_traits>

namespace LibCommandLine
{

MultiOption::MultiOption(char identifier, Necessity necessity) : 
    OptionWithArgument{identifier},
    m_necessity{necessity},
    m_arguments{}
{
}

void MultiOption::parse(Args &args, Badge<Parser>)
{
    m_arguments.push_back(parseArgument(args));
}

void MultiOption::validate(Badge<Parser>)
{
    if (m_necessity == Necessity::Required && m_arguments.empty())
    {
        throw std::runtime_error{"LibCommandLine error. Missing required multi-option -" + std::string{m_identifier}};
    }
}

std::vector<std::string_view> const &MultiOption::getArguments() const
{
    return m_arguments;
}

}