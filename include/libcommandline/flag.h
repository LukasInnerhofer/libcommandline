#pragma once

#include "libcommandline/option.h"

namespace LibCommandLine
{

class Flag : public Option
{
public:
    Flag(char identifier);

    void parse(std::string_view string) override;

    operator bool() const;

private:
    bool m_set;
};

}