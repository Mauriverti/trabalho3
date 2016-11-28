QT += core
QT -= gui

CONFIG += c++11

TARGET = trabalho3
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    readwrite.cpp \
    gerenciador.cpp \
    cabecalho.cpp \
    disco.cpp \
    fat.cpp \
    dados.cpp \
    cluster.cpp

HEADERS += \
    readwrite.h \
    gerenciador.h \
    cabecalho.h \
    disco.h \
    fat.h \
    dados.h \
    cluster.h
