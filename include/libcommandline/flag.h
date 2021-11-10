#pragma once

#include <iostream>

#include "libcommandline/args.h"
#include "libcommandline/option.h"

namespace LibCommandLine
{

class Parser;

class Flag : public Option
{
public:
    Flag(char identifier);

    void parse(Args &args, Badge<Parser>) override;
    void validate(Badge<Parser>) override {};
    void printHelp(std::ostream &stream) override;

    operator bool() const;

private:
    bool m_set;
};

}