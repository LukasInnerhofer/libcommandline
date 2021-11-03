#include "libcommandline/args.h"
#include "libcommandline/parser.h"
#include "libutilities/non_null.h"

namespace LibCommandLine
{

std::vector<NonNullSharedPtr<Option>> Parser::m_options;

void Parser::addOption(NonNullSharedPtr<Option> newOption)
{
    for (auto option : m_options)
    {
        if (option->getIdentifier() == newOption->getIdentifier())
        {
            return;
        }
    }
    m_options.push_back(newOption);
}

void Parser::parse(int argc, char const *argv[])
{
    auto args{Args{argc, argv}};

    while (!args.end())
    {
        if (args.get()[0] != '-')
        {
            // TODO
            args.next();
            continue;
        }
        for (auto option : m_options)
        {
            if (args.get()[1] == option->getIdentifier())
            {
                option->parse(args, Badge<Parser>{});
                break;
            }
        }
    }
}

}