#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("Калькулятор");
  graph_window = new Graph_Window();
  credit_window = new CreditWindow();
  axis_window = new AxisWindow(this);
  x_window = new XWindow(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));

  connect(ui->pushButton_bracket_1, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_bracket_2, SIGNAL(clicked()), this, SLOT(ClickNumbersAndBrackets()));

  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(ClickPowAndDot()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(ClickPowAndDot()));

  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(ClickOperators()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this, SLOT(ClickOperators()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(ClickOperators()));
  connect(ui->pushButton_divide, SIGNAL(clicked()), this, SLOT(ClickOperators()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(ClickOperators()));

  connect(ui->pushButton_lg, SIGNAL(clicked()), this, SLOT(ClickFunctions()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(ClickFunctions()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(ClickFunctions()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(ClickFunctions()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(ClickFunctions()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(ClickFunctions()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(ClickFunctions()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(ClickFunctions()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(ClickFunctions()));

  connect(ui->pushButton_unary, SIGNAL(clicked()), this, SLOT(ClickUnaryOperators()));

  connect(ui->pushButton_delete_all, SIGNAL(clicked()), this, SLOT(ClickDeleteAll()));
  connect(ui->pushButton_delete_1, SIGNAL(clicked()), this, SLOT(ClickDeleteSymbol()));

  connect(ui->pushButton_equal, SIGNAL(clicked()), this, SLOT(ClickEqual()));
  connect(ui->pushButton_graph, SIGNAL(clicked()), this, SLOT(ClickGraph()));
  connect(ui->pushButton_credit, SIGNAL(clicked()), this, SLOT(ClickCredit()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::ClickNumbersAndBrackets() {
  QPushButton *button = (QPushButton *)sender();
  ui->result_window->setText(GetNewWindow(button->text(), 2));
}

void MainWindow::ClickPowAndDot() {
  QPushButton *button = (QPushButton *)sender();
  ui->result_window->setText(GetNewWindow(button->text(), 1));
}

void MainWindow::ClickOperators() {
  QPushButton *button = (QPushButton *)sender();
  QString button_text = " " + button->text() + " ";
  ui->result_window->setText(GetNewWindow(button_text, 1));
}

void MainWindow::ClickFunctions() {
  QPushButton *button = (QPushButton *)sender();
  QString button_text = button->text() + "(";
  ui->result_window->setText(GetNewWindow(button_text, 2));
}

void MainWindow::ClickUnaryOperators() {
  if (ui->result_window->text().last(1) == " " ||
      ui->result_window->text().last(1) == "(" ||
      ui->result_window->text().last(1) == "0") {

    ui->result_window->setText(GetNewWindow("-", 2));
  }
}

void MainWindow::ClickDeleteAll() {
  ui->result_window->setText("0");
}

void MainWindow::ClickDeleteSymbol() {
  QString window = ui->result_window->text();
  if (window == "Ошибка ввода") {
    window = "0";
  }
  if (window.length() > 1) {
    do {
      window = window.chopped(1);
    } while (window.last(1) != "(" && window.last(1) != " " &&
             window.length() > 1);

    if (window.last(1) == " ") {
      window = window.chopped(1);
    }
  }
  if (window.length() == 1) {
    window = "0";
  }
  ui->result_window->setText(window);
}

void MainWindow::ClickEqual() {
  if (ui->result_window->text() == "Ошибка ввода") {
    ui->result_window->setText("0");
  }

  bool status;
  double result = GetResult(ui->result_window->text(), &status);
 
  if (status) {
    if (data.indexOf('x') == -1) {
      ui->result_window->setText(QString::number(result, 'f', 7));
    } else {
      x_window->show();
    }
  } else {
    ui->result_window->setText("Ошибка ввода");
  }
}

void MainWindow::ClickGraph() {
  if (ui->result_window->text().indexOf('x') != -1) {
    graph_window->close();

    bool status;
    GetResult(ui->result_window->text(), &status);

    if (status) {
      axis_window->show();
    } else {
      ui->result_window->setText("Ошибка ввода");
    }
  }
}

void MainWindow::ClickCredit() { credit_window->show(); }

QString MainWindow::GetNewWindow(QString button_text, int flag) {
  QString new_window;
  if (flag == 2 && (ui->result_window->text() == "0" ||
                    ui->result_window->text() == "Ошибка ввода")) {
    new_window = button_text;
  } else if (flag == 1 && ui->result_window->text() == "Ошибка ввода") {
    new_window = button_text;
  } else {
    new_window = ui->result_window->text() + button_text;
  }
  return new_window;
}

double MainWindow::GetResult(QString data, bool *status) {
  bool status_calc = false;
  std::string str_x= data.toUtf8().constData();

  s21::Calculations calc;
  double result = calc.Calculate(str_x, &status_calc);
  *status = status_calc;
  return result;
}

void MainWindow::PlotGraph(int max_x, int min_x) {
  QChart *chart = new QChart();
  chart->legend()->hide();

  QString data = ReplaceUnary();

  QSplineSeries *series = GetSeries(data, max_x, min_x);
  chart->addSeries(series);

  QValueAxis *axis_x = new QValueAxis;
  QValueAxis *axis_y = new QValueAxis;
  chart->addAxis(axis_x, Qt::AlignBottom);
  chart->addAxis(axis_y, Qt::AlignLeft);
  axis_x->setLabelFormat("%.6g");
  axis_y->setLabelFormat("%.6g");

  series->attachAxis(axis_x);
  series->attachAxis(axis_y);

  QChartView *chartView = new QChartView(chart);
  chartView->setRenderHint(QPainter::Antialiasing);

  graph_window->setCentralWidget(chartView);
  graph_window->show();
}

QString MainWindow::ReplaceUnary() {
  QString tmp = ui->result_window->text();
  for (int i = 0; i < tmp.length(); i++) {
    if (tmp[i] == '-' && tmp[i + 1] != ' ') {
      tmp.replace(i, 1, "(-1) * ");
      i += 7;
    }
  }
  return tmp;
}

QSplineSeries *MainWindow::GetSeries(QString data, int max_x, int min_x) {
  QSplineSeries *series = new QSplineSeries();

  int step = GetStep(max_x, min_x);

  if ((data.indexOf("sin") != -1 || data.indexOf("cos") != -1) &&
      (step >= 10 || max_x - min_x == 2000)) {
    step *= 10;
  }

  for (double i = min_x; i <= max_x; i += step) {
    series->append(i, Get_Result(data, i));

    if (step > 1) {
      if (i + step == 0) {
        series->append(-1, Get_Result(data, -1));
      }

      if (i == 0) {
        series->append(1, Get_Result(data, 1));
      }
    }
  }

  return series;
}

void MainWindow::GetNewX(double x) {
  QString data = ReplaceUnary();
  double res = Get_Result(data, x);
  ui->result_window->setText(QString::number(res, 'f', 7));
}

double MainWindow::Get_Result(QString data, double i) {
  QString tmp = data;
  std::string str_without_x = tmp.replace('x', "(" + QString::number(i) + ")").toUtf8().constData();

  s21::Calculations calc;

  double res = 0;
  calc.Calculate(str_without_x, &res);
  return res;
}

int MainWindow::GetStep(int max_x, int min_x) {
  int step = 1;

  if (max_x - min_x > 2000 && max_x - min_x <= 20000) {
    step = 10;
  } else if (max_x - min_x > 20000 && max_x - min_x <= 200000) {
    step = 1000;
  } else if (max_x - min_x > 200000) {
    step = 10000;
  }

  return step;
}
