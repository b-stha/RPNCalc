#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <string>
#include "AST.h"

struct elem
{
    elem* next = NULL;
    AST* data = NULL;
};

class stack
{
public:
    elem* head;
    stack();
    ~stack();
    void append(AST* value);
    AST* pop();
    size_t count() const;
};

#endif