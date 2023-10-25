#ifndef CPP3_SMARTCALC_VIEW_X_WINDOW_H
#define CPP3_SMARTCALC_VIEW_X_WINDOW_H

#include <QDialog>

#include "main_window.h"

class MainWindow;

namespace Ui {
class XWindow;
}

class XWindow : public QDialog {
  Q_OBJECT

 public:
  explicit XWindow(QWidget *parent = nullptr);
  ~XWindow();

 private slots:
  void ClickApply();
  void ClickCancel();

 private:
  Ui::XWindow *ui;

  void SetDefault();
  void showEvent(QShowEvent *event);
};

#endif  // CPP3_SMARTCALC_VIEW_X_WINDOW_H
