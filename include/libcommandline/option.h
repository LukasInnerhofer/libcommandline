#pragma once

#include <string_view>

namespace LibCommandLine
{

class Option
{
public:
    Option(char identifier);
    virtual ~Option() = 0;

    char getIdentifier() const;
    virtual void parse(std::string_view string) = 0;

private:
    char m_identifier;
};

}