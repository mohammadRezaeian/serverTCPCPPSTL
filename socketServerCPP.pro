TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        generator.cpp \
        main.cpp \
        socketcreateconnection.cpp

HEADERS += \
    generator.h \
    socketcreateconnection.h
