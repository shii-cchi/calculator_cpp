#ifndef SRC_GRAPH_WINDOW_H
#define SRC_GRAPH_WINDOW_H

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

#endif  // SRC_GRAPH_WINDOW_H
