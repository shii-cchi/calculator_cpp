#ifndef SRC_LEXEME_H_
#define SRC_LEXEME_H_

namespace s21 {
  enum lexeme_type { NUMBER, OPERATOR, FUNCTION, BRACKET, UNDEFINED };

  typedef struct lexemes {
    enum lexeme_type type;
    char lexeme_kind;  // mod - m, cos - c, sin - s, tan - t, acos - C, asin -
                       // S, atan - T, sqrt - Q, log - l, ln - L
    double number;
    int unary;
  } lexeme;
}

#endif  // SRC_LEXEME_H_