#include "calculations.h"

void s21::Calculations::ToReversePolish(std::string &str_input,
                                        lexeme *reverse_polish) {
  std::stack<lexeme> queue;
  lexeme lex;

  int index_input = 0, index_output = 0;
  while (index_input < (int)str_input.length()) {
    index_input = DefineLexeme(str_input, &lex, index_input);

    if (lex.type == NUMBER) {
      reverse_polish[index_output] = lex;
      index_output++;
    }

    if (lex.type == FUNCTION || lex.lexeme_kind == '(') {
      queue.push(lex);
    }

    if (lex.lexeme_kind == ')') {
      while (!queue.empty() && queue.top().lexeme_kind != '(') {
        reverse_polish[index_output] = queue.top();
        index_output++;
        queue.pop();
      }

      queue.pop();
    }

    if (lex.type == OPERATOR) {
      while (!queue.empty() &&
             (queue.top().type == FUNCTION ||
              (queue.top().type == OPERATOR &&
               GetPriority(queue.top()) <= GetPriority(lex)))) {
        reverse_polish[index_output] = queue.top();
        index_output++;
        queue.pop();
      }

      queue.push(lex);
    }

    if (str_input[index_input] == ' ') {
      index_input++;
    }
  }
  while (!queue.empty()) {
    reverse_polish[index_output] = queue.top();
    index_output++;
    queue.pop();
  }
}

int s21::Calculations::DefineLexeme(std::string &str_input, lexeme *lex,
                                    int index_input) {
  ClearLexeme(lex);
  char lex_kind = 0;
  double number = 0;

  if ((lex_kind = IsOperator(str_input, &index_input))) {
    lex->type = OPERATOR;
    lex->lexeme_kind = lex_kind;

    std::string signs = "+-";
    if ((int)signs.find(lex_kind) != -1 &&
        (str_input[index_input] == 'x' || str_input[index_input] == '(' ||
         isdigit(str_input[index_input]))) {
      lex->unary = 1;
    }
  } else if ((lex_kind = IsFunction(str_input, &index_input))) {
    lex->type = FUNCTION;
    lex->lexeme_kind = lex_kind;
  } else if ((lex_kind = IsBracket(str_input, &index_input))) {
    lex->type = BRACKET;
    lex->lexeme_kind = lex_kind;
  } else {
    lex_kind = IsNum(str_input, &index_input, &number);
    lex->type = NUMBER;
    lex->lexeme_kind = lex_kind;
    lex->number = number;
  }

  return index_input;
}

char s21::Calculations::IsNum(std::string &str_input, int *index_input,
                              double *number) {
  char status = 0;
  int count_symbol = 0;
  std::string new_str = GetSubstr(str_input, *index_input);

  std::istringstream ss(new_str);

  if (ss >> *number) {
    count_symbol = new_str.size();
  }

  if (count_symbol > 0) {
    *index_input += count_symbol;
    status = 1;
  } else {
    if (str_input[*index_input] == 'x') {
      status = 'x';
      *index_input += 1;
    }
  }
  return status;
}

char s21::Calculations::IsOperator(std::string &str_input, int *index_input) {
  char status = 0;

  std::string operators = "+-*/^";
  if ((int)operators.find(str_input[*index_input]) != -1) {
    status = str_input[*index_input];
    *index_input += 1;
  } else if (GetSubstr(str_input, *index_input) == "mod") {
    status = 'm';
    *index_input += 3;
  }
  return status;
}

char s21::Calculations::IsFunction(std::string &str_input, int *index_input) {
  char status = 0;

  std::string new_str = GetSubstr(str_input, *index_input);

  if (new_str == "sin" || new_str == "cos" || new_str == "tan" ||
      new_str == "log") {
    status = str_input[*index_input];
    *index_input += 3;
  } else if (new_str == "asin" || new_str == "acos" || new_str == "atan" ||
             new_str == "sqrt") {
    status = str_input[*index_input + 1] - 32;
    *index_input += 4;
  } else if (new_str == "ln") {
    status = str_input[*index_input] - 32;
    *index_input += 2;
  }

  return status;
}

char s21::Calculations::IsBracket(std::string &str_input, int *index_input) {
  char status = 0;

  if (str_input[*index_input] == '(' || str_input[*index_input] == ')') {
    status = str_input[*index_input];
    *index_input += 1;
  }
  return status;
}

int s21::Calculations::GetPriority(lexeme lex) {
  int prior = 0;
  std::string lexeme_prior_3 = "*/msctlSCTQL";

  if (lex.lexeme_kind == '^') {
    prior = 2;
  } else if ((int)lexeme_prior_3.find(lex.lexeme_kind) != -1) {
    prior = 3;
  } else if (lex.lexeme_kind == '+' || lex.lexeme_kind == '-') {
    if (lex.unary == 0) {
      prior = 4;
    } else {
      prior = 1;
    }
  }
  return prior;
}

std::string s21::Calculations::GetSubstr(std::string &str_input,
                                         int index_input) {
  std::string new_str;

  for (int i = 0; i < (int)str_input.length() - index_input; i++) {
    if (str_input[index_input + i] == ' ' ||
        str_input[index_input + i] == '(' ||
        str_input[index_input + i] == ')' ||
        str_input[index_input + i] == '^') {
      break;
    }
    new_str.resize(i + 1, str_input[index_input + i]);
  }

  return new_str;
}

void s21::Calculations::ClearLexeme(lexeme *lex) {
  lex->type = UNDEFINED;
  lex->lexeme_kind = 0;
  lex->number = 0;
  lex->unary = 0;
}