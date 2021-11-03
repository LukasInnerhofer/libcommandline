#pragma once

#include "libcommandline/option_with_argument.h"

namespace LibCommandLine
{

class MultiOption : public OptionWithArgument
{
public:
    MultiOption(char identifier);

    void parse(Args &args, Badge<Parser>) override;
    std::vector<std::string_view> const &getArguments() const;

private:
    std::vector<std::string_view> m_arguments;
};

}