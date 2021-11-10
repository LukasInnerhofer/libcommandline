#include <iostream>
#include <filesystem>
#include <stdexcept>
#include <string>

#include "libcommandline/args.h"
#include "libcommandline/parser.h"
#include "libutilities/non_null.h"

namespace LibCommandLine
{

std::string_view Parser::m_executable;
std::vector<NonNullSharedPtr<Option>> Parser::m_options;
NonNullSharedPtr<std::vector<std::string_view>> Parser::m_operands{makeNonNullShared<std::vector<std::string_view>>()};
Parser::ExpectedOperands Parser::m_expectedOperands{Parser::ExpectedOperands::ManyOptional};
NonNullSharedPtr<Flag> Parser::m_helpFlag{makeNonNullShared<Flag>('h')};

void Parser::addOption(NonNullSharedPtr<Option> newOption)
{
    for (auto option : m_options)
    {
        if (option->getIdentifier() == newOption->getIdentifier())
        {
            return;
        }
    }
    m_options.push_back(newOption);
}

void Parser::expectOperands(ExpectedOperands expectedOperands)
{
    m_expectedOperands = expectedOperands;
}

void Parser::parse(int argc, char const *argv[])
{
    Args args{argc, argv};

    addOption(m_helpFlag);

    std::string_view arg{args.get()};
    m_executable = arg.substr(arg.find_last_of("\\/") + 1);
    args.next();

    while (!args.end())
    {
        arg = args.get();
        if (arg[0] != '-')
        {
            m_operands->push_back(arg);
            args.next();
            continue;
        }
        for (auto option : m_options)
        {
            if (args.get()[1] == option->getIdentifier())
            {
                option->parse(args, Badge<Parser>{});
                break;
            }
        }
    }

    if (*m_helpFlag)
    {
        printHelp(std::cout);
        return;
    }

    validateOperands();
    for (auto option : m_options)
    {
        option->validate(Badge<Parser>{});
    }
}

void Parser::printHelp(std::ostream &stream)
{
    stream << m_executable;
    /*for (auto option : m_options)
    {
        option->printHelp(stream);
    }*/
}

NonNullSharedPtr<std::vector<std::string_view>> Parser::getOperands()
{
    return m_operands;
}

NonNullSharedPtr<Flag> Parser::getHelpFlag()
{
    return m_helpFlag;
}

void Parser::validateOperands()
{
    size_t const nOperands{m_operands->size()};
    std::string message;
    switch(m_expectedOperands)
    {
    case ExpectedOperands::One:
        if (nOperands != 1)
        {
            message = "Expected one operand ";
        }
        break;
    case ExpectedOperands::AtLeastOne:
        if (nOperands == 0)
        {
            message = "Expected at least one operand ";
        }
        break;
    case ExpectedOperands::ManyOptional:
        break;
    case ExpectedOperands::OneOptional:
        if (nOperands > 1)
        {
            message = "Expected one optional operand ";
        }
        break;
    case ExpectedOperands::None:
        if (nOperands > 0)
        {
            message = "Expected no operands ";
        }
        break;
    }
    if (!message.empty())
    {
        message += "but received " + std::to_string(nOperands);
        throw std::runtime_error{message};
    }
}

}