#pragma once

#include "libcommandline/option_with_argument.h"

namespace LibCommandLine
{

class SingleOption : public OptionWithArgument
{
public:
    SingleOption(char identifier);

    void parse(Args &args, Badge<Parser>) override;
    std::string_view getArgument() const;

private:
    std::string_view m_argument;
};

}