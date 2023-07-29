#include "validator.h"

namespace s21 {
int s21::Validator::IsExpressionValid(const std::string &expression) {
  // status of valid - 0 - incorrect, 1 - correct, 2 correct with variable
  std::string operations = "+-/*.%^";
  std::map<std::string, int> flags = {
      flags_type("operation", 0),       flags_type("function_operation", 0),
      flags_type("number", 0),          flags_type("count_of_brackets", 0),
      flags_type("start_position", 1),  flags_type("brackets_row", 0),
      flags_type("variable_status", 0), flags_type("status_of_valid", 1)};
  for (size_t i = 0; i < expression.size() && flags["status_of_valid"]; ++i) {
    if (isdigit(expression[i]) || expression[i] == 'x') {
      NumberValid(expression, i, flags);
    } else if (operations.find(expression[i]) != std::string::npos) {
      OperationValid(expression, i, flags);
    } else if (isalpha(expression[i])) {
      FunctionValid(expression, i, flags);
    } else if (expression[i] == '(' || expression[i] == ')') {
      BracketValid(expression, i, flags);
    }
  }

  if (flags["operation"] || flags["count_of_brackets"] ||
      flags["function_operation"]) {
    flags["status_of_valid"] = 0;
  } else if (flags["status_of_valid"] && flags["variable_status"]) {
    flags["status_of_valid"] = 2;
  }
  return flags["status_of_valid"];
}

bool s21::Validator::IsPlotRangeValid(std::string min_plot_interval,
                                      std::string max_plot_interval) {
  std::string operations = "+-. ";
  if (min_plot_interval != "" && max_plot_interval != "" &&
      (min_plot_interval.size() > 1 ||
       (min_plot_interval.size() == 1 &&
        (operations.find(min_plot_interval) == std::string::npos))) &&
      (max_plot_interval.size() > 1 ||
       (max_plot_interval.size() == 1 &&
        (operations.find(max_plot_interval) == std::string::npos))) &&
      std::stod(min_plot_interval) < std::stod(max_plot_interval)) {
    return true;
  }
  return false;
}

void Validator::NumberValid(const std::string &expression, size_t &position,
                            std::map<std::string, int> &flags) {
  if (flags["number"]) {
    flags["status_of_valid"] = false;
  } else {
    flags["number"] = 1;
    flags["operation"] = 0;
    flags["function_operation"] = 0;
    flags["brackets_row"] = 0;
    flags["start_position"] = 0;

    if (expression[position] != 'x') {
      int size_of_number = 0;
      double _ = 0;
      std::sscanf(expression.c_str() + position, "%le%n", &_, &size_of_number);
      position += size_of_number - 1;
    } else {
      flags["variable_status"] = 1;
    }
  }
}

void Validator::OperationValid(const std::string &expression, size_t &position,
                               std::map<std::string, int> &flags) {
  if ((flags["start_position"] &&
       !(expression[position] == '+' || expression[position] == '-')) ||
      flags["operation"]) {
    flags["status_of_valid"] = false;
  } else {
    flags["operation"] = 1;
    flags["number"] = 0;
  }
}

void Validator::FunctionValid(const std::string &expression, size_t &position,
                              std::map<std::string, int> &flags) {
  std::set<std::string> functions = {"cos",  "sin",  "tan", "acos", "asin",
                                     "atan", "sqrt", "ln",  "log"};
  char function[5];
  int size_of_function = 0;
  std::sscanf(expression.c_str() + position, "%4[^(]%n", function,
              &size_of_function);
  if (functions.find((std::string)function) != functions.end() &&
      (flags["operation"] || flags["start_position"])) {
    position += size_of_function - 1;
    flags["function_operation"] = 1;
  } else {
    flags["status_of_valid"] = false;
  }
}

void Validator::BracketValid(const std::string &expression, size_t &position,
                             std::map<std::string, int> &flags) {
  if (expression[position] == '(') {
    flags["brackets_row"] = 1;
    flags["start_position"] = 1;
    flags["operation"] = 0;
    flags["function_operation"] = 0;
    ++flags["count_of_brackets"];
  } else if (expression[position] == ')') {
    if (flags["count_of_brackets"] <= 0 || flags["brackets_row"]) {
      flags["status_of_valid"] = false;
    } else {
      --flags["count_of_brackets"];
      flags["start_position"] = 0;
      flags["operation"] = 0;
    }
  }
}

}  // namespace s21
