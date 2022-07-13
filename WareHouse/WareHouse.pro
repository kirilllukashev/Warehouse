QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Commands.cpp \
    Consumer.cpp \
    Package.cpp \
    Product.cpp \
    Simulation.cpp \
    Storage.cpp \
    Supplier.cpp \
    TransferService.cpp \
    Warehouse.cpp \
    main.cpp \
    mainwindow.cpp \
    value.cpp

HEADERS += \
    Commands.h \
    Consumer.h \
    ITransferPoint.h \
    Package.h \
    Product.h \
    Simulation.h \
    Storage.h \
    Supplier.h \
    TransferService.h \
    Warehouse.h \
    debug.h \
    mainwindow.h \
    value.h

FORMS += \
    mainwindow.ui \
    value.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md
