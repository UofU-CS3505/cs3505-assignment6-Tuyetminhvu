#include "simongame.h"

SimonGame::SimonGame(QObject *parent)
    : QObject{parent}
{}

void SimonGame::startGame(){
    buttonSequence.append(getRandomNumber());
    playSequence(0);
}

void SimonGame::button1Pressed(){
    if (buttonSequence[sequenceIndex] == 1){
        buttonSequence.append(getRandomNumber());
        playSequence(0);
    } else {
        // Game over
        buttonSequence.clear();
    }
}

void SimonGame::button2Pressed(){
    if (buttonSequence[sequenceIndex] == 2){
        buttonSequence.append(getRandomNumber());
        playSequence(0);
    } else {
        // Game over
        buttonSequence.clear();
    }
}

int SimonGame::getRandomNumber(){
    return QRandomGenerator::global()->bounded(1, 3);
}

void SimonGame::playSequence(int index)
{
    // Base case, return when last index is reached
    if (index >= buttonSequence.size()) return;

    if (buttonSequence[index] == 1)
        emit flashButton1();
    else
        emit flashButton2();

    QTimer::singleShot(500, this, [=]() {playSequence(index + 1);});
}
