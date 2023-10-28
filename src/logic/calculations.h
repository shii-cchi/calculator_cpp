#ifndef CPP3_SMARTCALC_LOGIC_CALCULATIONS_H_
#define CPP3_SMARTCALC_LOGIC_CALCULATIONS_H_

#include <cmath>

#include "parser.h"
#include "validation.h"
#include <tuple>

#define LEN 255
#define EPS 1e-8

namespace s21 {

class Calculations {
 public:
  std::tuple<double, bool> Calculate(std::string &str_input);

 private:
  double CalculateReversePolish(lexeme *reverse_polish);
  double CalculateFunction(double number, char function);
  double CalculateUnaryOp(double number, char op);
  double CalculateOp(double number_1, double number_2, char op);

  s21::Parser parser;
  s21::Validation validation;
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_LOGIC_CALCULATIONS_H_
