#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "../../Controller/engineering_controller.h"
#include "../EngineeringCalculator/engineering_calculator.h"
#include "../FinanceCalculator/finance_calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

  std::string TestMethod();

 private:
  Ui::MainWindow *ui;
  EngineeringCalculator *engineering_calculator_;
  FinanceCalculator *credit_calculator_;
};
#endif  // MAINWINDOW_H
