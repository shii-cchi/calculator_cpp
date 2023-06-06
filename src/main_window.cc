#include "main_window.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("Калькулятор");
  graph_window = new GraphWindow(this);
  credit_window = new CreditWindow();
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
  if (window.length() ==  1) {
    window = "0";
  } else {
    char last_symbol;

    do {
      window = window.chopped(1);
      last_symbol = window[window.length() - 1].toLatin1();
    } while (last_symbol != '(' && last_symbol != ' ' &&
             window.length() > 1 && last_symbol != '.' && last_symbol != '^' && !isdigit(last_symbol));

    if (last_symbol == ' ' && (isdigit(window[window.length() - 2].toLatin1()) || window[window.length() - 2].toLatin1() == 'x')) {
      window = window.chopped(1);
    }
  }

  if (window.length() == 1 && !isdigit(window[window.length() - 1].toLatin1()) && window[window.length() - 1].toLatin1() != '-' && window[window.length() - 1].toLatin1() != 'x') {
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
    if (ui->result_window->text().indexOf('x') == -1) {
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
      graph_window->show();
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

void MainWindow::GetNewX(double x) {
  QString data = ui->result_window->text().replace('x', "(" + QString::number(x) + ")");
  bool status;
  double result = GetResult(data, &status);
  ui->result_window->setText(QString::number(result, 'f', 7));
}

double MainWindow::GetYValue(double x) {
  QString data = ui->result_window->text().replace('x', "(" + QString::number(x) + ")");
  bool status;
  double result = GetResult(data, &status);
  return result;
}

