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

private slots:
    void on_blueButton_clicked();

    void on_redButton_clicked();

private:
    Ui::MainWindow *ui;
    SimonGame *simonGame;
};
#endif // MAINWINDOW_H
