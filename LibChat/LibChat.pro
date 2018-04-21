#-------------------------------------------------
#
# Project created by QtCreator 2018-04-19T10:48:55
#
#-------------------------------------------------

QT       += network

QT       -= gui

TARGET = LibChat
TEMPLATE = lib

MOC_DIR = .moc
OBJECTS_DIR = .obj

DESTDIR = $$PWD/../libs

DEFINES += LIBCHAT_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        libchat.cpp \
    chatrequest.cpp \
    chatresponse.cpp \
    chatnetworkmanager.cpp \
    chatclient.cpp

HEADERS += \
        libchat.h \
        libchat_global.h \ 
    chatrequest.h \
    chatresponse.h \
    common_consts.h \
    chatnetworkmanager.h \
    chatclient.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
