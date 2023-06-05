#ifndef SRC_GRAPH_WINDOW_H
#define SRC_GRAPH_WINDOW_H

#include <QMainWindow>

namespace Ui {
class GraphWindow;
}

class GraphWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit GraphWindow(QWidget *parent = nullptr);
  ~GraphWindow();

 private:
  Ui::GraphWindow *ui;
};

#endif  // SRC_GRAPH_WINDOW_H
