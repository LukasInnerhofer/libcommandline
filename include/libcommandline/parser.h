#pragma once

#include <vector>

#include "libcommandline/option.h"
#include "libcommandline/flag.h"
#include "libutilities/non_null.h"

namespace LibCommandLine
{

class Option;
class Flag;

class Parser
{
public:
    enum class ExpectedOperands { One, AtLeastOne, OneOptional, ManyOptional, None };

    static void addOption(NonNullSharedPtr<Option> newOption);
    static void expectOperands(ExpectedOperands expectedOperands);
    static void parse(int argc, char const *argv[]);
    static void printHelp(std::ostream &stream);

    static NonNullSharedPtr<std::vector<std::string_view>> getOperands();
    static NonNullSharedPtr<Flag> getHelpFlag();

private:
    static void validateOperands(); 

    static std::string_view m_executable;
    static std::vector<NonNullSharedPtr<Option>> m_options;
    static NonNullSharedPtr<std::vector<std::string_view>> m_operands;
    static ExpectedOperands m_expectedOperands;
    static NonNullSharedPtr<Flag> m_helpFlag;
};

}