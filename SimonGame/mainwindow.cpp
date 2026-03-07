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

    // signal disableButtons from simonGame -> slot disableColorButtons in MainWindow
    connect(simonGame, &SimonGame::disableButtons, this, &MainWindow::disableColorButtons);

    // enable buttons
    connect(simonGame, &SimonGame::enableButtons, this, &MainWindow::enableColorButtons);

    // flash button1 which should be red
    connect(simonGame, &SimonGame::flashButton1, this, &MainWindow::flashBlue);

    // flash button2 which should be blue
    connect(simonGame, &SimonGame::flashButton2, this, &MainWindow::flashRed);
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
    QTimer::singleShot(300, this, [=]() {
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


void MainWindow::flashBlue(){
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
    QTimer::singleShot(300, this, [=]() {
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

