#pragma once

#include "libcommandline/option.h"

namespace LibCommandLine
{

class MultiOption : public Option
{
public:
    MultiOption(char identifier);

    void parse(Args &args, Badge<Parser>) override;
    std::vector<std::string_view> const &getArguments() const;

private:
    std::vector<std::string_view> m_arguments;
};

}