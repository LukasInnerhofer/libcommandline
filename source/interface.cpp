#include <vector>

#include "libcommandline/interface.h"
#include "libutilities/non_null.h"

namespace LibCommandLine
{

std::vector<NonNullSharedPtr<Option>> options;

void addOption(NonNullSharedPtr<Option> option)
{
    options.push_back(option);
}

void parse(std::string_view string)
{
    decltype(string)::size_type optionOffset;
    while ((optionOffset = string.find(" -") + 2) < string.size())
    {
        for (auto option : options)
        {
            if (string.at(optionOffset) == option->getIdentifier())
            {
                option->parse(string.substr(optionOffset));
            }
        }
    }
}

}