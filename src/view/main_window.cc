#include "main_window.h"

#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("Калькулятор");
  graph_window = new GraphWindow(this);
  credit_window = new CreditWindow();
  x_window = new XWindow(this);

  connect(ui->pushButton_0, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_x, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));

  connect(ui->pushButton_bracket_1, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));
  connect(ui->pushButton_bracket_2, SIGNAL(clicked()), this,
          SLOT(ClickNumbersAndBrackets()));

  connect(ui->pushButton_pow, SIGNAL(clicked()), this, SLOT(ClickPowAndDot()));
  connect(ui->pushButton_dot, SIGNAL(clicked()), this, SLOT(ClickPowAndDot()));

  connect(ui->pushButton_plus, SIGNAL(clicked()), this, SLOT(ClickOperators()));
  connect(ui->pushButton_minus, SIGNAL(clicked()), this,
          SLOT(ClickOperators()));
  connect(ui->pushButton_mult, SIGNAL(clicked()), this, SLOT(ClickOperators()));
  connect(ui->pushButton_divide, SIGNAL(clicked()), this,
          SLOT(ClickOperators()));
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

  connect(ui->pushButton_unary, SIGNAL(clicked()), this,
          SLOT(ClickUnaryOperators()));

  connect(ui->pushButton_delete_all, SIGNAL(clicked()), this,
          SLOT(ClickDeleteAll()));
  connect(ui->pushButton_delete_1, SIGNAL(clicked()), this,
          SLOT(ClickDeleteSymbol()));

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
      ui->result_window->text().last(1) == START_MESSAGE) {
    ui->result_window->setText(GetNewWindow("-", 2));
  }
}

void MainWindow::ClickDeleteAll() { ui->result_window->setText(START_MESSAGE); }

void MainWindow::ClickDeleteSymbol() {
  QString new_window = ui->result_window->text();

  if (new_window == ERROR_MESSAGE_1 || new_window.length() == 1) {
    new_window = START_MESSAGE;
  }

  if (new_window.length() > 1) {
    char last_symbol;
    QString symbols = "(x-.^ ";

    do {
      new_window = new_window.chopped(1);
      last_symbol = new_window[new_window.length() - 1].toLatin1();
    } while (new_window.length() > 1 && !isdigit(last_symbol) &&
             symbols.indexOf(last_symbol) == -1);

    if (last_symbol == ' ' &&
        (isdigit(new_window[new_window.length() - 2].toLatin1()) ||
         new_window[new_window.length() - 2].toLatin1() == 'x')) {
      new_window = new_window.chopped(1);
    }

    if (new_window.length() == 1 && !isdigit(new_window.back().toLatin1()) &&
        new_window.back().toLatin1() != '-' &&
        new_window.back().toLatin1() != 'x') {
      new_window = START_MESSAGE;
    }
  }

  ui->result_window->setText(new_window);
}

void MainWindow::ClickEqual() {
  if (ui->result_window->text() == ERROR_MESSAGE_1) {
    ui->result_window->setText(START_MESSAGE);
  }

  bool status;
  double result = GetResult(ui->result_window->text(), &status);

  if (status) {
    if (ui->result_window->text().indexOf('x') == -1) {
      SetResult(result);
    } else {
      x_window->show();
    }
  } else {
    ui->result_window->setText(ERROR_MESSAGE_1);
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
      ui->result_window->setText(ERROR_MESSAGE_1);
    }
  }
}

void MainWindow::ClickCredit() { credit_window->show(); }

QString MainWindow::GetNewWindow(QString button_text, int flag) {
  QString new_window;
  if (flag == 2 && (ui->result_window->text() == START_MESSAGE ||
                    ui->result_window->text() == ERROR_MESSAGE_1)) {
    new_window = button_text;
  } else if (flag == 1 && ui->result_window->text() == ERROR_MESSAGE_1) {
    new_window = button_text;
  } else {
    new_window = ui->result_window->text() + button_text;
  }
  return new_window;
}

double MainWindow::GetResult(QString data, bool *status) {
  bool status_calc = false;
  std::string str_x = data.toUtf8().constData();

  s21::Controller calc;
  double result = calc.Calculate(str_x, &status_calc);
  *status = status_calc;
  return result;
}

double MainWindow::GetValue(double x) {
  QString data =
      ui->result_window->text().replace('x', "(" + QString::number(x) + ")");
  bool status;
  double result = GetResult(data, &status);
  return result;
}

void MainWindow::SetResult(double result) {
  ui->result_window->setText(QString::number(result, 'f', 7));
}
