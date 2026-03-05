#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(SimonGame *simonGame, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
    , simonGame(simonGame)
{
    ui->setupUi(this);
    // startButton connect to startGame()
    connect(ui->startButton, &QPushButton::clicked, simonGame, &SimonGame::startGame);

    // blueButton connect to button1Pressed()
    connect(ui->blueButton, &QPushButton::clicked, simonGame, &SimonGame::button1Pressed);

    // redButton connect to button2Pressed()
    connect(ui->redButton, &QPushButton::clicked, simonGame, &SimonGame::button2Pressed);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_blueButton_clicked()
{

}

