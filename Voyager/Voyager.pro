QT   += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail kuda compile if it uses deprecated APIs.
# In order kuda do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000# disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
Graph.cpp \
main.cpp \
Puti.cpp \
Voyager.cpp \
Planets.cpp \
    trigcalcx.cpp

HEADERS += \
Graph.h \
Puti.h \
Voyager.h \
Planets.h \
    trigcalcx.h

FORMS += \
mainwindow.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


