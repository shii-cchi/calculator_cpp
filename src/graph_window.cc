#include "graph_window.h"
#include "ui_graph_window.h"

GraphWindow::GraphWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
  this->setWindowTitle("График");

  connect(ui->pushButton_build, SIGNAL(clicked()), this, SLOT(ClickBuild()));
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::ClickBuild() {
  bool x_1, x_2;
  int max_x = ui->max_x->text().toInt(&x_1, 10);
  int min_x = ui->min_x->text().toInt(&x_2, 10);

  if (x_1 && x_2 && max_x > min_x && max_x <= MAX_XY && min_x >= -MAX_XY) {
      QVector<double> x(DOTS), y(DOTS);
      int index = 0;
      double step = fabs(max_x - min_x) / DOTS;
      double x_value = min_x;
      while (index != DOTS && x_value <= max_x) {
        x[index] = x_value;
        y[index] = qobject_cast<MainWindow *>(parent())->GetYValue(x_value);

        index++;
        x_value += step;
      }

      ui->plot->clearGraphs();
      ui->plot->addGraph();
      ui->plot->graph(0)->setData(x, y);
      ui->plot->xAxis->setLabel("x");
      ui->plot->yAxis->setLabel("y");
      
      ui->plot->xAxis->setRange(min_x, max_x);
      double min_y = y[0], max_y = y[0];
      for (int i = 1; i < 1000; i++) {
          if (y[i] < min_y) {
            min_y = y[i];
          }
          
          if (y[i] > max_y) {
            max_y = y[i];
          }
      }
      ui->plot->yAxis->setRange(min_y, max_y);
      
      
      ui->plot->replot();
  } else {
      ui->label_err->setText("Ошибка ввода");
  }
}

void GraphWindow::SetDefault() {
  ui->label_err->setText("");
  ui->max_x->setText("1000");
  ui->min_x->setText("-1000");
}
