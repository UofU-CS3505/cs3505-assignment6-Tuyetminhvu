#ifndef SIMONGAME_H
#define SIMONGAME_H

#include <QObject>

class simonGame : public QObject
{
    Q_OBJECT
public:
    explicit simonGame(QObject *parent = nullptr);

signals:
};

#endif // SIMONGAME_H
