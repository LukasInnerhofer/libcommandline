#pragma once

#include "libcommandline/option.h"
#include "libutilities/non_null.h"

namespace LibCommandLine
{

void addOption(NonNullSharedPtr<Option> option);
void parse(std::string_view arguments);

}