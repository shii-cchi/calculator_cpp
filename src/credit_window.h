#ifndef SRC_CREDIT_WINDOW_H
#define SRC_CREDIT_WINDOW_H

#include <QMainWindow>

#include "credit_calculations.h"

#define ERROR_MESSAGE_1 "Неверные данные"
#define ERROR_MESSAGE_2 "Все поля должны быть заполнены"

namespace Ui {
class CreditWindow;
}

class CreditWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit CreditWindow(QWidget *parent = nullptr);
  ~CreditWindow();

 private slots:
  void ClickRunCount();

 private:
  Ui::CreditWindow *ui;

  QString GetCreditType();
  bool IsEmptyFields();
  void SetDefault();
  void showEvent(QShowEvent *event);
};

#endif  // SRC_CREDIT_WINDOW_H
