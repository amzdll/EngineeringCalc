#ifndef CPP3_SMARTCALC_V2_0_1_CALCULATOR_FACADE_H
#define CPP3_SMARTCALC_V2_0_1_CALCULATOR_FACADE_H

#include "Calculator/calculator.h"
#include "Converter/converter.h"
#include "Validator/validator.h"

namespace s21 {

class EnigineeringCalculatorFacade {
 public:
  void SetExpression(std::string expression);
  void SetVariable(std::string variable_parameter);
  void SetInterval(std::pair<std::string, std::string>);

  std::pair<double, double> GetInterval();
  std::string GetExpression();
  std::string GetResult();

  void AllClean();

  std::pair<std::vector<double>, std::vector<double>> CalculateDataToPlot();
  std::string CalculateExpression();

 private:
  std::string min_plot_interval_ = "-10";
  std::string max_plot_interval_ = "10";
  std::string expression_;
  std::string variable_parameter_;
  std::string result_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CALCULATOR_FACADE_H
