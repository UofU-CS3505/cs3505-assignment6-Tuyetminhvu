#ifndef SIMONGAME_H
#define SIMONGAME_H

#include <QObject>

class SimonGame : public QObject
{
    Q_OBJECT
public:
    explicit SimonGame(QObject *parent = nullptr);

public slots:
    void button1Pressed();
    void button2Presssed();

signals:
    void flashButton1();
    void flashButton2();

private:
    QVector<int> buttonSequence;

};

#endif // SIMONGAME_H
