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
    enum class ExpectedOperands { One, AtLeastOne, OneOptional, ManyOptional, None };

    static void addOption(NonNullSharedPtr<Option> newOption);
    static void expectOperands(ExpectedOperands expectedOperands);
    static void parse(int argc, char const *argv[]);
    static std::vector<std::string_view> const &getOperands();

private:
    static void validateOperands(); 

    static std::vector<NonNullSharedPtr<Option>> m_options;
    static std::vector<std::string_view> m_operands;
    static ExpectedOperands m_expectedOperands;
};

}