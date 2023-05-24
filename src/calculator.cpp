//#include "../headers/calculator.h"
#include "calculator.h"

#include "ui_calculator.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("Калькулятор");
  graph_window = new Graph();
  credit_window = new Credit();
  custom_axis = new CustomAxis(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(click_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(click_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(click_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(click_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(click_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(click_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(click_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(click_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(click_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(click_numbers()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this, SLOT(click_numbers()));

  connect(ui->pushButton_plus, SIGNAL(clicked()), this,
          SLOT(click_operators()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(click_operators()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this,
          SLOT(click_operators()));
  connect(ui->pushButton_divide, SIGNAL(clicked()), this,
          SLOT(click_operators()));
  connect(ui->pushButton_mod, SIGNAL(clicked()), this, SLOT(click_operators()));

  connect(ui->pushButton_bracket_1, SIGNAL(clicked()), this,
          SLOT(click_bracket()));
  connect(ui->pushButton_bracket_2, SIGNAL(clicked()), this,
          SLOT(click_bracket()));

  connect(ui->pushButton_lg, SIGNAL(clicked()), this, SLOT(click_func()));
  connect(ui->pushButton_ln, SIGNAL(clicked()), this, SLOT(click_func()));
  connect(ui->pushButton_sqrt, SIGNAL(clicked()), this, SLOT(click_func()));
  connect(ui->pushButton_sin, SIGNAL(clicked()), this, SLOT(click_func()));
  connect(ui->pushButton_cos, SIGNAL(clicked()), this, SLOT(click_func()));
  connect(ui->pushButton_tan, SIGNAL(clicked()), this, SLOT(click_func()));
  connect(ui->pushButton_asin, SIGNAL(clicked()), this, SLOT(click_func()));
  connect(ui->pushButton_acos, SIGNAL(clicked()), this, SLOT(click_func()));
  connect(ui->pushButton_atan, SIGNAL(clicked()), this, SLOT(click_func()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::click_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString button_text = button->text();
  ui->result_window->setText(get_new_window(button_text, 2));
}

void MainWindow::on_pushButton_delete_all_clicked() {
  ui->result_window->setText("0");
}

void MainWindow::on_pushButton_delete_1_clicked() {
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

void MainWindow::on_pushButton_dot_clicked() {
  QString button_text = ".";
  ui->result_window->setText(get_new_window(button_text, 1));
}

void MainWindow::click_operators() {
  QPushButton *button = (QPushButton *)sender();
  QString button_text = " " + button->text() + " ";
  ui->result_window->setText(get_new_window(button_text, 1));
}

void MainWindow::click_bracket() {
  QPushButton *button = (QPushButton *)sender();
  QString button_text = button->text();
  ui->result_window->setText(get_new_window(button_text, 2));
}

void MainWindow::on_pushButton_pow_clicked() {
  if (ui->result_window->text().last(1) != "^") {
    QString button_text = "^";
    ui->result_window->setText(get_new_window(button_text, 1));
  }
}

void MainWindow::click_func() {
  QPushButton *button = (QPushButton *)sender();
  QString button_text = button->text() + "(";
  ui->result_window->setText(get_new_window(button_text, 2));
}

void MainWindow::on_pushButton_unary_clicked() {
  if (ui->result_window->text().last(1) == " " ||
      ui->result_window->text().last(1) == "(" ||
      ui->result_window->text().last(1) == "0") {
    QString button_text = "-";
    ui->result_window->setText(get_new_window(button_text, 2));
  }
}

void MainWindow::on_pushButton_equal_clicked() {
  if (ui->result_window->text() == "Ошибка ввода") {
    ui->result_window->setText("0");
  }

  QString data = ui->result_window->text().replace(".", ",");

  if (data.indexOf('x') == -1) {
    double result = 0;
    char *str_data = qstring_to_char(data);

    int status = calculate(str_data, &result);
    if (status) {
      ui->result_window->setText(QString::number(result, 'f', 7));
    } else {
      ui->result_window->setText("Ошибка ввода");
    }
  }
}

void MainWindow::on_pushButton_graph_clicked() {
  if (ui->result_window->text().indexOf('x') != -1) {
    graph_window->close();

    QString data = ui->result_window->text().replace(".", ",");

    int status = check_valid_data(data);
    if (status) {
      custom_axis->show();
    }
  }
}

void MainWindow::on_pushButton_credit_clicked() { credit_window->show(); }

QString MainWindow::get_new_window(QString button_text, int flag) {
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

int MainWindow::check_valid_data(QString data) {
  char *str_x = qstring_to_char(data);
  double res = 0;
  int status = calculate(str_x, &res);
  if (!status) {
    ui->result_window->setText("Ошибка ввода");
  }
  return status;
}

char *MainWindow::qstring_to_char(QString qstr) {
  QByteArray arr = qstr.toLocal8Bit();
  char *str = arr.data();
  return str;
}

void MainWindow::plot_graph(int max_x, int min_x) {
  QChart *chart = new QChart();
  chart->legend()->hide();

  QString data = replace_unary();

  QSplineSeries *series = get_series(data, max_x, min_x);
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

QString MainWindow::replace_unary() {
  QString tmp = ui->result_window->text().replace(".", ",");
  for (int i = 0; i < tmp.length(); i++) {
    if (tmp[i] == '-' && tmp[i + 1] != ' ') {
      tmp.replace(i, 1, "(-1) * ");
      i += 7;
    }
  }
  return tmp;
}

QSplineSeries *MainWindow::get_series(QString data, int max_x, int min_x) {
  QSplineSeries *series = new QSplineSeries();

  int step = get_step(max_x, min_x);

  if ((data.indexOf("sin") != -1 || data.indexOf("cos") != -1) &&
      (step >= 10 || max_x - min_x == 2000)) {
    step *= 10;
  }

  for (int i = min_x; i <= max_x; i += step) {
    series->append(i, get_result(data, i));

    if (step > 1) {
      if (i + step == 0) {
        series->append(-1, get_result(data, -1));
      }

      if (i == 0) {
        series->append(1, get_result(data, 1));
      }
    }
  }

  return series;
}

double MainWindow::get_result(QString data, int i) {
  QString tmp = data;
  char *str_without_x =
      qstring_to_char(tmp.replace('x', "(" + QString::number(i) + ")"));
  double res = 0;
  calculate(str_without_x, &res);
  return res;
}

int MainWindow::get_step(int max_x, int min_x) {
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
