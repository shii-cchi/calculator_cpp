#include "graph_window.h"
#include "ui_graph_window.h"

GraphWindow::GraphWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
  this->setWindowTitle("График");
}

GraphWindow::~GraphWindow() { delete ui; }
