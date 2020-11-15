# OpenGL编译文件

file = none
CXX = g++
CC = gcc

GL=1
GLES2=1
GLES3=1
GLFW=1
EGL=1
GLU=1
GLUS=1
GLUT=1
GLAD=1
OPENCV3=0
OPENCV4=1
DL=1
SDL=1

# 系统库文件
INCPATH = -I. -isystem 
LIBS = -L/usr/lib

ifeq ($(DL), 1)
    LIBS += -ldl
endif

ifeq ($(SDL), 1)
    LIBS += -lSDL2
endif

ifeq ($(GL), 1)
    INCPATH+=-I/usr/include/GL
    LIBS += -lGL
endif

ifeq ($(GLES2), 1)
    INCPATH+=-I/usr/include/GLES2
endif

ifeq ($(GLES3), 1)
    INCPATH+=-I/usr/include/GLES3 
endif

ifeq ($(EGL), 1)
    INCPATH+=-I/usr/include/EGL 
endif

ifeq ($(GLFW), 1)
    INCPATH+=-I/usr/include/GLFW
    LIBS += -lglfw
endif

ifeq ($(GLU), 1)
    LIBS += -lGLU
endif

ifeq ($(GLUS), 1)
    LIBS += -lGLUS
endif

ifeq ($(GLUT), 1)
    LIBS += -lglut
endif

ifeq ($(GLAD), 1)
    LIBS += -lglad
endif

ifeq ($(OPENCV3), 1)
    INCPATH+=-I/usr/include/opencv
    LIBS+=`pkgconf --libs opencv`
endif

ifeq ($(OPENCV4), 1)
    INCPATH+=-I/usr/include/opencv4
    LIBS+=`pkgconf --libs opencv4`
endif

# 默认编译部分
all:
	$(CXX) -c $(INCPATH) $(file).cpp
	$(CXX) -o $(file) $(file).o $(LIBS)
	rm *.o
