#ifndef SRC_CALCULATIONS_H_
#define SRC_CALCULATIONS_H_

#include <iostream> // скорее всего надо будет удалить!!!!!!!!
#include <string>
#include <stack>
#include <sstream>
#include <cmath>

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
                char lexeme_kind;  // mod - m, cos - c, sin - s, tan - t, acos - C, asin - S, atan - T, sqrt - Q, log - l, ln - L
                double number;
                int unary;
            } lexeme;
            
            void ToReversePolish(std::string &str_input, lexeme *reverse_polish);
            int DefineLexeme(std::string &str_input, lexeme *lex, int index_input);
            char isNum(std::string &str_input, int *index_input, double *number);
            char isOperator(std::string &str_input, int *index_input);
            char isFunction(std::string &str_input, int *index_input);
            char isBracket(std::string &str_input, int *index_input);
            int GetPriority(lexeme lex);
            std::string GetSubstr(std::string &str_input, int index_input);
            void ClearLexeme(lexeme *lex);

            bool isValidInputStr(std::string &str_input);
            bool CheckDot(std::string &str_input);
            bool CheckX(std::string &str_input);
            bool CheckNumbers(std::string &str_input);
            bool CheckBrackets(std::string &str_input);
            bool isValidReversePolish(lexeme *reverse_polish);

            double CalculateReversePolish(lexeme *reverse_polish);
            double CalculateFunction(double number, char function);
            double CalculateUnaryOp(double number, char op);
            double CalculateOp(double number_1, double number_2, char op);
    };
}

#endif  // SRC_CALCULATIONS_H_