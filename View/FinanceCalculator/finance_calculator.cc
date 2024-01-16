#include "finance_calculator.h"

#include "ui_finance_calculator.h"

FinanceCalculator::FinanceCalculator(QWidget *parent)
    : QWidget(parent), ui(new Ui::FinanceCalculator) {
  finance_controller_ = new s21::FinanceController;

  ui->setupUi(this);
  this->setFixedSize(QSize(1400, 470));
  auto numeric_valid =
      new QDoubleValidator(0.00000000000000001, 1000000, 6, this);
  numeric_valid->setNotation(QDoubleValidator::StandardNotation);
  ui->input_sum_credit->setValidator(numeric_valid);
  ui->input_period_credit->setValidator(numeric_valid);
  ui->input_rate_credit->setValidator(numeric_valid);

  ui->input_sum_credit->setText("");

  connect(ui->calculate_credit, SIGNAL(clicked()), this,
          SLOT(CalculateCredit()));
}

void FinanceCalculator::CalculateCredit() {
  int type = ui->radioButton_a->isChecked() ? 1 : 0;
  ui->month_table->setRowCount(0);
  if (finance_controller_->CalculateCredit(
          type, ui->input_sum_credit->text().toDouble(),
          ui->input_period_credit->text().toInt(),
          ui->input_rate_credit->text().toDouble())) {
    std::vector<double> monthly_payments =
        finance_controller_->GetMonthlyPayments();
    for (int i = 0; i < ui->input_period_credit->text().toInt(); ++i) {
      ui->month_table->insertRow(i);
      ui->month_table->setItem(i, 0,
                               new QTableWidgetItem(QString::number(i + 1)));
      ui->month_table->setItem(
          i, 1, new QTableWidgetItem(QString::number(monthly_payments[i])));
    }
    ui->output_sum_credit->setText(
        QString::number(finance_controller_->GetFinalSum()));
    ui->output_overpayment_credit->setText(
        QString::number(finance_controller_->GetOverpayment()));
  }
}

FinanceCalculator::~FinanceCalculator() {
  delete ui;
  delete finance_controller_;
}
