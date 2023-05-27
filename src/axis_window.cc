#include "axis_window.h"
#include "ui_axis_window.h"

AxisWindow::AxisWindow(MainWindow *parent)
    : QDialog(parent), ui(new Ui::AxisWindow) {
  ui->setupUi(this);
  this->setWindowTitle("Область определения");
}

AxisWindow::~AxisWindow() { delete ui; }

void AxisWindow::on_pushButton_apply_clicked() {
  bool x_1, x_2;
  int max_x = ui->max_x->text().toInt(&x_1, 10);
  int min_x = ui->min_x->text().toInt(&x_2, 10);

  if (x_1 && x_2 && max_x > min_x && max_x <= MAX_XY && min_x >= -MAX_XY) {
    qobject_cast<MainWindow *>(parent())->plot_graph(max_x, min_x);

    this->close();
    set_default();
  } else {
    ui->label_err->setText("Ошибка ввода");
  }
}

void AxisWindow::on_pushButton_cancel_clicked() {
  this->close();
  set_default();
}

void AxisWindow::set_default() {
  ui->label_err->setText("");
  ui->max_x->setText("1000");
  ui->min_x->setText("-1000");
}
