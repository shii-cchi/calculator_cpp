#ifndef SRC_AXIS_WINDOW_H
#define SRC_AXIS_WINDOW_H

#include <QDialog>

#include "main_window.h"

class MainWindow;

namespace Ui {
class AxisWindow;
}

class AxisWindow : public QDialog {
  Q_OBJECT

 public:
  explicit AxisWindow(MainWindow *parent = nullptr);
  ~AxisWindow();

 private slots:
  void ClickApply();
  void ClickCancel();

 private:
  Ui::AxisWindow *ui;

  void SetDefault();
};

#endif  // SRC_AXIS_WINDOW_H
