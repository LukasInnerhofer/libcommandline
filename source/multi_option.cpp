#include "libcommandline/multi_option.h"

namespace LibCommandLine
{

MultiOption::MultiOption(char identifier) : 
    Option{identifier},
    m_arguments{}
{
}

void MultiOption::parse(Args &args, Badge<Parser>)
{
    auto string{args.get()};
    if (string.size() == 2)
    {
        args.next();
        string = args.get();
    }
    else 
    {
        string = string.substr(2);
        string = string.substr(string.find_first_not_of(" \t"));    
    }
    m_arguments.push_back(string);
    args.next();
}

std::vector<std::string_view> const &MultiOption::getArguments() const
{
    return m_arguments;
}

}