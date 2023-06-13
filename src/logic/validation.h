#ifndef SRC_LOGIC_VALIDATION_H_
#define SRC_LOGIC_VALIDATION_H_

#include <string>

#include "lexeme.h"

namespace s21 {

class Validation {
 public:
  bool IsValidInputStr(std::string &str_input);
  bool IsValidReversePolish(lexeme *reverse_polish);

 private:
  bool CheckDot(std::string &str_input);
  bool CheckX(std::string &str_input);
  bool CheckNumbers(std::string &str_input);
  bool CheckBrackets(std::string &str_input);
};
}  // namespace s21

#endif  // SRC_LOGIC_VALIDATION_H_