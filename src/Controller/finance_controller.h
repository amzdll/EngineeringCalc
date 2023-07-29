#ifndef CPP3_SMARTCALC_V2_0_1_FINANCE_CONTROLLER_H
#define CPP3_SMARTCALC_V2_0_1_FINANCE_CONTROLLER_H

#include "../Model/FinanceCalculator/finance_calculator_model.h"

namespace s21 {

class FinanceController {
 public:
  FinanceController();
  ~FinanceController();

  bool CalculateCredit(int type_of_credit, double sum, int period, double rate);
  double GetFinalSum();
  double GetOverpayment();
  std::vector<double> GetMonthlyPayments();

 private:
  FinanceCalculatorModel *credit_calc_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_0_1_FINANCE_CONTROLLER_H
