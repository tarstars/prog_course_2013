TEMPLATE = app
TARGET = povraygen
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += matrix.h polynom.h solpart.h Tensor4.h util.h vec3.h \
    povray_templates.h
SOURCES += matrix.cpp \
           polynom.cpp \
           povray.cpp \
           Tensor4.cpp \
           util.cpp \
           vec3.cpp
