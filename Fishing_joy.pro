#-------------------------------------------------
#
# Project created by QtCreator 2022-11-28T10:33:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Fishing_joy
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        Widget.cpp \
    Bullet.cpp \
    gameview.cpp \
    qgun.cpp \
    qpixmapitem.cpp \
    qfish.cpp \
    qshark.cpp \
    qnet.cpp

HEADERS += \
        Widget.h \
    Bullet.h \
    gameview.h \
    qgun.h \
    qpixmapitem.h \
    qfish.h \
    qshark.h \
    qnet.h

FORMS += \
        widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc \
    boss.qrc \
    bullet.qrc \
    fish_net.qrc \
    gold_fish.qrc \
    gun.qrc \
    manta_ray.qrc \
    octopus_fish.qrc \
    readme_img.qrc \
    shark.qrc
