TEMPLATE = lib

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