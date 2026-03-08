#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "simongame.h"
#include<QMediaPlayer>

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
    void showGameOverGif(bool show);
    void showColorButtons(bool show);
    void currentLevelLabel(int level);
    void currentScoreLabel(int score);
    void showUserTurnGif(bool show);
    void updateProgressBar(int value);

private:
    Ui::MainWindow *ui;
    SimonGame *simonGame;
    QMovie *gameOverMovie;
    QMovie *userTurnMovie;
    QMovie *loseGameMovie;
    QMediaPlayer *bgMusic;
};
#endif // MAINWINDOW_H
