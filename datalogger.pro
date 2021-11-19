#-------------------------------------------------
#
# Project created by QtCreator 2016-10-27T20:58:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = datalogger
TEMPLATE = app
DESTDIR=x86-Debug #Target file directory
OBJECTS_DIR=obj #Intermediate object files directory
MOC_DIR=moc #Intermediate moc files directory


SOURCES += src/main.cpp\
           src/oekofen/gui/MainWindow.cpp\
           src/oekofen/bufferTank.cpp \
           src/oekofen/energy.cpp \
           src/oekofen/environment.cpp \
           src/oekofen/heater.cpp \
           src/oekofen/heatingCircuit.cpp \
           src/oekofen/hotWaterTank.cpp \
           src/oekofen/logEntry.cpp \
           src/oekofen/pelletronic.cpp

HEADERS  += src/oekofen/gui/MainWindow.h \
            src/oekofen/common/unit.h \
            src/oekofen/dt/sensor.h \
            src/oekofen/gui/MainWindow.h \
            src/oekofen/bufferTank.h \
            src/oekofen/energy.h \
            src/oekofen/environment.h \
            src/oekofen/heater.h \
            src/oekofen/heatingCircuit.h \
            src/oekofen/hotWaterTank.h \
            src/oekofen/logEntry.h \
            src/oekofen/pelletronic.h
