// #ifndef SRC_HEADERS_CALCULATOR_H
// #define SRC_HEADERS_CALCULATOR_H
#ifndef SRC_CALCULATOR_H
#define SRC_CALCULATOR_H

#include <QMainWindow>
#include <QSplineSeries>
#include <QValueAxis>
#include <QtCharts>

#include "credit.h"
#include "custom_axis.h"
#include "graph.h"
#include "calculations.h"

class CustomAxis;

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
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  Graph *graph_window;
  Credit *credit_window;
  CustomAxis *custom_axis;
  int check_valid_data(QString data);
  char *qstring_to_char(QString qstr);
  QString replace_unary();
  QSplineSeries *get_series(QString data, int max_x, int min_x);
  QString get_new_window(QString button_text, int flag);
  double get_result(QString data, int i);
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
//#endif  // SRC_HEADERS_CALCULATOR_H
#endif  // SRC_CALCULATOR_H
