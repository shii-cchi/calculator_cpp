//#include "../headers/credit.h"
#include "credit.h"
#include "ui_credit.h"

Credit::Credit(QWidget *parent) : QMainWindow(parent), ui(new Ui::Credit) {
  ui->setupUi(this);
  this->setWindowTitle("Кредитный калькулятор");
}

Credit::~Credit() { delete ui; }

void Credit::on_run_count_clicked() {
  clear();

  if (!fields_is_empty()) {
    QString credit_type = get_credit_type();

    QString credit_data = ui->credit_sum->text() + " " +
                          ui->credit_term->text() + " " +
                          ui->credit_percent->text() + " " + credit_type;
    char *str_credit_data = credit_data.toLocal8Bit().data();

    double max_payment = 0, min_payment = 0, overpayment = 0, total_sum = 0;
    if (credit_calculate(str_credit_data, &max_payment, &min_payment,
                         &overpayment, &total_sum)) {
      if (credit_type == "a") {
        ui->payment_2->setText(QString::number(max_payment, 'f', 0));
      } else {
        ui->payment_2->setText(QString::number(max_payment, 'f', 0) + "..." +
                               QString::number(min_payment, 'f', 0));
      }

      ui->payment_1->setText("Ежемесячный платеж: ");
      ui->overpayment_1->setText("Переплата по кредиту: ");
      ui->total_sum_1->setText("Общая выплата: ");
      ui->overpayment_2->setText(QString::number(overpayment, 'f', 0));
      ui->total_sum_2->setText(QString::number(total_sum, 'f', 0));
    } else {
      ui->payment_1->setText("Неверные данные");
    }
  } else {
    ui->payment_1->setText("Все поля должны быть заполнены");
  }
}

void Credit::clear() {
  ui->payment_1->setText("");
  ui->overpayment_1->setText("");
  ui->total_sum_1->setText("");
  ui->payment_2->setText("");
  ui->overpayment_2->setText("");
  ui->total_sum_2->setText("");
}

QString Credit::get_credit_type() {
  QString credit_type;

  if (ui->credit_type_1->isChecked()) {
    credit_type = "a";
  } else {
    credit_type = "d";
  }

  return credit_type;
}

int Credit::fields_is_empty() {
  int status = 1;
  if (!ui->credit_sum->text().isEmpty() && !ui->credit_term->text().isEmpty() &&
      !ui->credit_percent->text().isEmpty() &&
      (ui->credit_type_1->isChecked() || ui->credit_type_2->isChecked())) {
    status = 0;
  }
  return status;
}
