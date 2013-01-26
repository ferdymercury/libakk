TEMPLATE = lib

VERSION = 2.0.0

QT -= core gui

TARGET = akk

DEFINES += AKK_LIBRARY

SOURCES += Akk.cpp

HEADERS += Akk.h\
           akk_global.h

LIBS += -lgsl

unix {
    isEmpty(PREFIX) {
        PREFIX=/usr/local
    }
    headers.path=$$PREFIX/include/
    headers.files=$$HEADERS
    target.path = $$PREFIX/lib/
    INSTALLS += headers target
}

win32-msvc* {
    CONFIG += static exceptions
    LIBS += -L../gsl-1.14-msvc/lib -lgslcblas
    INCLUDEPATH += ../gsl-1.14-msvc/include}

mac {
    CONFIG += ppc x86
    LIBS += -L/opt/local/lib/
}

