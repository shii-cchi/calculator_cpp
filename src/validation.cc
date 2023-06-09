#include "calculations.h"

bool s21::Calculations::IsValidInputStr(std::string &str_input) {
  bool status = true;

  if (!CheckDot(str_input) || !CheckX(str_input) || !CheckNumbers(str_input) ||
      !CheckBrackets(str_input)) {
    status = false;
  }

  return status;
}

bool s21::Calculations::CheckDot(std::string &str_input) {
  bool status = true;
  int count_dot = 0;

  for (int i = 0; i < (int)str_input.length(); i++) {
    if (str_input[i] == '.') {
      count_dot++;

      if (i == (int)str_input.length() - 1) {
        if (!isdigit(str_input[i - 1])) {
          status = false;
        }
      } else {
        if (!isdigit(str_input[i - 1]) && !isdigit(str_input[i + 1])) {
          status = false;
        }
      }
    }

    if (str_input[i] == ' ') {
      count_dot = 0;
    }

    if (count_dot > 1) {
      status = false;
      break;
    }
  }

  return status;
}

bool s21::Calculations::CheckX(std::string &str_input) {
  bool status = true;
  int count_x = 0;

  for (int i = 0; i < (int)str_input.length(); i++) {
    if (str_input[i] == 'x') {
      count_x++;
    }

    if (str_input[i] == ' ') {
      count_x = 0;
    }

    if (count_x > 1) {
      status = false;
      break;
    }
  }

  return status;
}

bool s21::Calculations::CheckNumbers(std::string &str_input) {
  int status = true;
  int digit = 0;

  for (int i = 0; i < (int)str_input.length(); i++) {
    if (isdigit(str_input[i]) || str_input[i] == 'x') {
      digit++;
    }
  }

  if (digit == 0) {
    status = false;
  }

  return status;
}

bool s21::Calculations::CheckBrackets(std::string &str_input) {
  int status = true;
  int brackets = 0;

  for (int i = 0; i < (int)str_input.length(); i++) {
    if (str_input[i] == '(') {
      brackets++;
    }

    if (str_input[i] == ')') {
      brackets--;
    }

    if (brackets < 0) {
      status = false;
      break;
    }
  }

  if (brackets != 0) {
    status = false;
  }

  return status;
}

bool s21::Calculations::IsValidReversePolish(lexeme *reverse_polish) {
  int status = true;
  int index = 0, operators = 0, numbers = 0;

  while (reverse_polish[index].type != UNDEFINED) {
    if (reverse_polish[index].type == NUMBER) {
      numbers++;
    }

    if (reverse_polish[index].type == OPERATOR) {
      if (reverse_polish[index].unary != 1) {
        operators++;
      }
    }

    index++;
  }

  if (numbers < operators + 1 || (numbers >= 2 && operators == 0)) {
    status = false;
  }

  return status;
}