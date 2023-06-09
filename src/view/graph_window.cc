#include "graph_window.h"

#include "ui_graph_window.h"

GraphWindow::GraphWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::GraphWindow) {
  ui->setupUi(this);
  this->setWindowTitle("График");

  connect(ui->pushButton_build, SIGNAL(clicked()), this, SLOT(ClickBuild()));
}

GraphWindow::~GraphWindow() { delete ui; }

void GraphWindow::ClickBuild() {
  ui->label_err->setText("");

  bool x_1, x_2;
  double max_x = ui->max_x->text().toDouble(&x_1);
  double min_x = ui->min_x->text().toDouble(&x_2);

  if (x_1 && x_2 && max_x > min_x && max_x <= MAX_XY && min_x >= -MAX_XY) {
    double max_y, min_y;
    if (!ui->min_y->text().isEmpty() && !ui->max_y->text().isEmpty()) {
      bool y_1, y_2;
      max_y = ui->max_y->text().toDouble(&y_1);
      min_y = ui->min_y->text().toDouble(&y_2);

      if (!(y_1 && y_2 && max_y > min_y && max_y <= MAX_XY &&
            min_y >= -MAX_XY)) {
        SetError();
      }
    }

    if (ui->label_err->text() != ERROR_MESSAGE_2) {
      QVector<double> x(DOTS), y(DOTS);

      int index = 0;
      double step = fabs(max_x - min_x) / (DOTS - 1);
      for (double i = min_x; i <= max_x; i += step) {
        x[index] = i;
        y[index] = qobject_cast<MainWindow *>(parent())->GetValue(i);

        index++;
      }

      ui->plot->addGraph();
      ui->plot->graph(0)->setData(x, y);
      ui->plot->xAxis->setRange(min_x, max_x);

      if (ui->min_y->text().isEmpty() && ui->max_y->text().isEmpty()) {
        GetRangeY(y, &min_y, &max_y);
      }

      ui->plot->yAxis->setRange(min_y, max_y);
      ui->plot->replot();
    }
  } else {
    SetError();
  }
}

void GraphWindow::SetDefault() {
  ui->plot->clearGraphs();
  ui->plot->xAxis->setLabel("x");
  ui->plot->yAxis->setLabel("y");
  ui->plot->xAxis->setRange(-1000, 1000);
  ui->plot->yAxis->setRange(-1000, 1000);
  ui->plot->axisRect()->setMinimumMargins(QMargins(30, 30, 30, 30));
  ui->plot->setInteraction(QCP::iRangeZoom, true);
  ui->plot->setInteraction(QCP::iRangeDrag, true);
  ui->plot->replot();

  ui->label_err->setText("");
  ui->max_x->setText("1000");
  ui->min_x->setText("-1000");
  ui->max_y->setText("");
  ui->min_y->setText("");
}

void GraphWindow::SetError() {
  ui->label_err->setText(ERROR_MESSAGE_2);
  ui->plot->clearGraphs();
  ui->plot->replot();
}

void GraphWindow::GetRangeY(QVector<double> y, double *min_y, double *max_y) {
  *min_y = y[0], *max_y = y[0];
  for (int i = 1; i < DOTS; i++) {
    if (y[i] < *min_y) {
      *min_y = y[i];
    }

    if (y[i] > *max_y) {
      *max_y = y[i];
    }
  }

  if (*min_y < -MAX_XY) {
    *min_y = -MAX_XY;
  }

  if (*max_y > MAX_XY) {
    *max_y = MAX_XY;
  }
}

void GraphWindow::showEvent(QShowEvent *event) {
  SetDefault();
  event->accept();
}
