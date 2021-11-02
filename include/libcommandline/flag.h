#pragma once

#include "libcommandline/args.h"
#include "libcommandline/option.h"

namespace LibCommandLine
{

class Flag : public Option
{
public:
    Flag(char identifier);

    void parse(Args &args) override;

    operator bool() const;

private:
    bool m_set;
};

}