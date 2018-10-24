QT -= gui
QT += network concurrent
CONFIG += c++11 console
CONFIG -= app_bundle

INCLUDEPATH += $$PWD/../Common/
INCLUDEPATH += $$PWD/../LibChat/
LIBS += -L$$PWD/../Out -lLibChat
DESTDIR = $$PWD/../Out
# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += USE_QSTRING_CONSTS
DEFINES += TEST
#QMAKE_CXXFLAGS_DEBUG += -pg
#QMAKE_LFLAGS_DEBUG += -pg
# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    server.cpp \
    client.cpp \
    worker.cpp \
    client_p.cpp \
    globalstorage.cpp \
    room.cpp \
    serverevent.cpp \
    clientcommand.cpp \
    handlerrequest.cpp \
    Handlers/authhandler.cpp \
    iparserrequest.cpp \
    parserclientjson.cpp \
    parserserverevent.cpp \
    Handlers/getlistusershandler.cpp \
    Handlers/decoratorhandler.cpp \
    Handlers/timedecoratorhandler.cpp \
    Handlers/userstatushandler.cpp \
    Handlers/senddatahandler.cpp \
    Handlers/sendmessagehandler.cpp \
    Handlers/errordecoratorhandler.cpp \
    Handlers/commanddecoratorhandler.cpp \
    Handlers/eventdecoratorhandler.cpp \
    Handlers/checkconnecthandler.cpp \
    requestfilter.cpp

HEADERS += \
    server.h \
    client.h \
    server_consts.h \
    worker.h \
    client_p.h \
    globalstorage.h \
    room.h \
    serverevent.h \
    clientcommand.h \
    handlerrequest.h \
    Handlers/authhandler.h \
    iparserrequest.h \
    parserclientjson.h \
    parserserverevent.h \
    Handlers/getlistusershandler.h \
    Handlers/decoratorhandler.h \
    Handlers/timedecoratorhandler.h \
    Handlers/userstatushandler.h \
    Handlers/senddatahandler.h \
    Handlers/sendmessagehandler.h \
    Handlers/errordecoratorhandler.h \
    Handlers/commanddecoratorhandler.h \
    Handlers/eventdecoratorhandler.h \
    Handlers/checkconnecthandler.h \
    requestfilter.h
