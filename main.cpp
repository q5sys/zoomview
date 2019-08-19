#include "mainwindow.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[]){
  QApplication a(argc, argv);

  QString file;
  file = argv[0];

  MainWindow w;
  //w.LoadArguments(file);
  w.show();


    return a.exec();
}
