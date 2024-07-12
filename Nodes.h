#ifndef NODES_H
#define NODES_H

#include "AST.h"
#include <sstream>
#include <stdexcept>
#include <cmath>

class oper: public AST
{

    public:
    ~oper();
    AST* left = NULL;
    AST* right = NULL;
};

class number: public AST
{
    double constant;

    public:
    number(double data);
    std::string prefix() const;
    std::string postfix() const;
    double value() const;
};

class plus: public oper
{
    public:
    double value() const;
    std::string prefix() const;
    std::string postfix() const;
};

class minus: public oper
{
    public:
    double value() const;
    std::string prefix() const;
    std::string postfix() const;
};

class astsk: public oper
{
    public:
    double value() const;
    std::string prefix() const;
    std::string postfix() const;
};

class slash: public oper
{
    public:
    double value() const;
    std::string prefix() const;
    std::string postfix() const;
};

class mod: public oper
{
    public:
    double value() const;
    std::string prefix() const;
    std::string postfix() const;
};

class tilda: public oper
{
    public:
    double value() const;
    std::string prefix() const;
    std::string postfix() const;
};



#endif