#ifndef AST_H
#define AST_H

#include <string>

class AST {
public:
  static AST* parse(const std::string& expression);

public:
  virtual ~AST() {}

  virtual std::string prefix()  const = 0;
  virtual std::string postfix() const = 0;
  virtual double      value()   const = 0;
};

#endif
