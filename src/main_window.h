#ifndef SRC_MAIN_WINDOW_H
#define SRC_MAIN_WINDOW_H

#include <QMainWindow>

#include "credit_window.h"
#include "x_window.h"
#include "graph_window.h"
#include "calculations.h"

class GraphWindow;
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

  void GetNewX(double x);
  double GetYValue(double x);

 private:
  Ui::MainWindow *ui;
  GraphWindow *graph_window;
  CreditWindow *credit_window;
  XWindow *x_window;

  double GetResult(QString data, bool *status);
  QString GetNewWindow(QString button_text, int flag);

 private slots:
  void ClickNumbersAndBrackets();
  void ClickPowAndDot();
  void ClickOperators();
  void ClickFunctions();
  void ClickUnaryOperators();

  void ClickDeleteAll();
  void ClickDeleteSymbol();
  
  void ClickEqual();
  void ClickGraph();
  void ClickCredit();
};

#endif  // SRC_MAIN_WINDOW_H
