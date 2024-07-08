#ifndef KEYPRESSHANDLER_H
#define KEYPRESSHANDLER_H

#include <QObject>
#include <QEvent>
#include <QKeyEvent>

class KeyPressHandler : public QObject {
    Q_OBJECT

public:
    explicit KeyPressHandler(QObject *parent = nullptr);
    bool leftPressed;
    bool rightPressed;
    bool upPressed;

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;
};

#endif // KEYPRESSHANDLER_H
