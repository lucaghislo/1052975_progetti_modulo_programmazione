QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Car.cpp \
    Ecar.cpp \
    FFcar.cpp \
    Garage.cpp \
    Hcar.cpp \
    main.cpp \
    carfleetmanager.cpp

HEADERS += \
    Car.h \
    Ecar.h \
    FFcar.h \
    Garage.h \
    Hcar.h \
    TaxCalc.h \
    carfleetmanager.h

FORMS += \
    carfleetmanager.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
