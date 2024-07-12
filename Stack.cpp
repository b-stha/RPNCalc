#include "Stack.h"

stack::stack()
{
    head = NULL;
}

stack::~stack()
{
    elem* curr = head;

    while (curr != NULL)
    {
        head = curr -> next;
        delete curr -> data;
        delete curr;
        curr = head;
    }
    delete head;
    head = NULL;
}

void stack::append(AST* value)
{
    if (head == NULL)
    {
        elem* input = new elem;
        input -> next = NULL;
        head = input;
        input -> data = value;
    }
    else
    {
        elem* curr = head;
        elem* prev = head;
        while (curr != NULL)
        {
            prev = curr;
            curr = curr -> next;
        }
        elem* input = new elem;
        input -> data = value;
        input -> next = NULL;
        prev -> next = input;
    }
}

AST* stack::pop()
{
    elem* curr = head;
    elem* prev = head;
    elem* idx = head;

    while (idx != NULL)
    {
        prev = curr;
        curr = idx;
        idx = idx -> next;
    }

    AST* output = curr -> data;
    if (stack::count() == 1)
    {
        head = NULL;
    }
    else
    {
        prev -> next = NULL;
    }
    delete curr;
    return output;
}

size_t stack::count() const
{
    elem* p = head;
    size_t count = 0;
    while (p != NULL)
    {
        count++;
        p = p -> next;
    }
    return count;
}