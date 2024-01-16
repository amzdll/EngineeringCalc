#include "finance_controller.h"

namespace s21 {

FinanceController::FinanceController() {
  credit_calc_ = new FinanceCalculatorModel;
}

FinanceController::~FinanceController() { delete credit_calc_; }

bool FinanceController::CalculateCredit(int type_of_credit, double sum,
                                        int period, double rate) {
  if (type_of_credit) {
    return credit_calc_->AnnuityCredit(sum, period, rate);
  } else {
    return credit_calc_->DifferentiatedCredit(sum, period, rate);
  }
}

double FinanceController::GetFinalSum() { return credit_calc_->GetFinalSum(); }

double FinanceController::GetOverpayment() {
  return credit_calc_->GetOverpayment();
}

std::vector<double> FinanceController::GetMonthlyPayments() {
  return credit_calc_->GetMonthlyPayments();
}

}  // namespace s21