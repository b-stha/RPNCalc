#include "Nodes.h"
#include "AST.h"

oper::~oper()
{
    delete this -> left;
    delete this -> right;
    left = NULL;
    right = NULL;
}
number::number(double data)
{
    constant = data;
}
std::string number::prefix() const
{
    std::ostringstream stream;
    stream << constant;
    return stream.str();
}
std::string number::postfix() const
{
    std::ostringstream stream;
    stream << constant;
    return stream.str();
}
double number::value() const
{
    return number::constant;
}

double plus::value() const
{
    return (left -> value() + right -> value());
}
std::string plus::prefix() const
{
    std::string output = "+";

    output += ' ' + right -> prefix();
    output += ' ' + left -> prefix();
    return output;
}
std::string plus::postfix() const
{
    std::string output = "";

    output += right -> postfix();
    output += " " + left -> postfix();
    output += " +";
    return output;
}

double minus::value() const
{
    return (right -> value() - left -> value());
}
std::string minus::prefix() const
{
    std::string output = "-";

    output += ' ' + right -> prefix();
    output += ' ' + left -> prefix();
    return output;
}
std::string minus::postfix() const
{
    std::string output = "";

    output += right -> postfix();
    output += " " + left -> postfix();
    output += " -";
    return output;
}

double astsk::value() const
{
    return (left -> value() * right -> value());
}
std::string astsk::prefix() const
{
    std::string output = "*";

    output += ' ' + right -> prefix();
    output += ' ' + left -> prefix();
    return output;
}
std::string astsk::postfix() const
{
    std::string output = "";

    output += right -> postfix();
    output += " " + left -> postfix();
    output += " *";
    return output;
}

double slash::value() const
{
    if (left -> value() == 0)
    {
        throw std::runtime_error("Division by zero.");
    }
    return (right -> value() / left -> value());
}
std::string slash::prefix() const
{
    std::string output = "/";

    output += ' ' + right -> prefix();
    output += ' ' + left -> prefix();
    return output;
}
std::string slash::postfix() const
{
    std::string output = "";

    output += right -> postfix();
    output += " " + left -> postfix();
    output += " /";
    return output;
}

double mod::value() const
{
    if (left -> value() == 0)
    {
        throw std::runtime_error("Division by zero.");
    }
    return fmod(right -> value(), left -> value());
}
std::string mod::prefix() const
{
    std::string output = "%";

    output += ' ' + right -> prefix();
    output += ' ' + left -> prefix();
    return output;
}
std::string mod::postfix() const
{
    std::string output = "";

    output += right -> postfix();
    output += " " + left -> postfix();
    output += " %";
    return output;
}

double tilda::value() const
{
    return -(left -> value());
}
std::string tilda::prefix() const
{
    std::string output = "~";

    output += ' ' + left -> prefix();
    return output;
}
std::string tilda::postfix() const
{
    std::string output = "";

    output += left -> postfix();
    output += " ~";
    return output;
}
