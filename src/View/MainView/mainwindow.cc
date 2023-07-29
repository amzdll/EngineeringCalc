#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setFixedSize(QSize(1400, 470));

  engineering_calculator_ = new EngineeringCalculator(this);
  credit_calculator_ = new FinanceCalculator(this);

  ui->tabWidget->addTab(engineering_calculator_, "Engineering Calculator");
  ui->tabWidget->addTab(credit_calculator_, "Finance Calculator");
}

MainWindow::~MainWindow() {
  delete engineering_calculator_;
  delete credit_calculator_;
  delete ui;
}

std::string MainWindow::TestMethod() { return ""; }
