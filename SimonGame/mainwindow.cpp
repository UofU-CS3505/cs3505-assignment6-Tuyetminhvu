#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(SimonGame *simonGame, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
    , simonGame(simonGame)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
