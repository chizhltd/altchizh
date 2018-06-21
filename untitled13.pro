
QT       += core gui opengl

//TARGET = KatyaOGL_pt1
TEMPLATE = app

LIBS += -lopengl32
SOURCES +=\
        widget.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS  += widget.h \
    mainwindow.h
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

RESOURCES += \
    shaders.qrc \
    textures.qrc


