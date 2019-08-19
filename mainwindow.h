#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    static QString findPath(QString file);
    void openFile();
    void setResolution();
    void saveFile();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
