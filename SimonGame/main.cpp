/**
 * Teammembers: Fernando Lemus Guilen & Tuyet Minh Vu
 * Github usernames: fernandolemus051 & Tuyetminhvu
 * Github repo URL: github.com/UofU-CS3505/cs3505-assignment6-Tuyetminhvu
 * Creative elements:
 * 1. We added background music to liven it up a bit
 * 2. Fun GIFs to let a player know when its their turn and when they lose.
 * 3. Background image to make it feel 'polished' and engaging.
 */

/**
 * The entry point for the Simon Game app.
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
