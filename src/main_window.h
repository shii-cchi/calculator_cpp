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
  void plot_graph(int max_x, int min_x);
  void get_new_x(double x);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Graph_Window *graph_window;
  CreditWindow *credit_window;
  AxisWindow *axis_window;
  XWindow *x_window;

  int check_valid_data(QString data);
  QString replace_unary();
  QSplineSeries *get_series(QString data, int max_x, int min_x);
  QString get_new_window(QString button_text, int flag);
  double get_result(QString data, double i);
  int get_step(int max_x, int min_x);

 private slots:
  void click_numbers();
  void on_pushButton_delete_all_clicked();
  void on_pushButton_delete_1_clicked();
  void on_pushButton_dot_clicked();
  void click_operators();
  void click_bracket();
  void on_pushButton_pow_clicked();
  void click_func();
  void on_pushButton_unary_clicked();
  void on_pushButton_equal_clicked();
  void on_pushButton_graph_clicked();
  void on_pushButton_credit_clicked();
};

#endif  // SRC_MAIN_WINDOW_H
