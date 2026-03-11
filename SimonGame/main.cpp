/**
 * The entry point for the Simon Game application.
 * Initializes the Qt Application, the Game Model, and the Main Window.
 * @author Fernando Lemus Guillen & Tuyet Minh Vu
 * @date 2026-03-10
 */

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
