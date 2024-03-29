#ifndef CPP3_SMARTCALC_VIEW_GRAPH_WINDOW_H
#define CPP3_SMARTCALC_VIEW_GRAPH_WINDOW_H

#include <QMainWindow>

#include "../qcustomplot/qcustomplot.h"
#include "main_window.h"

#define MAX_XY 1000000
#define DOTS 100000

class MainWindow;

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit GraphWindow(QWidget *parent = nullptr);
  ~GraphWindow();

 private slots:
  void ClickBuild();

 private:
  Ui::GraphWindow *ui;
  void SetDefault();
  void SetError();
  void GetRangeY(QVector<double> y, double *min_y, double *max_y);
  void showEvent(QShowEvent *event);
};

#endif  // CPP3_SMARTCALC_VIEW_GRAPH_WINDOW_H
