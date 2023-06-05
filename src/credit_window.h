#ifndef SRC_CREDIT_WINDOW_H
#define SRC_CREDIT_WINDOW_H

#include <QMainWindow>

#include "credit_calculations.h"

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit CreditWindow(QWidget *parent = nullptr);
  ~CreditWindow();

 private slots:
  void on_run_count_clicked();

 private:
  Ui::CreditWindow *ui;

  void Clear();
  QString GetCreditType();
  bool isEmptyFields();
};

#endif  // SRC_CREDIT_WINDOW_H
