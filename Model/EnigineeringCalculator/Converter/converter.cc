#include "converter.h"

#include <utility>

namespace s21 {
void Converter::InitMapsOfOperands(std::map<char, lexeme_t> &operations,
                                   std::map<std::string, lexeme_t> &functions) {
  operations = {
      operand_type('+', {0, 1, t_plus}), operand_type('-', {0, 1, t_minus}),
      operand_type('/', {0, 2, t_div}),  operand_type('*', {0, 2, t_mul}),
      operand_type('%', {0, 2, t_mod}),  operand_type('^', {0, 3, t_pow}),
  };

  functions = {function_type("cos", {0, 4, t_cos}),
               function_type("sin", {0, 4, t_sin}),
               function_type("tan", {0, 4, t_tan}),
               function_type("acos", {0, 4, t_acos}),
               function_type("asin", {0, 4, t_asin}),
               function_type("atan", {0, 4, t_atan}),
               function_type("sqrt", {0, 4, t_sqrt}),
               function_type("ln", {0, 4, t_ln}),
               function_type("log", {0, 4, t_log})};
}

void Converter::LexemeOfNumber(const std::string &expression, size_t &position,
                               list &list_of_expression) {
  int size_of_number = 0;
  double value = 0;
  std::sscanf(expression.c_str() + position, "%le%n", &value, &size_of_number);
  position += size_of_number - 1;
  list_of_expression.emplace_back(value, 0, t_num);
}

void Converter::LexemeOfOperations(const std::string &expression,
                                   size_t &position, list &list_of_expression,
                                   std::map<char, lexeme_t> operations) {
  auto current_operator = operations.find(expression[position]);
  size_t fiction_position = 0;
  if ((expression[position] == '+' || expression[position] == '-') &&
      (position == 0 || expression[position - 1] == '(')) {
    LexemeOfNumber("0", fiction_position, list_of_expression);
  }
  list_of_expression.emplace_back(operations[current_operator->first]);
}

void Converter::LexemeOfFunctions(std::string &expression, size_t &position,
                                  list &list_of_expression,
                                  std::map<std::string, lexeme_t> functions) {
  int size_of_function = 0;
  char function[5];
  std::sscanf(expression.c_str() + position, "%4[^(]%n", function,
              &size_of_function);
  position += size_of_function - 1;
  auto current_function = functions.find((std::string)function);
  list_of_expression.emplace_back(functions[current_function->first]);
}

Converter::list Converter::StringToInfix(std::string expression) {
  std::map<char, lexeme_t> operations;
  std::map<std::string, lexeme_t> functions;
  InitMapsOfOperands(operations, functions);
  list list_of_expression;
  for (size_t i = 0; i < expression.size(); i++) {
    if (expression[i] == '.' || isdigit(expression[i])) {
      LexemeOfNumber(expression, i, list_of_expression);
    } else if (expression[i] == 'x') {
      list_of_expression.emplace_back(0, 0, t_variable);
    } else if (operations.find(expression[i]) != operations.end()) {
      //      auto current_operator = operations.find(expression[i]);
      LexemeOfOperations(expression, i, list_of_expression, operations);
    } else if (expression[i] == '(') {
      list_of_expression.emplace_back(0, -1, t_bracket_l);
    } else if (expression[i] == ')') {
      list_of_expression.emplace_back(0, -1, t_bracket_r);
    } else if (isalpha(expression[i])) {
      LexemeOfFunctions(expression, i, list_of_expression, functions);
    }
  }
  return list_of_expression;
}

Converter::list Converter::StringToPostfix(std::string expression) {
  list temporary_list;
  list output_list;
  list infix = StringToInfix(expression);
  for (auto itr : infix) {
    if (itr.type == t_num || itr.type == t_variable) {
      output_list.push_back(itr);
    } else if (itr.priority >= 1 && itr.priority <= 4) {
      ConvertOperationToPostfix(itr, temporary_list, output_list);
    } else if (itr.type == t_bracket_l || itr.type == t_bracket_r) {
      ConvertBracketsToPostfix(itr, temporary_list, output_list);
    }
  }
  while (!temporary_list.empty()) {
    output_list.push_back(*(temporary_list.begin()));
    temporary_list.pop_front();
  }
  return output_list;
}

void Converter::ConvertOperationToPostfix(lexeme_t lexeme, list &temporary_list,
                                          list &output_list) {
  if (temporary_list.begin()->priority < lexeme.priority ||
      temporary_list.empty()) {
    temporary_list.push_front(lexeme);
  } else if (temporary_list.begin()->priority >= lexeme.priority) {
    for (auto itr = temporary_list.begin();
         itr != temporary_list.end() &&
         temporary_list.begin()->priority >= lexeme.priority &&
         temporary_list.begin()->type != t_bracket_l;
         ++itr) {
      output_list.push_back(*itr);
      temporary_list.pop_front();
    }
    temporary_list.push_front(lexeme);
  }
}

void Converter::ConvertBracketsToPostfix(lexeme_t lexeme, list &temporary_list,
                                         list &output_list) {
  if (lexeme.type == t_bracket_l) {
    temporary_list.push_front(lexeme);
  } else {
    for (auto itr = temporary_list.begin(); itr->type != t_bracket_l; ++itr) {
      output_list.push_back(*itr);
      temporary_list.pop_front();
    }
    temporary_list.pop_front();
  }
}
}  // namespace s21
