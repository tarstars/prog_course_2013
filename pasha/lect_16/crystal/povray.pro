TEMPLATE = app
TARGET = povraygen
DEPENDPATH += .
INCLUDEPATH += .

QMAKE_CXXFLAGS += -std=c++11

# Input
HEADERS += matrix.h polynom.h solpart.h Tensor4.h util.h vec3.h \
    povray_templates.h
SOURCES += matrix.cpp \
           polynom.cpp \
           main.cpp \
           Tensor4.cpp \
           util.cpp \
           vec3.cpp
