#ifndef KEYPRESSHANDLER_H
#define KEYPRESSHANDLER_H

#include <QObject>
#include <QKeyEvent>

class AminDopingi;

class KeyPressHandler : public QObject {
    Q_OBJECT

public:
    explicit KeyPressHandler(AminDopingi *player);
    bool leftPressed;
    bool rightPressed;
    bool jumpPressed;

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    AminDopingi *player;
};

#endif // KEYPRESSHANDLER_H
