#ifndef GAMEMENU_H
#define GAMEMENU_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsTextItem>
#include "playbutton.h"
#include "exitbutton.h"

class gameMenu : public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *menuScene;
    playButton *pButton;
    exitButton *eButton;
    QGraphicsTextItem *gameName;
public:
    explicit gameMenu();
signals:

};
#endif // GAMEMENU_H
