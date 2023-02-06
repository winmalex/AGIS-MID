QT += core
QT += serialport
CONFIG += c++11 console

SOURCES += \
        main.cpp \
        my.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix|win32: LIBS += -L$$PWD/ModbusRTU/Lib/ -lModbusRTU

INCLUDEPATH += $$PWD/ModbusRTU/Include
DEPENDPATH += $$PWD/ModbusRTU/Include

HEADERS += \
    ModbusRTU/Include/ModbusRTU.h \
    ModbusRTU/Include/ModbusRTU_global.h \
    ModbusRTU/Include/MyPackage.h \
    my.h

