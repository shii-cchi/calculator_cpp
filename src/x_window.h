#ifndef X_WINDOW_H
#define X_WINDOW_H

#include <QDialog>

#include "main_window.h"

class MainWindow;

namespace Ui {
class XWindow;
}

class XWindow : public QDialog
{
    Q_OBJECT

public:
    explicit XWindow(QWidget *parent = nullptr);
    ~XWindow();

private slots:
    void on_pushButton_apply_clicked();

    void on_pushButton_cancel_clicked();

private:
    Ui::XWindow *ui;

    void SetDefault();
};

#endif // X_WINDOW_H
