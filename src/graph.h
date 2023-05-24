// #ifndef SRC_HEADERS_GRAPH_H
// #define SRC_HEADERS_GRAPH_H
#ifndef SRC_GRAPH_H
#define SRC_GRAPH_H

#include <QMainWindow>

namespace Ui {
class Graph;
}

class Graph : public QMainWindow {
  Q_OBJECT

 public:
  explicit Graph(QWidget *parent = nullptr);
  ~Graph();

 private:
  Ui::Graph *ui;
};

// #endif  // SRC_HEADERS_GRAPH_H
#endif  // SRC_GRAPH_H
