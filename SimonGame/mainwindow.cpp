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

    //
    connect(simonGame, &SimonGame::disableButtons, this, &MainWindow::disableColorButtons);

    //
    connect(simonGame, &SimonGame::enableButtons, this, &MainWindow::enableColorButtons);

    //
    connect(simonGame, &SimonGame::flashButton1, this, &MainWindow::flashRed);

    //
    connect(simonGame, &SimonGame::flashButton2, this, &MainWindow::flashBlue);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// void MainWindow::on_blueButton_clicked()
// {

// }

void MainWindow::disableColorButtons(){
    ui->redButton->setEnabled(false);
    ui->blueButton->setEnabled(false);
}

void MainWindow::enableColorButtons(){
    ui->redButton->setEnabled(true);
    ui->blueButton->setEnabled(true);
}

void MainWindow::flashRed(){
    //set red button to a bright red or change background image
}

void MainWindow::flashBlue(){
    //set blue button to a bright blue
}

