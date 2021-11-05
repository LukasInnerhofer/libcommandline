#pragma once

#include <string_view>

#include "libcommandline/args.h"
#include "libcommandline/parser.h"
#include "libutilities/badge.h"

namespace LibCommandLine
{

class Parser;

class Option
{
public:
    enum class Necessity{Optional, Required};

    Option(char identifier);
    virtual ~Option() = default;

    char getIdentifier() const;
    virtual void parse(Args &args, Badge<Parser>) = 0;
    virtual void validate(Badge<Parser>) = 0;

protected:
    char m_identifier;
};

}