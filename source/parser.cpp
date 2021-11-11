#include <iostream>
#include <filesystem>
#include <stdexcept>
#include <string>

#include "libcommandline/args.h"
#include "libcommandline/parser.h"
#include "libutilities/non_null.h"

namespace LibCommandLine
{

Parser::Parser(
    std::vector<NonNullSharedPtr<Option>> &&options,
    ExpectedOperands expectedOperands,
    std::string_view operandName) :
    m_executable{},
    m_options{std::move(options)},
    m_operands{makeNonNullShared<std::vector<std::string_view>>()},
    m_operandName{operandName},
    m_expectedOperands{expectedOperands},
    m_helpFlag{makeNonNullShared<Flag>('h')}
{
    m_options.push_back(m_helpFlag);
}

void Parser::parse(int argc, char const *argv[])
{
    Args args{argc, argv};

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
    stream << "Usage:\n" << m_executable;
    for (auto option : m_options)
    {
        option->printHelp(stream);
    }
    stream << " ";
    printOperands(stream);
    stream << "\n";
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
            message = "Expected 1 operand ";
        }
        break;
    case ExpectedOperands::AtLeastOne:
        if (nOperands == 0)
        {
            message = "Expected at least 1 operand ";
        }
        break;
    case ExpectedOperands::ManyOptional:
        break;
    case ExpectedOperands::OneOptional:
        if (nOperands > 1)
        {
            message = "Expected 1 optional operand ";
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

void Parser::printOperands(std::ostream &stream)
{
    switch (m_expectedOperands)
    {
    case ExpectedOperands::AtLeastOne:
        stream << "<" << m_operandName << "> ...";
        break;
    case ExpectedOperands::ManyOptional:
        stream << "[<" << m_operandName << "> ...]";
        break;
    case ExpectedOperands::One:
        stream << "<" << m_operandName << ">";
        break;
    case ExpectedOperands::OneOptional:
        stream << "[<" << m_operandName << ">]";
        break;
    default:
        break;
    }
}

}