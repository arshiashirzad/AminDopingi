QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AminDopingi.cpp \
    BodyObject.cpp \
    Game.cpp \
    KeyPressHandler.cpp \
    Platform.cpp \
    Position.cpp \
    exitbutton.cpp \
    gamemenu.cpp \
    gameview.cpp \
    main.cpp \
    mainwindow.cpp \
    playbutton.cpp

HEADERS += \
    AminDopingi.h \
    BodyObject.h \
    Game.h \
    KeyPressHandler.h \
    Platform.h \
    Position.h \
    exitbutton.h \
    gamemenu.h \
    gameview.h \
    mainwindow.h \
    playbutton.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
