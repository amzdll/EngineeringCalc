#include "engineering_calculator_facade.h"

#include <utility>
namespace s21 {
std::string EnigineeringCalculatorFacade::CalculateExpression() {
  if (s21::Validator::IsExpressionValid(expression_) == 1) {
    auto postfix_expression_ = s21::Converter::StringToPostfix(expression_);
    result_ = std::to_string(
        s21::Calculator::CalculatePostfix(postfix_expression_, 0));
    expression_ = result_;
  } else if (s21::Validator::IsExpressionValid(expression_) == 2 &&
             variable_parameter_ != "+" && variable_parameter_ != "-" &&
             variable_parameter_ != "." && !variable_parameter_.empty()) {
    auto postfix_expression_ = s21::Converter::StringToPostfix(expression_);
    result_ = std::to_string(s21::Calculator::CalculatePostfix(
        postfix_expression_, std::stod(variable_parameter_)));
    expression_ = result_;
  } else {
    variable_parameter_ = "";
    expression_ = "";
    result_ = "Invalid expression";
  }
  return result_;
}

std::pair<std::vector<double>, std::vector<double>>
EnigineeringCalculatorFacade::CalculateDataToPlot() {
  std::vector<double> x_coordinates;
  std::vector<double> y_coordinates;
  if (s21::Validator::IsExpressionValid(expression_) &&
      s21::Validator::IsPlotRangeValid(min_plot_interval_,
                                       max_plot_interval_)) {
    double interval_step =
        (stod(max_plot_interval_) - stod(min_plot_interval_)) / 500;
    auto postfix_expression_ = s21::Converter::StringToPostfix(expression_);
    double y_coordinate;
    for (double i = stod(min_plot_interval_); i < stod(max_plot_interval_);
         i += interval_step) {
      x_coordinates.push_back(i);
      y_coordinate = s21::Calculator::CalculatePostfix(postfix_expression_, i);
      y_coordinates.push_back(y_coordinate);
    }
  } else {
    x_coordinates.push_back(0);
    y_coordinates.push_back(0);
  }
  return std::pair<std::vector<double>, std::vector<double>>{x_coordinates,
                                                             y_coordinates};
}

void EnigineeringCalculatorFacade::AllClean() {
  expression_ = "";
  variable_parameter_ = "";
}

std::string EnigineeringCalculatorFacade::GetExpression() {
  return expression_;
}

std::string EnigineeringCalculatorFacade::GetResult() { return result_; }

std::pair<double, double> EnigineeringCalculatorFacade::GetInterval() {
  return std::pair{std::stod(min_plot_interval_),
                   std::stod(max_plot_interval_)};
}

void EnigineeringCalculatorFacade::SetExpression(std::string expression) {
  expression_ = expression;
}

void EnigineeringCalculatorFacade::SetVariable(std::string variable_parameter) {
  variable_parameter_ = std::move(variable_parameter);
}

void EnigineeringCalculatorFacade::SetInterval(
    std::pair<std::string, std::string> interval) {
  min_plot_interval_ = interval.first;
  max_plot_interval_ = interval.second;
}

}  // namespace s21
