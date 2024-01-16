#ifndef CPP3_SMARTCALC_V2_0_1_CREDIT_CALCULATOR_H
#define CPP3_SMARTCALC_V2_0_1_CREDIT_CALCULATOR_H

#include <cmath>
#include <vector>

namespace s21 {

class FinanceCalculatorModel {
 public:
  bool AnnuityCredit(double sum, int period, double rate);
  bool DifferentiatedCredit(double sum, int period, double rate);

  bool CalculateDeposit(double sum, int period, int period_of_payments,
                        double rate, double tax_rate);

  double GetFinalSum();
  double GetOverpayment();
  std::vector<double> GetMonthlyPayments();

 private:
  double credit_final_sum_;
  double credit_overpayment_;
  std::vector<double> credit_monthly_payments_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_CREDIT_CALCULATOR_H
