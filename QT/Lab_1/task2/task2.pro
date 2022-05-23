QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    circle.cpp \
    graphicspainter.cpp \
    hexagon.cpp \
    main.cpp \
    mainwindow.cpp \
    rectangle.cpp \
    rhombus.cpp \
    square.cpp \
    star.cpp \
    trapezoid.cpp \
    triangle.cpp

HEADERS += \
    circle.h \
    graphicspainter.h \
    hexagon.h \
    mainwindow.h \
    rectangle.h \
    rhombus.h \
    square.h \
    star.h \
    trapezoid.h \
    triangle.h \
    кщ.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
