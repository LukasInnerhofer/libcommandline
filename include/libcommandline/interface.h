#pragma once

#include "libcommandline/option.h"
#include "libutilities/non_null.h"

namespace LibCommandLine
{

void addOption(NonNullSharedPtr<Option> newOption);
void parse(int argc, char const *argv[]);

}