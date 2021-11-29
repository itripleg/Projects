#-------------------------------------------------
#
# Project created by QtCreator 2017-11-16T12:44:32
#
#-------------------------------------------------

QT       += core gui network xml
QMAKE_LFLAGS += -static

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SearchTool
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    advanced.cpp \
    discoverddevice.cpp

HEADERS += \
        mainwindow.h \
    advanced.h \
    discoverddevice.h

FORMS += \
    mainwindow.ui \
    advanced.ui

RESOURCES += \
    main.qrc

win32: LIBS += -L$$PWD/../../../../Desktop/NetDEVSDK_Win32_V1.7.0.0_IN/lib/ -lNetDEVSDK

INCLUDEPATH += $$PWD/../../../../Desktop/NetDEVSDK_Win32_V1.7.0.0_IN/include
DEPENDPATH += $$PWD/../../../../Desktop/NetDEVSDK_Win32_V1.7.0.0_IN/include
