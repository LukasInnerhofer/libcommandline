#include <stdexcept>

#include "libcommandline/single_option.h"
#include "libcommandline/option_with_argument.h"
#include "libutilities/badge.h"

namespace LibCommandLine
{

SingleOption::SingleOption(char identifier, Necessity necessity) : 
    OptionWithArgument{identifier},
    m_necessity{necessity},
    m_argument{}
{
}

void SingleOption::parse(Args &args, Badge<Parser>)
{
    m_argument = parseArgument(args);
}

void SingleOption::validate(Badge<Parser>)
{
    if (m_necessity == Necessity::Required && m_argument.empty())
    {
        throw std::runtime_error{"LibCommandLine error. Missing required single option -" + std::string{m_identifier}};
    }
}

void SingleOption::printHelp(std::ostream &stream)
{
    const bool optional{m_necessity == Necessity::Optional};
    stream << " ";
    if (optional)
    {
        stream << "[";
    }
    stream << "-" << m_identifier << " value"; // Print something more useful than 'value'
    if (optional)
    {
        stream << "]";
    }
}

std::string_view SingleOption::getArgument() const
{
    return m_argument;
}

}