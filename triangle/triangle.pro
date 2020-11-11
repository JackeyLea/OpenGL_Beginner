TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

unix:{
LIBS += -L/usr/lib/x86_64-linux-gnu/ -lGLEW -lEGL -lGLESv2 -lGL \
        -lGLU -lGLw -lGLX -lOpenGL -lgle -lglfw -lglut
}

SOURCES += \
        main.cpp
