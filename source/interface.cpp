#include <vector>
#include <iostream>

#include "libcommandline/args.h"
#include "libcommandline/interface.h"
#include "libutilities/non_null.h"

namespace LibCommandLine
{

std::vector<NonNullSharedPtr<Option>> options;

void addOption(NonNullSharedPtr<Option> newOption)
{
    for (auto option : options)
    {
        if (option->getIdentifier() == newOption->getIdentifier())
        {
            return;
        }
    }
    options.push_back(newOption);
}

void parse(int argc, char const *argv[])
{
    auto args{Args{argc, argv}};

    while (!args.done())
    {
        if (args.peek()[0] != '-')
        {
            // TODO
            args.next();
            continue;
        }
        for (auto option : options)
        {
            if (args.peek()[1] == option->getIdentifier())
            {
                option->parse(args);
                break;
            }
        }
        args.next();
    }
}

}