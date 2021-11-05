#pragma once

#include "libcommandline/args.h"
#include "libcommandline/option.h"

namespace LibCommandLine
{

class Flag : public Option
{
public:
    Flag(char identifier);

    void parse(Args &args, Badge<Parser>) override;
    void validate(Badge<Parser>) override {};

    operator bool() const;

private:
    bool m_set;
};

}