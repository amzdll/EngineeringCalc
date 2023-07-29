#include "finance_calculator_model.h"

#include "cmath"
#include "iostream"

namespace s21 {
bool FinanceCalculatorModel::AnnuityCredit(double sum, int period,
                                           double rate) {
  credit_monthly_payments_.clear();
  if (sum <= 0 && period <= 0 && rate <= 0) {
    return false;
  }
  double monthly_payment;
  credit_final_sum_ = 0;
  rate = rate / (12.0 * 100.0);
  monthly_payment = (sum * rate) / (1 - (pow(1.0 + rate, -(double)period)));
  credit_final_sum_ = monthly_payment * period;
  for (int i = 0; i < period; i++) {
    credit_monthly_payments_.push_back(monthly_payment);
  }
  credit_overpayment_ = credit_final_sum_ - sum;
  return true;
}

bool FinanceCalculatorModel::DifferentiatedCredit(double sum, int period,
                                                  double rate) {
  credit_monthly_payments_.clear();
  if (sum <= 0 && period <= 0 && rate <= 0) {
    return false;
  }
  double monthly_payment;
  double fixed_payment = sum / (double)period;
  rate = rate / (12.0 * 100.0);
  for (int i = 0; i < period; i++) {
    monthly_payment = fixed_payment + (sum - fixed_payment * (double)i) * rate;
    credit_monthly_payments_.push_back(monthly_payment);
    credit_final_sum_ += monthly_payment;
  }
  credit_overpayment_ = credit_final_sum_ - sum;

  return true;
}

double FinanceCalculatorModel::GetFinalSum() { return credit_final_sum_; }

double FinanceCalculatorModel::GetOverpayment() { return credit_overpayment_; }

std::vector<double> FinanceCalculatorModel::GetMonthlyPayments() {
  return credit_monthly_payments_;
}
}  // namespace s21