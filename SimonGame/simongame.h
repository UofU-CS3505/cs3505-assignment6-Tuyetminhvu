#ifndef SIMONGAME_H
#define SIMONGAME_H

#include <QObject>
#include <QRandomGenerator>
#include <QTimer>

class SimonGame : public QObject
{
    Q_OBJECT
public:
    explicit SimonGame(QObject *parent = nullptr);

public slots:
    /**
     * @brief startGame
     * Initiates the game.
     * Sets the first number in the sequence.
     */
    void startGame();

    /**
     * @brief button1Pressed
     * A slot for the first button to verify
     * if is the correct number in the sequence.
     */
    void button1Pressed();

    /**
     * @brief button2Pressed
     * A slot for the second button to verify
     * if is the correct number in the sequence.
     */
    void button2Pressed();

signals:
    void flashButton1();
    void flashButton2();

private:
    /**
     * @brief buttonSequence
     * vector to hold the sequence of numbers (1 or 2)
     */
    QVector<int> buttonSequence;

    /**
     * @brief sequenceIndex
     * Keeps track of what index the buttonSequence is
     */
    int sequenceIndex = 0;

    /**
     * @brief getRandomNumber
     * A helper method to get a random
     * number (1 or 2) to add to the number sequence.
     * @return a random number 1 or 2
     */
    int getRandomNumber();

    /**
     * @brief playSequence
     * recursively iterates through the buttonSequence and emits signals to the view
     * depending on what number is in the sequence.
     * @param index Starts at the index passed by parameter
     */
    void playSequence(int index);

};

#endif // SIMONGAME_H
