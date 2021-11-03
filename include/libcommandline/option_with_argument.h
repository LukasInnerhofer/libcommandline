#pragma once

#include "libcommandline/option.h"

namespace LibCommandLine
{

class OptionWithArgument : public Option
{
protected:
    OptionWithArgument(char identifier);
    std::string_view parseArgument(Args &args);
};

}