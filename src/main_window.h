#ifndef SRC_MAIN_WINDOW_H
#define SRC_MAIN_WINDOW_H

#include <QMainWindow>
#include <QSplineSeries>
#include <QValueAxis>
#include <QtCharts>

#include "credit_window.h"
#include "axis_window.h"
#include "x_window.h"
#include "graph_window.h"
#include "calculations.h"

class AxisWindow;
class XWindow;

#define MAX_XY 1000000

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

  void PlotGraph(int max_x, int min_x);
  void GetNewX(double x);

 private:
  Ui::MainWindow *ui;
  Graph_Window *graph_window;
  CreditWindow *credit_window;
  AxisWindow *axis_window;
  XWindow *x_window;

  int CheckValidData(QString data);
  QString ReplaceUnary();
  QSplineSeries *GetSeries(QString data, int max_x, int min_x);
  QString GetNewWindow(QString button_text, int flag);
  double GetResult(QString data, double i);
  int GetStep(int max_x, int min_x);

 private slots:
  void ClickNumbersAndBrackets();
  void ClickPowAndDot();
  void ClickOperators();
  void ClickFunctions();
  void ClickUnaryOperators();

  void ClickDeleteAll();
  void ClickDeleteSymbol();
  
  void ClickEqual()();
  void ClickGraph();
  void ClickCredit()();
};

#endif  // SRC_MAIN_WINDOW_H
