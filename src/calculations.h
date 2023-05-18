#ifndef SRC_CALCULATIONS_H_
#define SRC_CALCULATIONS_H_

#include <iostream> // скорее всего надо будет удалить!!!!!!!!
#include <string>
#include <stack>
#include <sstream>

#define LEN 255

namespace s21 {
    enum lexeme_type { NUMBER, OPERATOR, FUNCTION, BRACKET, UNDEFINED };

    typedef struct lexemes {
    enum lexeme_type type;
    char lexeme_kind;  // mod - m, cos - c, sin - s, tan - t, acos - C, asin - S, atan - T, sqrt - Q, log - l, ln - L
    double number;
    int unary;
    } lexeme;

    class Calculations {
        public:
            void ToReversePolish(std::string &str_input, lexeme *reverse_polish);
            int DefineLexeme(std::string &str_input, lexeme *lex, int index_input);
            char isNum(std::string &str_input, int *index_input, double *number);
            char isOperator(std::string &str_input, int *index_input);
            char isFunction(std::string &str_input, int *index_input);
            char isBracket(std::string &str_input, int *index_input);
            int GetPriority(lexeme lex);
            std::string GetSubstr(std::string &str_input, int index_input);
            void ClearLexeme(lexeme *lex);
    };
}

#endif  // SRC_CALCULATIONS_H_