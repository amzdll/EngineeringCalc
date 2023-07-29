#ifndef CPP3_SMARTCALC_V2_0_1_VALIDATOR_H
#define CPP3_SMARTCALC_V2_0_1_VALIDATOR_H

#include "../common.h"

namespace s21 {
class Validator {
  using flags_type = std::pair<std::string, int>;

 public:
  static int IsExpressionValid(const std::string &expression);
  static bool IsPlotRangeValid(std::string min_plot_interval_,
                               std::string max_plot_interval_);

 private:
  static void NumberValid(const std::string &expression, size_t &position,
                          std::map<std::string, int> &flags);
  static void OperationValid(const std::string &expression, size_t &position,
                             std::map<std::string, int> &flags);
  static void FunctionValid(const std::string &expression, size_t &position,
                            std::map<std::string, int> &flags);
  static void BracketValid(const std::string &expression, size_t &position,
                           std::map<std::string, int> &flags);
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_VALIDATOR_H
