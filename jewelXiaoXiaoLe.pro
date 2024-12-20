QT       += core gui sql
QT += network multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    emailwindow.cpp \
    gamemap.cpp \
    gamepanelwindow.cpp \
    helpingwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    paihangwindow.cpp \
    smtp.cpp \
    usernamewindow.cpp \


HEADERS += \
    emailwindow.h \
    gamemap.h \
    gamepanelwindow.h \
    helpingwindow.h \
    mainwindow.h \
    paihangwindow.h \
    smtp.h \
    usernamewindow.h \


FORMS += \
    emailwindow.ui \
    gamepanelwindow.ui \
    helpingwindow.ui \
    mainwindow.ui \
    paihangwindow.ui \
    usernamewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    loopy1.qrc \
    loopy2.qrc \
    material/picture/mine/resources.qrc \
    material/picture/tools/tools.qrc \
    material/soundeffect/sound.qrc
