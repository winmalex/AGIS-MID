#ifndef MY_H
#define MY_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <ModbusRTU.h>
#include <QSerialPort>

class my : public QObject
{
    Q_OBJECT
public:
    explicit my(QObject *parent = nullptr);
    ~my();

public slots:

    // Событие, говорящее, сколько пришло байтов
    void toAnswer(MyPackage::DataVector code);
    void toWarning(int code, QString message);
    void toError(QString message);

    // События подключения / отключения
    void toConnected();
    void toDisconnected();

private:
    ModbusRTU  *modbus  = new ModbusRTU(3000000, QSerialPort::OneStop, QSerialPort::EvenParity, QSerialPort::Data8);
    MyPackage  *package = new MyPackage();

    int FL  = 0;
};

#endif // MY_H
