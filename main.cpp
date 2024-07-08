#include "gamemenu.h"
#include <QApplication>
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    auto menuView=new gameMenu();
    menuView->show();
    return a.exec();
}
