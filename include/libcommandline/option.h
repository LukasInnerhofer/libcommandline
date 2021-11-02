#pragma once

#include <string_view>

#include "libcommandline/args.h"

namespace LibCommandLine
{

class Option
{
public:
    Option(char identifier);
    virtual ~Option() = default;

    char getIdentifier() const;
    virtual void parse(Args &args) = 0;

private:
    char m_identifier;
};

}