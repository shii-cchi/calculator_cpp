#ifndef SRC_GRAPH_WINDOW_H
#define SRC_GRAPH_WINDOW_H

#include <QMainWindow>

namespace Ui {
class Graph_Window;
}

class Graph_Window : public QMainWindow {
  Q_OBJECT

 public:
  explicit Graph_Window(QWidget *parent = nullptr);
  ~Graph_Window();

 private:
  Ui::Graph_Window *ui;
};

#endif  // SRC_GRAPH_WINDOW_H
