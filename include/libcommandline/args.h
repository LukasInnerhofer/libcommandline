#pragma once

#include <string_view>

namespace LibCommandLine
{

class Args
{
public:
    Args(int argc, char const *argv[]);

    std::string_view get() const;
    void next();
    bool end() const;

private:
    int m_argc;
    int m_iterator;
    char const **m_argv;
};

}