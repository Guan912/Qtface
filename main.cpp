#include "mainwindow.h"
#include <QApplication>
#include <Python.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    Py_SetProgramName(argv[0]);
//    Py_Initialize();
//    PyRun_SimpleString("print 'Hello Python!'\n");
//    Py_Finalize();

    MainWindow w;
    w.show();
    return a.exec();
}
