#include "x_window.h"

#include "ui_x_window.h"

XWindow::XWindow(QWidget *parent) : QDialog(parent), ui(new Ui::XWindow) {
  ui->setupUi(this);
  this->setWindowTitle("X");

  connect(ui->pushButton_apply, SIGNAL(clicked()), this, SLOT(ClickApply()));
  connect(ui->pushButton_cancel, SIGNAL(clicked()), this, SLOT(ClickCancel()));
}

XWindow::~XWindow() { delete ui; }

void XWindow::ClickApply() {
  bool x_1;
  int x = ui->x->text().toInt(&x_1, 10);

  if (x_1 && x <= MAX_XY && x >= -MAX_XY) {
    double result = qobject_cast<MainWindow *>(parent())->GetValue(x);
    qobject_cast<MainWindow *>(parent())->SetResult(result);

    this->close();
  } else {
    ui->label_err->setText(ERROR_MESSAGE_2);
  }
}

void XWindow::ClickCancel() { this->close(); }

void XWindow::SetDefault() {
  ui->label_err->setText("");
  ui->x->setText("");
}

void XWindow::showEvent(QShowEvent *event) {
  SetDefault();
  event->accept();
}
