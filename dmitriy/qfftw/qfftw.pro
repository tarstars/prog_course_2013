TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += qt
QT += core

SOURCES += main.cpp \
    fftwmatrix.cpp \
    fftwplan.cpp

LIBS += -lfftw3

HEADERS += \
    fftwmatrix.h \
    fftwplan.h \
    defs.h

