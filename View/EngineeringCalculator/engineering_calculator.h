#ifndef ENGINEERING_CALCULATOR_H
#define ENGINEERING_CALCULATOR_H

#include <QAbstractButton>
#include <QWidget>

#include "../../Controller/engineering_controller.h"

namespace Ui {
class EngineeringCalculator;
}

class EngineeringCalculator : public QWidget {
  Q_OBJECT

 public:
  explicit EngineeringCalculator(QWidget *parent = nullptr);
  ~EngineeringCalculator();

 private:
  QString expression_ = "";

  Ui::EngineeringCalculator *ui;
  s21::EngineeringController *engineering_controller_;

  void connect_buttons();

 private slots:
  void AddOperand();
  void AllClean();
  void Clean();
  void GetResult();
  void DrawPlot();
};

#endif  // ENGINEERING_CALCULATOR_H
