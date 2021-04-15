TEMPLATE = lib

VERSION = 2.0.0

QT -= gui

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
    LIBS += ../gsl-1.15-msvc/_build-msvc/libcblas/libcblas.lib ../gsl-1.15-msvc/_build-msvc/libgsl/libgsl.lib
    INCLUDEPATH += ../gsl-1.15-msvc
}

mac {
    CONFIG += ppc x86
    LIBS += -L/opt/local/lib/
}

