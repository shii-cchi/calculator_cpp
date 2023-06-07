#ifndef SRC_GRAPH_WINDOW_H
#define SRC_GRAPH_WINDOW_H

#include <QMainWindow>

#include "qcustomplot.h"
#include "main_window.h"

#define MAX_XY 1000000
#define DOTS 10000

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
  void showEvent(QShowEvent *event);
};

#endif  // SRC_GRAPH_WINDOW_H
