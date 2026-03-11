/**
 * This class serves as the View (UI) for the Simon Game.
 * It handles all visual updates, animations, and user interactions
 * by connecting to the SimonGame model signals.
 * @author Fernando Lemus Guillen & Tuyet Minh Vu
 * @date 2026-03-10
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <QMediaPlayer>
#include "simongame.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief MainWindow constructor
     * Sets up the UI, initializes animations, and connects signals from the SimonGame model.
     * @param simonGame Pointer to the game logic model.
     * @param parent The parent QWidget.
     */
    MainWindow(SimonGame *simonGame, QWidget *parent = nullptr);

    /**
     * @brief MainWindow destructor
     * Cleans up the UI and allocated resources.
     */
    ~MainWindow();

public slots:
    /**
     * @brief enableStartButton
     * Toggles if player can click the start button.
     * @param enable True to enable, false to disable.
     */
    void enableStartButton(bool enable);

    /**
     * @brief enableColorButtons
     * Toggles whether the player can click the red and blue game buttons.
     * @param enable True to allow input, false to block it.
     */
    void enableColorButtons(bool enable);

    /**
     * @brief flashRed
     * Triggers the visual flash effect on the Red button.
     * @param timer The duration the highlight remains visible.
     */
    void flashRed(int timer);

    /**
     * @brief flashBlue
     * Triggers the visual flash effect on the Blue button.
     * @param timer The duration the highlight remains visible.
     */
    void flashBlue(int timer);

    /**
     * @brief showGameOverGif
     * Controls the visibility of the Game Over animation.
     * @param show True to display the GIF, false to hide.
     */
    void showGameOverGif(bool show);

    /**
     * @brief showColorButtons
     * Controls the overall visibility of the main game buttons.
     * @param show True to show, false to hide.
     */
    void showColorButtons(bool show);

    /**
     * @brief currentLevelLabel
     * Updates the level display text in the UI.
     * @param level The current level number.
     */
    void currentLevelLabel(int level);

    /**
     * @brief currentScoreLabel
     * Updates the score display text in the UI.
     * @param score The current player score.
     */
    void currentScoreLabel(int score);

    /**
     * @brief showUserTurnGif
     * Toggles an indicator letting the player know it is their turn to repeat the sequence.
     * @param show True to display the turn indicator.
     */
    void showUserTurnGif(bool show);

    /**
     * @brief updateProgressBar
     * Updates the progress bar value to show how far along the user is in the current sequence.
     * @param value The percentage value (0-100).
     */
    void updateProgressBar(int value);

private:
    /** @brief Pointer to the generated UI class */
    Ui::MainWindow *ui;

    /** @brief Pointer to the game logic model */
    SimonGame *simonGame;

    /** @brief Animation object for the game over screen */
    QMovie *gameOverMovie;

    /** @brief Animation object to indicate the user's turn */
    QMovie *userTurnMovie;

    /** @brief Animation object for the loss sequence */
    QMovie *loseGameMovie;

    /** @brief Controller for background music and sound effects */
    QMediaPlayer *bgMusic;
};

#endif // MAINWINDOW_H
