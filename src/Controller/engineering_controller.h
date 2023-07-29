#ifndef CPP3_SMARTCALC_V2_0_1_CONTROLLER_H
#define CPP3_SMARTCALC_V2_0_1_CONTROLLER_H

#include <string>

#include "../Model/EnigineeringCalculator/engineering_calculator_facade.h"

namespace s21 {

class EngineeringController {
 public:
  EngineeringController();
  ~EngineeringController();

  void CalculateExpression(std::string expression,
                           std::string variable_parameter);
  std::pair<std::vector<double>, std::vector<double>> CalculateDataToPlot(
      std::pair<std::string, std::string> interval);

  void AllClean();

  void SetExpression(std::string expression);
  void SetVariable(std::string variable_parameter);
  void SetInterval(std::pair<std::string, std::string> interval);

  std::string GetVariableParameter();
  std::string GetExpression();
  std::string GetResult();
  std::pair<double, double> GetInterval();

 private:
  EnigineeringCalculatorFacade *calculator_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CONTROLLER_H
