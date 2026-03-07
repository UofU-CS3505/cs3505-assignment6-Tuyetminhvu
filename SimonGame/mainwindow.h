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

<<<<<<< HEAD
private slots:
    void on_blueButton_clicked();

    void on_redButton_clicked();
=======
public slots:
    void enableStartButton(bool);
    void enableColorButtons(bool);
    void flashRed(int timer);
    void flashBlue(int timer);
>>>>>>> fab7a271895d2c8054e5b4ebad20cf9aa94cf265

private:
    Ui::MainWindow *ui;
    SimonGame *simonGame;
};
#endif // MAINWINDOW_H
