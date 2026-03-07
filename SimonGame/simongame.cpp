#include "simongame.h"

SimonGame::SimonGame(QObject *parent)
    : QObject{parent}
{}

void SimonGame::startGame(){
    numberSequence.append(getRandomNumber());
    playSequence(0);
}

// TODO: SHOULD DISABLE BUTTONS AFTER FINAL BUTTON IN SEQUENCE IS PRESSED,
// THEN ENABLE THEM AFTER playSequence() IS FINISHED
void SimonGame::button1Pressed(){
    handleButtonPressed(1);
}

void SimonGame::button2Pressed(){
    handleButtonPressed(2);
}

void SimonGame::handleButtonPressed(int button){
    if (numberSequence[sequenceIndex] == button){
        sequenceIndex++;

        // If the final element in the sequence is reached,
        // reset index, add new element, and play back the sequence.
        if (sequenceIndex >= numberSequence.size()){
            sequenceIndex = 0;

            numberSequence.append(getRandomNumber());
            QTimer::singleShot(500, this, [=]() {playSequence(0);});
        }
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
