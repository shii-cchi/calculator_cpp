#include "graph_window.h"
#include "ui_graph_window.h"

Graph_Window::Graph_Window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Graph_Window) {
  ui->setupUi(this);
  this->setWindowTitle("График");
}

Graph_Window::~Graph_Window() { delete ui; }
