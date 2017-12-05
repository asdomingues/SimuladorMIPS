#-------------------------------------------------
#
# Project created by QtCreator 2017-12-01T18:50:31
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GraphicsTest
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp\
        source/Registrador.cpp\
        source/BancoDeRegistradores.cpp\
        source/EXMEM.cpp \
        source/ID.cpp \
        source/IDEXE.cpp \
        source/IF.cpp \
        source/IFID.cpp \
        source/Mem.cpp \
        source/Memoria.cpp \
        source/MemoriaInstrucao.cpp \
        source/MEMWB.cpp \
        source/Mux.cpp \
        source/Ula.cpp \
        source/WB.cpp\
        source/EX.cpp \


HEADERS  += mainwindow.h\
        include/Registrador.hpp\
        include/BancoDeRegistradores.hpp \
        include/EXMEM.hpp \
        include/ID.hpp \
        include/IDEXE.hpp \
        include/IF.hpp \
        include/IFID.hpp \
        include/Mem.hpp \
        include/Memoria.hpp \
        include/MemoriaInstrucao.hpp \
        include/MEMWB.hpp \
        include/Mux.hpp \
        include/Ula.hpp \
        include/WB.hpp \
        include/EX.hpp \

FORMS    += mainwindow.ui
