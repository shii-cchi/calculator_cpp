#include "axis_window.h"
#include "ui_axis_window.h"

AxisWindow::AxisWindow(MainWindow *parent)
    : QDialog(parent), ui(new Ui::AxisWindow) {
  ui->setupUi(this);
  this->setWindowTitle("Область определения");

  connect(ui->pushButton_apply, SIGNAL(clicked()), this, SLOT(ClickApply()));
  connect(ui->pushButton_cancel, SIGNAL(clicked()), this, SLOT(ClickCancel()));
}

AxisWindow::~AxisWindow() { delete ui; }

void AxisWindow::ClickApply() {
  bool x_1, x_2;
  int max_x = ui->max_x->text().toInt(&x_1, 10);
  int min_x = ui->min_x->text().toInt(&x_2, 10);

  if (x_1 && x_2 && max_x > min_x && max_x <= MAX_XY && min_x >= -MAX_XY) {
    qobject_cast<MainWindow *>(parent())->PlotGraph(max_x, min_x);

    this->close();
    SetDefault();
  } else {
    ui->label_err->setText("Ошибка ввода");
  }
}

void AxisWindow::ClickCancel() {
  this->close();
  SetDefault();
}

void AxisWindow::SetDefault() {
  ui->label_err->setText("");
  ui->max_x->setText("1000");
  ui->min_x->setText("-1000");
}
