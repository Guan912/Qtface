#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "videowidget.h"
#include <QDir>
#include <QFileDialog>
#include <Python.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_toolButton_clicked();
    void on_pushButton_clicked();
void reshow(QString);
signals:
    void sendurl(QString);


private:
    Ui::MainWindow *ui;

    VideoWidget *vw;


};

#endif // MAINWINDOW_H
