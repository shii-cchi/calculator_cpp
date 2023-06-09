#ifndef SRC_CALCULATIONS_H_
#define SRC_CALCULATIONS_H_

#include <cmath>
#include <iostream>  // скорее всего надо будет удалить!!!!!!!!
#include <sstream>
#include <stack>
#include <string>

#define LEN 255
#define EPS 1e-8

namespace s21 {

class Calculations {
 public:
  double Calculate(std::string &str_input, bool *status);

 private:
  enum lexeme_type { NUMBER, OPERATOR, FUNCTION, BRACKET, UNDEFINED };

  typedef struct lexemes {
    enum lexeme_type type;
    char lexeme_kind;  // mod - m, cos - c, sin - s, tan - t, acos - C, asin -
                       // S, atan - T, sqrt - Q, log - l, ln - L
    double number;
    int unary;
  } lexeme;

  void ToReversePolish(std::string &str_input, lexeme *reverse_polish);
  int DefineLexeme(std::string &str_input, lexeme *lex, int index_input);
  char IsNum(std::string &str_input, int *index_input, double *number);
  char IsOperator(std::string &str_input, int *index_input);
  char IsFunction(std::string &str_input, int *index_input);
  char IsBracket(std::string &str_input, int *index_input);
  int GetPriority(lexeme lex);
  std::string GetSubstr(std::string &str_input, int index_input);
  void ClearLexeme(lexeme *lex);

  bool IsValidInputStr(std::string &str_input);
  bool CheckDot(std::string &str_input);
  bool CheckX(std::string &str_input);
  bool CheckNumbers(std::string &str_input);
  bool CheckBrackets(std::string &str_input);
  bool IsValidReversePolish(lexeme *reverse_polish);

  double CalculateReversePolish(lexeme *reverse_polish);
  double CalculateFunction(double number, char function);
  double CalculateUnaryOp(double number, char op);
  double CalculateOp(double number_1, double number_2, char op);
};
}  // namespace s21

#endif  // SRC_CALCULATIONS_H_