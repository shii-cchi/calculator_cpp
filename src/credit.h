// #ifndef SRC_HEADERS_CREDIT_H
// #define SRC_HEADERS_CREDIT_H
#ifndef SRC_CREDIT_H
#define SRC_CREDIT_H

#include <QMainWindow>

#include "credit_calculations.h"

namespace Ui {
class Credit;
}

class Credit : public QMainWindow {
  Q_OBJECT

 public:
  explicit Credit(QWidget *parent = nullptr);
  ~Credit();

 private slots:
  void on_run_count_clicked();

 private:
  Ui::Credit *ui;

  void clear();
  QString get_credit_type();
  int fields_is_empty();
};

//#endif  // SRC_HEADERS_CREDIT_H
#endif  // SRC_CREDIT_H
