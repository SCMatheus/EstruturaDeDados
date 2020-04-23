#-------------------------------------------------
#
# Project created by QtCreator 2017-05-08T09:21:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OrdenarArquivoFila
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    IFila.cpp \
    No.cpp \
    Persistencia.cpp \
    Aluno.cpp \
    Fila.cpp \
    IPilha.cpp \
    Pilha.cpp \
    iarvorebinaria.cpp \
    ListaDuplamenteEncadeadaCircular.cpp \
    NoLista.cpp \
    ArvoreBinariaPorCodigo.cpp \
    ArvoreBinaria.cpp \
    ArvoreBinariaPorNome.cpp

HEADERS  += mainwindow.h \
    IFila.h \
    No.h \
    Persistencia.h \
    Aluno.h \
    Fila.h \
    IPilha.h \
    Pilha.h \
    iarvorebinaria.h \
    ListaDuplamenteEncadeadaCircular.h \
    NoLista.h \
    ArvoreBinariaPorCodigo.h \
    ArvoreBinaria.h \
    ArvoreBinariaPorNome.h

FORMS    += mainwindow.ui
