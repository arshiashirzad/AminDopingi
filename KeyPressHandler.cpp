#include "KeyPressHandler.h"

KeyPressHandler::KeyPressHandler(QObject *parent)
    : QObject(parent), leftPressed(false), rightPressed(false), upPressed(false) {}

bool KeyPressHandler::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress || event->type() == QEvent::KeyRelease) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        bool isPressed = (event->type() == QEvent::KeyPress);

        switch (keyEvent->key()) {
        case Qt::Key_Left:
            leftPressed = isPressed;
            return true;
        case Qt::Key_Right:
            rightPressed = isPressed;
            return true;
        case Qt::Key_Up:
            upPressed = isPressed;
            return true;
        default:
            break;
        }
    }
    return QObject::eventFilter(obj, event);
}
