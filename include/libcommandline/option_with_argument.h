#pragma once

#include "libcommandline/option.h"

namespace LibCommandLine
{

class OptionWithArgument : public Option
{
protected:
    OptionWithArgument(
        char identifier,
        std::string_view argumentName = "argument");
    std::string_view parseArgument(Args &args);

    std::string_view m_argumentName;
};

}