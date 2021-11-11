#include <stdexcept>
#include "libcommandline/multi_option.h"
#include "libcommandline/option_with_argument.h"

namespace LibCommandLine
{

MultiOption::MultiOption(char identifier, Necessity necessity) : 
    OptionWithArgument{identifier},
    m_necessity{necessity},
    m_arguments{}
{
}

MultiOption::MultiOption(
    char identifier,
    std::string_view argumentName,
    Necessity necessity) :
    OptionWithArgument{identifier, argumentName},
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
        throw std::runtime_error{"Missing required multi-option -" + std::string{m_identifier}};
    }
}

void MultiOption::printHelp(std::ostream &stream)
{
    stream << " ";
    if (m_necessity == Necessity::Required)
    {
        print(stream);
        stream << " ";
    }
    stream << "[";
    print(stream);
    stream << "]...";
}

std::vector<std::string_view> const &MultiOption::getArguments() const
{
    return m_arguments;
}

void MultiOption::print(std::ostream &stream) const
{
    stream << "-" << m_identifier << " <" << m_argumentName << ">";
}

}