#ifndef KEYPRESSHANDLER_H
#define KEYPRESSHANDLER_H

#include <QObject>
#include <QKeyEvent>

class KeyPressHandler : public QObject {
    Q_OBJECT

public:
    KeyPressHandler(QObject *parent = nullptr);

    bool eventFilter(QObject *obj, QEvent *event) override;

    bool leftPressed;
    bool rightPressed;
    bool upPressed;
};

#endif // KEYPRESSHANDLER_H
