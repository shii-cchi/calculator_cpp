//#include "../headers/graph.h"
#include "graph.h"

#include "ui_graph.h"

Graph::Graph(QWidget *parent) : QMainWindow(parent), ui(new Ui::Graph) {
  ui->setupUi(this);
  this->setWindowTitle("График");
}

Graph::~Graph() { delete ui; }
