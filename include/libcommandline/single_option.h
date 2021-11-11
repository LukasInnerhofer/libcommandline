#pragma once

#include <iostream>

#include "libcommandline/option_with_argument.h"

namespace LibCommandLine
{

class SingleOption : public OptionWithArgument
{
public:
    SingleOption(
        char identifier,
        std::string_view argumentName = "argument",
        Necessity necessity = Necessity::Optional);
    SingleOption(
        char identifier, 
        Necessity necessity = Necessity::Optional);

    void parse(Args &args, Badge<Parser>) override;
    void validate(Badge<Parser>) override;
    void printHelp(std::ostream &stream) override;

    std::string_view getArgument() const;

private:
    Necessity m_necessity;
    std::string_view m_argument;
};

}