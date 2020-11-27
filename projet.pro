QT       += core gui multimedia sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cadmin.cpp \
    client.cpp \
    connexion.cpp \
    gestiondeclient.cpp \
    gestiondereservation.cpp \
    main.cpp \
    mainwindow.cpp \
    menu.cpp \
    menugr.cpp \
    statistiquegc.cpp \
    statistiquegr.cpp \
    statistiques.cpp

HEADERS += \
    cadmin.h \
    client.h \
    connexion.h \
    gestiondeclient.h \
    gestiondereservation.h \
    mainwindow.h \
    menu.h \
    menugr.h \
    statistiquegc.h \
    statistiquegr.h \
    statistiques.h

FORMS += \
    gestiondeclient.ui \
    gestiondereservation.ui \
    mainwindow.ui \
    menu.ui \
    menugr.ui \
    statistiquegc.ui \
    statistiquegr.ui \
    statistiques.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc

DISTFILES += \
    ../../Downloads/ajouter.png \
    ../../Downloads/back.jpg \
    ../../Downloads/back2.jpg \
    music.mp3
