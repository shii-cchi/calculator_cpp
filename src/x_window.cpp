#include "x_window.h"
#include "ui_x_window.h"

XWindow::XWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::XWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("X");
}

XWindow::~XWindow() {
    delete ui;
}

void XWindow::on_pushButton_apply_clicked() {
    bool x_1;
    int x = ui->x->text().toInt(&x_1, 10);

    if (x_1 && x <= MAX_XY && x >= -MAX_XY) {
        qobject_cast<MainWindow *>(parent())->get_new_x(x);

        this->close();
        set_default();
    } else {
        ui->label_err->setText("Ошибка ввода");
    }
}


void XWindow::on_pushButton_cancel_clicked() {
    this->close();
    set_default();
}

void XWindow::set_default() {
    ui->label_err->setText("");
    ui->x->setText("");
}
