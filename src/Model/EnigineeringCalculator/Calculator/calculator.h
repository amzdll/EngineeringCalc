#ifndef CPP3_SMARTCALC_V2_0_1_CALCULATOR_H
#define CPP3_SMARTCALC_V2_0_1_CALCULATOR_H

#include "../common.h"

namespace s21 {

class Calculator {
 public:
  using list = std::list<lexeme_t>;

  static double CalculatePostfix(const list& postfix, double variable_value);

 private:
  static double CalculateArithmeticOperations(double a, double b,
                                              type_t operation);
  static double CalculateFunctionOperations(double a, type_t operation);
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CALCULATOR_H
