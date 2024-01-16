#include "engineering_controller.h"

#include <utility>

namespace s21 {

EngineeringController::EngineeringController() {
  calculator_ = new EnigineeringCalculatorFacade;
}

EngineeringController::~EngineeringController() { delete calculator_; }

void EngineeringController::CalculateExpression(
    std::string expression, std::string variable_parameter) {
  calculator_->SetExpression(expression);
  calculator_->SetVariable(std::move(variable_parameter));
  calculator_->CalculateExpression();
}

std::pair<std::vector<double>, std::vector<double>>
EngineeringController::CalculateDataToPlot(
    std::pair<std::string, std::string> interval) {
  calculator_->SetInterval(interval);
  return calculator_->CalculateDataToPlot();
}

void EngineeringController::AllClean() { calculator_->AllClean(); }

void EngineeringController::SetExpression(std::string expression) {
  calculator_->SetExpression(expression);
}

void EngineeringController::SetVariable(std::string variable_parameter) {
  calculator_->SetExpression(std::move(variable_parameter));
}

void EngineeringController::SetInterval(
    std::pair<std::string, std::string> interval) {
  calculator_->SetInterval(interval);
}

std::string EngineeringController::GetExpression() {
  return calculator_->GetExpression();
}

std::string EngineeringController::GetResult() {
  return calculator_->GetResult();
}

std::pair<double, double> EngineeringController::GetInterval() {
  return calculator_->GetInterval();
}

}  //  namespace s21
