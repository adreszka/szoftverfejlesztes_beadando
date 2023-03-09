QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adatbazis.cpp \
    adminisztrator.cpp \
    auto.cpp \
    belepes.cpp \
    kereskedo.cpp \
    kerveny.cpp \
    licit.cpp \
    main.cpp \
    dialog.cpp \
    regisztracio.cpp \
    regisztraltfelhasznalo.cpp \
    tarolo.cpp

HEADERS += \
    adatbazis.h \
    adminisztrator.h \
    auto.h \
    belepes.h \
    dialog.h \
    kereskedo.h \
    kerveny.h \
    licit.h \
    regisztracio.h \
    regisztraltfelhasznalo.h \
    tarolo.h

FORMS += \
    dialog.ui

SQLAPIDIR = "C:\Egyetem\3.felev\Korszprog\SQLAPI"

INCLUDEPATH += $${SQLAPIDIR}\include

LIBS += -L$${SQLAPIDIR}/mingw-w64-x86_64-8.1.0-posix-seh-rt_v6-rev0/lib -llibsqlapi -lversion

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
