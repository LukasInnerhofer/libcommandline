#pragma once

#include <string_view>

namespace LibCommandLine
{

class Option
{
public:
    Option(char identifier);
    virtual ~Option() = default;

    char getIdentifier() const;
    virtual void parse(std::string_view string) = 0;

private:
    char m_identifier;
};

}