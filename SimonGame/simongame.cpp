#include "simongame.h"

SimonGame::SimonGame(QObject *parent)
    : QObject{parent}
{}

void SimonGame::startGame(){
    emit enablePlayerButtons(false);
    emit enableStartButton(false);
    emit userTurnSignal(false);
    emit gameOverSignal(false);
    emit gameOverHideColorButtons(true);

    numberSequence.clear();
    sequenceIndex = 0;
    score = 0;
    emit scoreUpdated(score);
    numberSequence.append(getRandomNumber());
    updateGameLevel();
    playSequence(0);
}

void SimonGame::gameOver(){
    emit enablePlayerButtons(false);
    emit enableStartButton(true);
    emit gameOverSignal(true);
    emit gameOverHideColorButtons(false);
    emit userTurnSignal(false);
}

void SimonGame::button1Pressed(){
    handleButtonPressed(1);
    emit flashButton1(50);
}

void SimonGame::button2Pressed(){
    handleButtonPressed(2);
    emit flashButton2(50);
}

void SimonGame::handleButtonPressed(int button){
    if (numberSequence.isEmpty()) return;

    if (numberSequence[sequenceIndex] == button){
        score += 10;
        emit scoreUpdated(score);

        sequenceIndex++;
        updateGameScore();

        // When the final element in the sequence is reached,
        // reset index, add new element, and play back the sequence.
        if (sequenceIndex >= numberSequence.size()){
            emit enablePlayerButtons(false);
            emit userTurnSignal(false);
            sequenceIndex = 0;

            numberSequence.append(getRandomNumber());
            updateGameLevel();
            QTimer::singleShot(2000, this, [=]() {playSequence(0);});
        }
    } else {
        gameOver();
    }
}

int SimonGame::getRandomNumber(){
    return QRandomGenerator::global()->bounded(1, 3);
}

void SimonGame::playSequence(int index)
{
    // Base case, return when last index is reached
    if (index >= numberSequence.size()){
        emit enablePlayerButtons(true);
        emit userTurnSignal(true);
        return;
    }

    // length of time to flash and time for singleShot, increases with size of sequence
    int timer = 1000 - (numberSequence.size() * 20 );

    if (numberSequence[index] == 1)
        emit flashButton1(timer * 0.8);
    else
        emit flashButton2(timer * 0.8);


    QTimer::singleShot(timer, this, [=]() {playSequence(index + 1);});
}

int SimonGame::updateGameLevel(){
    int level = numberSequence.size();
    emit levelUpdated(level);
    return level;
}

int SimonGame::updateGameScore(){
    emit scoreUpdated(score);
    return score;
}
