#include "graph_window.h"
#include "ui_graph_window.h"

Graph::Graph(QWidget *parent) : QMainWindow(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
  this->setWindowTitle("График");
}

Graph::~Graph() { delete ui; }
