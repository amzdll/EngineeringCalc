#include "engineering_calculator.h"

#include <QDoubleValidator>
#include <utility>

#include "ui_engineering_calculator.h"

EngineeringCalculator::EngineeringCalculator(QWidget *parent)
    : QWidget(parent), ui(new Ui::EngineeringCalculator) {
  ui->setupUi(this);
  this->setFixedSize(QSize(1400, 470));
  connect_buttons();
  auto numeric_valid = new QDoubleValidator(-1000000000, 1000000000, 6, this);
  auto interval_valid = new QDoubleValidator(-1000000, 1000000, 6, this);
  numeric_valid->setNotation(QDoubleValidator::StandardNotation);
  interval_valid->setNotation(QDoubleValidator::StandardNotation);
  ui->variable_input->setValidator(numeric_valid);
  ui->min_y->setValidator(interval_valid);
  ui->max_y->setValidator(interval_valid);

  engineering_controller_ = new s21::EngineeringController();
  std::pair<double, double> init_interval =
      engineering_controller_->GetInterval();
  ui->min_y->setText(QString::number(init_interval.first));
  ui->max_y->setText(QString::number(init_interval.second));
}

EngineeringCalculator::~EngineeringCalculator() {
  delete ui;
  delete engineering_controller_;
}

void EngineeringCalculator::connect_buttons() {
  for (auto but : ui->Digits->buttons()) {
    connect(but, SIGNAL(clicked()), this, SLOT(AddOperand()));
  }
  for (auto but : ui->Operations->buttons()) {
    connect(but, SIGNAL(clicked()), this, SLOT(AddOperand()));
  }
  for (auto but : ui->Functions->buttons()) {
    connect(but, SIGNAL(clicked()), this, SLOT(AddOperand()));
  }
  connect(ui->AllClean, SIGNAL(clicked()), this, SLOT(AllClean()));
  connect(ui->Clean, SIGNAL(clicked()), this, SLOT(Clean()));
  connect(ui->GetResult, SIGNAL(clicked()), this, SLOT(GetResult()));
  connect(ui->Plot, SIGNAL(clicked()), this, SLOT(DrawPlot()));
}

void EngineeringCalculator::AddOperand() {
  QAbstractButton *button_text = (QAbstractButton *)sender();
  expression_ += button_text->text();
  ui->expression->setText(expression_);
}

void EngineeringCalculator::AllClean() {
  engineering_controller_->AllClean();
  expression_ =
      QString::fromStdString(engineering_controller_->GetExpression());
  ui->expression->setText(expression_);
}

void EngineeringCalculator::Clean() {
  expression_.chop(1);
  ui->expression->setText(expression_);
}

void EngineeringCalculator::GetResult() {
  engineering_controller_->CalculateExpression(
      expression_.toStdString(), (ui->variable_input->text()).toStdString());
  expression_ =
      QString::fromStdString(engineering_controller_->GetExpression());
  ui->expression->setText(
      QString::fromStdString(engineering_controller_->GetResult()));
}

void EngineeringCalculator::DrawPlot() {
  engineering_controller_->SetExpression(expression_.toStdString());
  std::pair<std::vector<double>, std::vector<double>> coordinates =
      engineering_controller_->CalculateDataToPlot(
          std::pair<std::string, std::string>{
              (ui->min_y->text().toStdString()),
              (ui->max_y->text().toStdString())});
  QVector<double> q_x_coordinates =
      QVector<double>(coordinates.first.begin(), coordinates.first.end());
  QVector<double> q_y_coordinates =
      QVector<double>(coordinates.second.begin(), coordinates.second.end());
  ui->widget->xAxis->setRange(q_x_coordinates[0],
                              q_x_coordinates[q_x_coordinates.size() - 1]);
  ui->widget->yAxis->setRange(
      *std::min_element(q_y_coordinates.begin(), q_y_coordinates.end()),
      *std::max_element(q_y_coordinates.begin(), q_y_coordinates.end()));
  ui->widget->addGraph();
  ui->widget->graph(0)->data()->clear();
  ui->widget->graph(0)->addData(q_x_coordinates, q_y_coordinates);
  ui->widget->replot();
}
