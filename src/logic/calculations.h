#ifndef SRC_LOGIC_CALCULATIONS_H_
#define SRC_LOGIC_CALCULATIONS_H_

#include <cmath>

#include "parser.h"
#include "validation.h"

#define LEN 255
#define EPS 1e-8

namespace s21 {

class Calculations {
 public:
  Calculations();

  double Calculate(std::string &str_input, bool *status);

 private:
  Parser *parser;
  Validation *validation;

  double CalculateReversePolish(lexeme *reverse_polish);
  double CalculateFunction(double number, char function);
  double CalculateUnaryOp(double number, char op);
  double CalculateOp(double number_1, double number_2, char op);
};
}  // namespace s21

#endif  // SRC_LOGIC_CALCULATIONS_H_
