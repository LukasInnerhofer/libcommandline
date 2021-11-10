#pragma once

#include <vector>

#include "libcommandline/option_with_argument.h"

namespace LibCommandLine
{

class MultiOption : public OptionWithArgument
{
public:
    MultiOption(char identifier, Necessity necessity = Necessity::Optional);

    void parse(Args &args, Badge<Parser>) override;
    void validate(Badge<Parser>) override;
    void printHelp(std::ostream &stream) override;

    std::vector<std::string_view> const &getArguments() const;

private:
    Necessity m_necessity;
    std::vector<std::string_view> m_arguments;
};

}