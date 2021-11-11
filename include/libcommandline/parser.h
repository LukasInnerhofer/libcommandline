#pragma once

#include <vector>

#include "libcommandline/option.h"
#include "libcommandline/flag.h"
#include "libutilities/concepts.h"
#include "libutilities/non_null.h"

namespace LibCommandLine
{

class Option;
class Flag;

class Parser
{
public:
    enum class ExpectedOperands { One, AtLeastOne, OneOptional, ManyOptional, None };

    Parser(
        std::vector<NonNullSharedPtr<Option>> &&options,
        ExpectedOperands expectedOperands,
        std::string_view operandName);

    void parse(int argc, char const *argv[]);
    void printHelp(std::ostream &stream);

    NonNullSharedPtr<std::vector<std::string_view>> getOperands();
    NonNullSharedPtr<Flag> getHelpFlag();

private:
    void validateOperands();
    void printOperands(std::ostream &);

    std::string_view m_executable;
    std::vector<NonNullSharedPtr<Option>> m_options;
    NonNullSharedPtr<std::vector<std::string_view>> m_operands;
    std::string_view m_operandName;
    ExpectedOperands m_expectedOperands;
    NonNullSharedPtr<Flag> m_helpFlag;
};

}