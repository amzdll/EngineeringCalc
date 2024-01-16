#include "calculator.h"

namespace s21 {
double Calculator::CalculatePostfix(const list& postfix,
                                    double variable_value) {
  list temporary_list;
  double temp_result;
  for (auto itr : postfix) {
    if (itr.type == t_num) {
      temporary_list.push_front(itr);
    } else if (itr.type == t_variable) {
      temporary_list.emplace_front(variable_value, 0, t_num);
    } else if (itr.type >= t_plus && itr.type <= t_pow) {
      double a = temporary_list.begin()->value;
      temporary_list.pop_front();
      double b = temporary_list.begin()->value;
      temporary_list.pop_front();
      temp_result = CalculateArithmeticOperations(a, b, itr.type);
      temporary_list.emplace_front(temp_result, 0, t_num);
    } else if (itr.type >= t_cos) {
      double a = temporary_list.begin()->value;
      temporary_list.pop_front();
      temp_result = CalculateFunctionOperations(a, itr.type);
      temporary_list.emplace_front(temp_result, 0, t_num);
    }
  }
  return temporary_list.begin()->value;
}

double Calculator::CalculateArithmeticOperations(double a, double b,
                                                 type_t operation) {
  double result = 0;
  if (operation == t_plus) {
    result = b + a;
  } else if (operation == t_minus) {
    result = b - a;
  } else if (operation == t_div) {
    result = b / a;
  } else if (operation == t_mul) {
    result = b * a;
  } else if (operation == t_mod) {
    result = fmod(b, a);
  } else if (operation == t_pow) {
    result = pow(b, a);
  }
  return result;
}

double Calculator::CalculateFunctionOperations(double a, type_t operation) {
  double result = 0;
  if (operation == t_cos) {
    result = cos(a);
  } else if (operation == t_sin) {
    result = sin(a);
  } else if (operation == t_tan) {
    result = tan(a);
  } else if (operation == t_acos) {
    result = acos(a);
  } else if (operation == t_asin) {
    result = asin(a);
  } else if (operation == t_atan) {
    result = atan(a);
  } else if (operation == t_sqrt) {
    result = sqrt(a);
  } else if (operation == t_ln) {
    result = log10(a);
  } else if (operation == t_log) {
    result = log(a);
  }
  return result;
}
}  // namespace s21