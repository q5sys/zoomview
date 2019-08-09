#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "zoomgview.h"
#include <QComboBox>
#include <QtGui>
#include <QToolButton>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
  ui->setupUi(this);

  QWidget *window = new QWidget;
  window->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

  zoomGView *frame = new zoomGView(scene)
  frame->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  frame->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  QVBoxLayout *vLayout = new QVBoxLayout;
  vLayout->addWidget(frame);

  QFrame* line = new QFrame();
  line->setFrameShape(QFrame::HLine);
  line->setFrameShadow(QFrame::Sunken);
  vLayout->addWidget(line);

  QHBoxLayout *hlayout = new QHBoxLayout;
  vLayout->addLayout(hlayout);

  QStringList *resolutions = new QStringList;
  // add resolutions to stringlist
  QComboBox *resBox = new QComboBox;
  resBox->addItems(*resolutions);
  hlayout->addWidget(resBox);
  //set default resolution to 1080p

  QSpacerItem *item = new QSpacerItem(1,1, QSizePolicy::Expanding, QSizePolicy::Fixed);
  hlayout->addSpacerItem(item);

  QToolButton *saveButton = new QToolButton;
  hlayout->addWidget(saveButton);

  window->setLayout(vLayout);
  window->show();
}

void openFile::MainWindow(QString file){
  findPath(file);
  QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(path));
  scene->addItem(item);
  view->show();
}


QString findPath::MainWindow(QString file){
  if(file.startsWith("~/")){ file = file.replace("~/", QDir::homePath()+"/" ); }
  if(file.startsWith("/") || QFile::exists(file)){ return file; }
  return path;
}

void setResolution::Mainwindow(){}
    //grab resolution from combobox when changed
    // resize capture frame to proper aspect ratio

//view->setFixedSize(width, height);
//view->setSceneRect(0, 0, width, height);
//view->fitInView(0, 0, width, height, Qt::KeepAspectRatio);


void SaveFile::MainWIndow(){


// get selected Image Resolution
// get image inside frame and set to resolution selected in resBox;
// File Save Dialog

}


MainWindow::~MainWindow()
{
    delete ui;
}
