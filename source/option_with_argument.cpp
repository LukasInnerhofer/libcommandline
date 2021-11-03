#include "libcommandline/option_with_argument.h"

namespace LibCommandLine
{

OptionWithArgument::OptionWithArgument(char identifier) :
    Option{identifier}
{
}

std::string_view OptionWithArgument::parseArgument(Args &args)
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
    args.next();
    return string;
}

}