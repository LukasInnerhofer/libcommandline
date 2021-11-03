#pragma once

#include <vector>

#include "libcommandline/option.h"
#include "libutilities/non_null.h"

namespace LibCommandLine
{

class Option;

class Parser
{
public:
    static void addOption(NonNullSharedPtr<Option> newOption);
    static void parse(int argc, char const *argv[]);

private:
    static std::vector<NonNullSharedPtr<Option>> m_options;
};

}