#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "simongame.h"
#include<QMovie>

MainWindow::MainWindow(SimonGame *simonGame, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
    , simonGame(simonGame),gameOverMovie(nullptr)
{
    ui->setupUi(this);

   gameOverMovie = new QMovie(":/gameover.gif");

    ui->gameOverLabel->setMovie(gameOverMovie);
    ui->gameOverLabel->hide();   // hide at start

    userTurnMovie = new QMovie(":/yourturn.gif");

    ui->userTurnLabel->setMovie(userTurnMovie);
    ui->userTurnLabel->hide();   // hide at start

    loseGameMovie = new QMovie(":/lose.gif");

    ui->loseGameLabel->setMovie(loseGameMovie);
    ui->loseGameLabel->hide();   // hide at start

    // startButton connect to startGame()
    connect(ui->startButton, &QPushButton::clicked, simonGame, &SimonGame::startGame);

    // blueButton connect to button1Pressed()
    connect(ui->blueButton, &QPushButton::clicked, simonGame, &SimonGame::button1Pressed);

    // redButton connect to button2Pressed()
    connect(ui->redButton, &QPushButton::clicked, simonGame, &SimonGame::button2Pressed);

    // signal enablePlayerButtons from simonGame -> slot disableColorButtons in MainWindow
    connect(simonGame, &SimonGame::enablePlayerButtons, this, &MainWindow::enableColorButtons);

    connect(simonGame, &SimonGame::enableStartButton, this, &MainWindow::enableStartButton);

    // flash button1 which should be blue
    connect(simonGame, &SimonGame::flashButton1, this, &MainWindow::flashBlue);

    // flash button2 which should be red
    connect(simonGame, &SimonGame::flashButton2, this, &MainWindow::flashRed);

    //Game over gif 
    connect(simonGame, &SimonGame::gameOverSignal,this, &MainWindow::showGameOverGif);

    //User turn gif
    connect(simonGame, &SimonGame::userTurnSignal,this, &MainWindow::showUserTurnGif);

    // show or hide the color buttons based on game state
    connect(simonGame, &SimonGame::gameOverHideColorButtons,this, &MainWindow::showColorButtons);

    //update the level
    connect(simonGame, &SimonGame::levelUpdated, this, &MainWindow::currentLevelLabel);

    //update the score
    connect(simonGame, &SimonGame::scoreUpdated, this, &MainWindow::currentScoreLabel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::enableColorButtons(bool isEnabled){
    ui->redButton->setEnabled(isEnabled);
    ui->blueButton->setEnabled(isEnabled);
}

void MainWindow::showColorButtons(bool isShow){
    if(isShow){
        ui->redButton->show();
        ui->blueButton->show();
    }

    else{
        ui->redButton->hide();
        ui->blueButton->hide();
    }
}

void MainWindow::enableStartButton(bool isEnabled){
    ui->startButton->setEnabled(isEnabled);
}

void MainWindow::showGameOverGif(bool isShow)
{
    if(isShow){
        ui->gameOverLabel->show();
        ui->loseGameLabel->show();
        gameOverMovie->start();
        loseGameMovie ->start();
    }

    else{
        ui->gameOverLabel->hide();
        ui->loseGameLabel->hide();
        gameOverMovie->stop();
        loseGameMovie ->stop();
    }
}

void MainWindow::showUserTurnGif(bool isShow)
{
    if(isShow){
        ui->userTurnLabel->show();
        userTurnMovie->start();
    }

    else{
        ui->userTurnLabel->hide();
        userTurnMovie->stop();
    }
}

void MainWindow::currentLevelLabel(int level){
    ui->currentLevel->setText(QString::number(level));
}

void MainWindow::currentScoreLabel(int level){
    ui->currentScore->setText(QString::number(level));
}

void MainWindow::flashRed(int timer){
    // Set to bright red
    ui->redButton->setStyleSheet(
        "background-color: rgb(255, 50, 50);"
        "border-style: outset;"
        "border-width: 2px;"
        "border-radius: 10px;"
        "border-color: black;"
        "color: white;"
        "font: 900 25pt 'Phosphate';"
        );

    // Schedule the button to return to normal dark red
    QTimer::singleShot(timer, this, [=]() {
        ui->redButton->setStyleSheet(
            "background-color: rgb(191, 9, 0);"
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: black;"
            "color: white;"
            "font: 900 25pt 'Phosphate';"
            );
    });
}


void MainWindow::flashBlue(int timer){
    // Set to bright blue
    ui->blueButton->setStyleSheet(
        "background-color: rgb(100, 100, 255);" // Bright flashing blue
        "border-style: outset;"
        "border-width: 2px;"
        "border-radius: 10px;"
        "border-color: black;"
        "color: white;"
        "font: 900 25pt 'Phosphate';"
        );

    // Schedule the button to return to normal blue
    QTimer::singleShot(timer, this, [=]() {
        ui->blueButton->setStyleSheet(
            "background-color: blue;" // Your original blue
            "border-style: outset;"
            "border-width: 2px;"
            "border-radius: 10px;"
            "border-color: black;"
            "color: white;"
            "font: 900 25pt 'Phosphate';"
            );
    });
}

