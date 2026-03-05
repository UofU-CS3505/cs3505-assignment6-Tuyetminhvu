#include "simongame.h"

SimonGame::SimonGame(QObject *parent)
    : QObject{parent}
{}

void SimonGame::startGame(){
    numberSequence.append(getRandomNumber());
    playSequence(0);
}

// SHOULD DISABLE BUTTONS AFTER A BUTTON IS PRESSED,
// THEN ENABLE THEM AFTER playSequence()
void SimonGame::button1Pressed(){
    if (numberSequence[sequenceIndex] == 1){
        numberSequence.append(getRandomNumber());
        playSequence(0);
    } else {
        // Game over
        numberSequence.clear();
        sequenceIndex = 0;
    }
}

void SimonGame::button2Pressed(){
    if (numberSequence[sequenceIndex] == 2){
        numberSequence.append(getRandomNumber());
        playSequence(0);
    } else {
        // Game over
        numberSequence.clear();
        sequenceIndex = 0;
    }
}

int SimonGame::getRandomNumber(){
    return QRandomGenerator::global()->bounded(1, 3);
}

void SimonGame::playSequence(int index)
{
    // Base case, return when last index is reached
    if (index >= numberSequence.size()) return;

    if (numberSequence[index] == 1)
        emit flashButton1();
    else
        emit flashButton2();

    QTimer::singleShot(500, this, [=]() {playSequence(index + 1);});
}
