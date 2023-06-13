#ifndef SRC_LOGIC_PARSER_H_
#define SRC_LOGIC_PARSER_H_

#include <sstream>
#include <stack>
#include <string>
#include "lexeme.h"

namespace s21 {

class Parser {
 public:
  void ClearLexeme(lexeme *lex);
  void ToReversePolish(std::string &str_input, lexeme *reverse_polish);

 private:
  int DefineLexeme(std::string &str_input, lexeme *lex, int index_input);
  char IsNum(std::string &str_input, int *index_input, double *number);
  char IsOperator(std::string &str_input, int *index_input);
  char IsFunction(std::string &str_input, int *index_input);
  char IsBracket(std::string &str_input, int *index_input);
  int GetPriority(lexeme lex);
  std::string GetSubstr(std::string &str_input, int index_input);
};
}  // namespace s21

#endif  // SRC_LOGIC_PARSER_H_