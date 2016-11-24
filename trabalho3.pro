QT += core
QT -= gui

CONFIG += c++11

TARGET = trabalho3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    header.cpp \
    readwrite.cpp

HEADERS += \
    header.h \
    readwrite.h
