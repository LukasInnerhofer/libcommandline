#include <stdexcept>
#include <string>

#include "libcommandline/args.h"
#include "libcommandline/parser.h"
#include "libutilities/non_null.h"

namespace LibCommandLine
{

std::vector<NonNullSharedPtr<Option>> Parser::m_options;
std::vector<std::string_view> Parser::m_operands;
Parser::ExpectedOperands Parser::m_expectedOperands{Parser::ExpectedOperands::ManyOptional};

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
    auto args{Args{argc, argv}};

    while (!args.end())
    {
        if (args.get()[0] != '-')
        {
            m_operands.push_back(args.get());
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

    validateOperands();
    for (auto option : m_options)
    {
        option->validate(Badge<Parser>{});
    }
}

std::vector<std::string_view> const &Parser::getOperands()
{
    return m_operands;
}

void Parser::validateOperands()
{
    size_t const nOperands{m_operands.size()};
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