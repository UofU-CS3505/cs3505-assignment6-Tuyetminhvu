#include "mainwindow.h"
#include "simongame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    SimonGame simonGame;
    QApplication a(argc, argv);
    MainWindow w(&simonGame);
    w.show();
    return a.exec();
}
