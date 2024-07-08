#include "KeyPressHandler.h"
#include "AminDopingi.h"

KeyPressHandler::KeyPressHandler(AminDopingi *player)
    : QObject(), player(player), leftPressed(false), rightPressed(false), jumpPressed(false) {}

bool KeyPressHandler::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Left) {
            leftPressed = true;
        } else if (keyEvent->key() == Qt::Key_Right) {
            rightPressed = true;
        } else if (keyEvent->key() == Qt::Key_Up || keyEvent->key() == Qt::Key_Space) {
            jumpPressed = true;
            player->jump();
        }
        return true;
    } else if (event->type() == QEvent::KeyRelease) {
        QKeyEvent *keyEvent = static_cast<QKeyEvent *>(event);
        if (keyEvent->key() == Qt::Key_Left) {
            leftPressed = false;
        } else if (keyEvent->key() == Qt::Key_Right) {
            rightPressed = false;
        } else if (keyEvent->key() == Qt::Key_Up || keyEvent->key() == Qt::Key_Space) {
            jumpPressed = false;
        }
        return true;
    } else {
        return QObject::eventFilter(obj, event);
    }
}
