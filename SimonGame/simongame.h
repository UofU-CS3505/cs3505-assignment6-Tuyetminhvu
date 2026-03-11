/**
 * This class serves as the Model (Logic) for the Simon Game.
 * It manages the button sequences, verifies user input, tracks scoring,
 * and emits signals to update the UI (View).
 * @author Fernando Lemus Guillen & Tuyet Minh Vu
 * @date 2026-03-10
 */

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
    /**
     * @brief flashButton1
     * Emitted to trigger the visual flash of the first button.
     * @param duration The duration of the flash in milliseconds.
     */
    void flashButton1(int duration);

    /**
     * @brief flashButton2
     * Emitted to trigger the visual flash of the second button.
     * @param duration The duration of the flash in milliseconds.
     */
    void flashButton2(int duration);

    /**
     * @brief enablePlayerButtons
     * Emitted to enable or disable the color buttons for player input.
     * @param enable True to enable, false to disable.
     */
    void enablePlayerButtons(bool enable);

    /**
     * @brief enableStartButton
     * Emitted to enable or disable the start game button.
     * @param enable True to enable, false to disable.
     */
    void enableStartButton(bool enable);

    /**
     * @brief gameOverSignal
     * Emitted when the player makes a mistake and the game ends.
     * @param isGameOver True when the game enters the game over state.
     */
    void gameOverSignal(bool isGameOver);

    /**
     * @brief gameOverHideColorButtons
     * Emitted to hide the color buttons when the game is over.
     * @param hide True to hide the buttons.
     */
    void gameOverHideColorButtons(bool hide);

    /**
     * @brief levelUpdated
     * Emitted when the player successfully completes a sequence and levels up.
     * @param level The new current level.
     */
    void levelUpdated(int level);

    /**
     * @brief scoreUpdated
     * Emitted when the player's score changes.
     * @param score The new current score.
     */
    void scoreUpdated(int score);

    /**
     * @brief userTurnSignal
     * Emitted to indicate whether it is currently the user's turn to play.
     * @param isUserTurn True if it is the user's turn, false if the sequence is playing.
     */
    void userTurnSignal(bool isUserTurn);

    /**
     * @brief progressUpdate
     * Emitted to update the visual progress bar based on current sequence completion.
     * @param percent The completion percentage (0 to 100).
     */
    void progressUpdate(int percent);

private:
    /**
     * @brief buttonSequence
     * vector to hold the sequence of numbers (1 or 2)
     */
    QVector<int> numberSequence;

    /**
     * @brief gameOver
     * Resets game and emits a singal to disable color buttons
     * , but enable start button
     */
    void gameOver();

    /**
     * @brief sequenceIndex
     * Keeps track of what index the buttonSequence is
     */
    int sequenceIndex = 0;

    /**
     * @brief handleButtonPressed
     * Helper method for button1Pressed and button2Pressed
     * to handle the logic after a button is pressed
     * @param button , The button pressed (1 or 2)
     */
    void handleButtonPressed(int button);

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

    /**
     * @brief updateGameLevel
     * Method to update game level
     * @param level
     */
    int updateGameLevel();

    /**
     * @brief updateGameScore
     * Method to update game score
     * @return
     */
    int updateGameScore();

    /**
     * @brief score
     */
    int score = 0;

    /**
     * @brief updateGameProgress
     * Calculates the current progress percentage based on the player's
     * position in the current sequence.
     * @return The calculated percentage (0 to 100)
     */
    int updateGameProgress();

    /**
     * @brief percent
     * Holds the calculated percentage of the active sequence completion
     */
    int percent = 0;

};

#endif // SIMONGAME_H
