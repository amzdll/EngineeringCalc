#ifndef FINANCE_CALCULATOR_H
#define FINANCE_CALCULATOR_H

#include <QWidget>

#include "../../Controller/finance_controller.h"

namespace Ui {
class FinanceCalculator;
}

class FinanceCalculator : public QWidget {
  Q_OBJECT

 public:
  explicit FinanceCalculator(QWidget *parent = nullptr);
  ~FinanceCalculator();

 private:
  s21::FinanceController *finance_controller_;
  Ui::FinanceCalculator *ui;

 private slots:
  void CalculateCredit();
};

#endif  // FINANCE_CALCULATOR_H
