/**
 * This class serves as the Model (Logic) for the Simon Game.
 * It manages the button sequences, verifies user input, tracks scoring,
 * and emits signals to update the UI (View).
 * @author Fernando Lemus Guillen & Tuyet Minh Vu
 * @date 2026-03-10
 */

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
    percent = 0;

    emit scoreUpdated(score);
    emit progressUpdate(percent);

    numberSequence.append(getRandomNumber());
    updateGameLevel();
    QTimer::singleShot(800, this, [=]() { playSequence(0); });
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
    emit flashButton1(75);
}

void SimonGame::button2Pressed(){
    handleButtonPressed(2);
    emit flashButton2(75);
}

void SimonGame::handleButtonPressed(int button){
    if (numberSequence.isEmpty()) return;

    if (numberSequence[sequenceIndex] == button){
        score += 10;

        percent = ((sequenceIndex + 1) * 100) / numberSequence.size();

        emit scoreUpdated(score);
        emit progressUpdate(percent);

        sequenceIndex++;
        updateGameScore();

        // When player gets to last element in the sequence
        if (sequenceIndex >= numberSequence.size()){
            emit enablePlayerButtons(false);
            emit userTurnSignal(false);

            sequenceIndex = 0;

            numberSequence.append(getRandomNumber());
            updateGameLevel();

            QTimer::singleShot(2000, this, [=]() { playSequence(0); });
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
        percent = 0;
        emit progressUpdate(percent);
        emit enablePlayerButtons(true);
        emit userTurnSignal(true);
        return;
    }

    // length of time to flash and time for singleShot, increases with size of sequence
    int timer = 1000 - (numberSequence.size() * 50 );
    if (timer < 200) timer = 200;   // Dont allow the timer to get too small

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

int SimonGame::updateGameProgress(){
    emit progressUpdate(percent);
    return percent;

}
