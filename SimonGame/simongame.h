#ifndef SIMONGAME_H
#define SIMONGAME_H

#include <QObject>

class SimonGame : public QObject
{
    Q_OBJECT
public:
    explicit SimonGame(QObject *parent = nullptr);

signals:
};

#endif // SIMONGAME_H
