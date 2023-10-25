#ifndef CPP3_SMARTCALC_VIEW_CREDIT_WINDOW_H
#define CPP3_SMARTCALC_VIEW_CREDIT_WINDOW_H

#include <QMainWindow>

#include "../controller/controller.h"

#define ERROR_MESSAGE_2 "Неверные данные"
#define ERROR_MESSAGE_3 "Все поля должны быть заполнены"

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

#endif  // CPP3_SMARTCALC_VIEW_CREDIT_WINDOW_H
