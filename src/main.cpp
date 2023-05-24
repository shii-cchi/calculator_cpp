#include <QApplication>

//#include "../headers/calculator.h"
#include "calculator.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.show();
  return a.exec();
}
