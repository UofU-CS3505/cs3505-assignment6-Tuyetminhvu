#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simongame.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(SimonGame *simonGame, QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void enableStartButton(bool);
    void enableColorButtons(bool);
    void flashRed(int timer);
    void flashBlue(int timer);

private:
    Ui::MainWindow *ui;
    SimonGame *simonGame;
};
#endif // MAINWINDOW_H
