#include "calculations.h"

double s21::Calculations::Calculate(std::string &str_input, bool *status) {
  double result = 0;
  lexeme reverse_polish[LEN];
  for (int i = 0; i < LEN; i++) {
    parser->ClearLexeme(&reverse_polish[i]);
  }

  if (validation->IsValidInputStr(str_input)) {
    parser->ToReversePolish(str_input, reverse_polish);

    if (validation->IsValidReversePolish(reverse_polish)) {
      result = CalculateReversePolish(reverse_polish);
      *status = true;
    }
  }

  return result;
}

double s21::Calculations::CalculateReversePolish(lexeme *reverse_polish) {
  double result = 0;
  int index_rev_pol = 0, index_num = 0;
  double numbers[LEN] = {0};

  while (reverse_polish[index_rev_pol].type != UNDEFINED) {
    if (reverse_polish[index_rev_pol].type == NUMBER) {
      numbers[index_num] = reverse_polish[index_rev_pol].number;
      index_num++;
    }

    if (reverse_polish[index_rev_pol].type == FUNCTION) {
      numbers[index_num - 1] = CalculateFunction(
          numbers[index_num - 1], reverse_polish[index_rev_pol].lexeme_kind);
    }

    if (reverse_polish[index_rev_pol].type == OPERATOR) {
      if (reverse_polish[index_rev_pol].unary == 1) {
        numbers[index_num - 1] = CalculateUnaryOp(
            numbers[index_num - 1], reverse_polish[index_rev_pol].lexeme_kind);
      } else {
        numbers[index_num - 2] =
            CalculateOp(numbers[index_num - 2], numbers[index_num - 1],
                        reverse_polish[index_rev_pol].lexeme_kind);
        numbers[index_num - 1] = 0;
        index_num--;
      }
    }

    index_rev_pol++;
  }

  result = numbers[index_num - 1];
  return result;
}

double s21::Calculations::CalculateFunction(double number, char function) {
  double result = 0;
  switch (function) {
    case 's':
      result = sin(number);
      break;
    case 'c':
      result = cos(number);
      break;
    case 't':
      result = tan(number);
      break;
    case 'l':
      result = log10(number);
      break;
    case 'S':
      result = asin(number);
      break;
    case 'C':
      result = acos(number);
      break;
    case 'T':
      result = atan(number);
      break;
    case 'Q':
      result = sqrt(number);
      break;
    case 'L':
      result = log(number);
      break;
  }
  return result;
}

double s21::Calculations::CalculateUnaryOp(double number, char op) {
  switch (op) {
    case '-':
      number = -number;
      break;
    case '+':
      break;
  }
  return number;
}

double s21::Calculations::CalculateOp(double number_1, double number_2,
                                      char op) {
  double result = 0;
  switch (op) {
    case '+':
      result = number_1 + number_2;
      break;
    case '-':
      result = number_1 - number_2;
      break;
    case '*':
      result = number_1 * number_2;
      break;
    case '/':
      result = number_1 / number_2;
      break;
    case '^':
      result = pow(number_1, number_2);
      break;
    case 'm':
      result = fmod(number_1, number_2);
      break;
  }
  return result;
}
