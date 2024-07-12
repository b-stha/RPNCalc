#include "AST.h"
#include "Nodes.h"
#include "Stack.h"

#include <sstream>
#include <iostream>
#include <stdexcept>


bool isDouble(std::string str)
{
    char* endptr = 0;
    strtod(str.c_str(), &endptr);

    if(*endptr != '\0' || endptr == str)
        return false;
    return true;
}

AST* AST::parse(const std::string& expression) {
    std::istringstream token1(expression);
    std::istringstream token2(expression);
    std::istringstream token3(expression);
    std::string counter;
    char op;
    stack queue;

    while (token3)
    {
        token3 >> counter;
        if (token3)
        {
            
            std::string tmp1;
            std::string tmp2;
            token1 >> tmp1;
            
            if (!isDouble(tmp1))
            {
                if (counter.length() == 1)
                {
                    token2 >> op;
                    switch(op)
                    {
                        case '+':
                        {
                            if (queue.count() < 2)
                            {
                                throw std::runtime_error("Not enough operands.");
                            }
                            else
                            {
                                plus* input_pl = new plus;
                                input_pl -> left = queue.pop();
                                input_pl -> right = queue.pop();
                                queue.append(input_pl);
                            }
                        }
                            break;
                        case '-':
                        {
                            if (queue.count() < 2)
                            {
                                throw std::runtime_error("Not enough operands.");
                            }
                            else
                            {
                                minus* input_mn = new minus;
                                input_mn -> left = queue.pop();
                                input_mn -> right = queue.pop();
                                queue.append(input_mn);
                            }
                        }
                            break;
                        case '*':
                        {
                            if (queue.count() < 2)
                            {
                                throw std::runtime_error("Not enough operands.");
                            }
                            else
                            {
                                astsk* input_mt = new astsk;
                                input_mt -> left = queue.pop();
                                input_mt -> right = queue.pop();
                                queue.append(input_mt);
                            }
                        }
                            break;
                        case '/':
                        {
                            if (queue.count() < 2)
                            {
                                throw std::runtime_error("Not enough operands.");
                            }
                            else
                            {
                                slash* input_dv = new slash;
                                input_dv -> left = queue.pop();
                                input_dv -> right = queue.pop();
                                queue.append(input_dv);
                            }
                        }
                            break;
                        case '%':
                        {
                            if (queue.count() < 2)
                            {
                                throw std::runtime_error("Not enough operands.");
                            }
                            else
                            {
                                mod* input_rm = new mod;
                                input_rm -> left = queue.pop();
                                input_rm -> right = queue.pop();
                                queue.append(input_rm);
                            }
                        }
                            break;
                        case '~':
                        {
                            if (queue.count() < 1)
                            {
                                throw std::runtime_error("Not enough operands.");
                            }
                            else
                            {
                                tilda* input_ng = new tilda;
                                input_ng -> left = queue.pop();
                                queue.append(input_ng);
                            }
                        }
                            break;
                        default:
                            std::string output = "Invalid token: ";
                            output += counter;
                            throw std::runtime_error(output);
                    }
                }
                else
                {
                    std::string output = "Invalid token: ";
                    output += counter;
                    throw std::runtime_error(output);
                    token2 >> tmp2;
                }
            }
            else
            {
                token2 >> tmp2;
                double num = std::stod(tmp1);
                number* input_num = new number(num);
                queue.append(input_num);
            }
        }
    }
    if (queue.count() == 0)
    {
        throw std::runtime_error("No input.");
    }
    else if (queue.count() > 1)
    {
        throw std::runtime_error("Too many operands.");
    }
    else
    {
        AST* output = queue.pop();
        return output;
    }
}
