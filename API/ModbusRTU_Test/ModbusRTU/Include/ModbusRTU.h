#ifndef MODBUSRTU_H
#define MODBUSRTU_H

#include "ModbusRTU_global.h"

#include <QObject>
#include <QString>
#include <QVector>
#include <QTimer>
#include <QDebug>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>

#include "MyPackage.h"

class MODBUSRTU_EXPORT ModbusRTU : public QObject
{

    Q_OBJECT
public:

    // Конструктор
    explicit ModbusRTU(unsigned long baud = 9600,                               // Физическая скорость в бодах. 1 Бод = 1 бит/сек.
                       QSerialPort::StopBits stopBits = QSerialPort::OneStop,   // Стоповый бит
                       QSerialPort::Parity partity = QSerialPort::NoParity,     // Четность
                       QSerialPort::DataBits dataBits = QSerialPort::Data8,
                       int bufferSize = 4096);

    // Деструктор
    ~ModbusRTU();

    // Сколько байт пришло
    int isAvailable();

    // Проверка подключения
    bool isEnabled();

    // Проверка занятой линии
    bool isBusy();

        /*
        Можно пользоваться либо Конструктором либо setParams
        */

    // Установка параметров подключения
    void setParams(unsigned long baud,
                   QSerialPort::StopBits stopBits = QSerialPort::OneStop,
                   QSerialPort::Parity partity = QSerialPort::NoParity,
                   QSerialPort::DataBits dataBits = QSerialPort::Data8,
                   int bufferSize = 4096);

    // Списко устройств
    QStringList listDevice();

        /*
        Таймаут - это время, через которое мы будем делать проверки.
        Например, указали Таймаут 200 мс и Порог промахов = 3 (количество промахов 3). Это означает, что будет 3 запроса с
        интервалом по 200 мс.
        Если в 2 раза уложились и весь пакет получен, то 3-го раза уже не будет. Если в 2 раза не уложились, то будет 3-ий раз.
        Если в 3 раза не уложились, то это уже Проверка - сколько ошибок может быть.
        Если пакет не пришел после указанного количества промахов, то программа занова отправляет весь пакет (с учетом того,
        солько проверок - ошибок - допустимо).
        */
    // Изминение параметров опроса
    void setCountCheck(int val);        // Порого проверок - сколько ошибок может быть.
    void setCountMiss(int val);         // Порог промахов - сколько промахов может snm
    void setTimeOut(int val);           // Порог обновления

signals:

    // События опроса
    void signalAnswer(MyPackage::DataVector code);  // Ответ
    void signalWarning(int code, QString message);  // Предуприждение
    void signalError(QString message);              // Крит. ошибка

    // События подключения / отключения
    void signalConnected();
    void signalDisconnected();

public slots:

    // Подлючение / Отключение
    bool connected(QString name);
    bool disconnected();

    // Стандарнтный метод чтения
    QString read(int len);

    // Продвинутый метод чтения / записи
    bool print(QString line);
    bool write(QByteArray data = nullptr);

    // Отправить пакет данных
    bool pushPackage(MyPackage *package);

    // Ответ на запрос чтения / записи
    MyPackage *answerPackage();


private slots:

    // Проверка прихода пакетов
    void tickReadPackage();
    void tickWritePackage();

private:

    MyPackage *myPackage = new MyPackage();                         // Пакет данных
    MyPackage::DataVector CODE = MyPackage::DataVector::Default;    // Направление данных
    QSerialPort *SERIAL = new QSerialPort(this);                    // СОМ Порты
    QTimer *MyTimer = new QTimer();                                 // Таймер
    QByteArray *DataArray = new QByteArray();                       // Хранилище данных


    // Проверка прихода пакетов
    bool checkReadPackage();
    bool checkWritePackage();

    // Отправка конкретного пакета
    void pushPackageRead(MyPackage *package);
    void pushPackageWrite(MyPackage *package);

    // Переключатели
    bool    PW_Timer = false;           // Состояние таймера ВКЛ/ВЫКЛ

    // Счётчики и прочее
    unsigned int    CountByte = 0,      // Кол-во байт, которое мы ожидаем при ответе
                    CounterCheck = 0,   // Счётчик повторений проверки
                    CounterMiss = 0,    // Счётчик промохов
                    TickTime = 20,      // Время между обновлениями проверки состояния
                    CheckOn = 8,        // Время дискритизации
                    MissOn = 5,         // Кол-во разрешённых промохов
                    BuffSize = 0;       // Размер полученного буффера

    volatile union {
                unsigned char       UC[4];
                signed char         SC[4];
                unsigned short      US;
                signed short        SS;
                unsigned int        UI;
                signed int          SI;
                unsigned long       UL;
                signed long         SL;
                long long           LL;
                float               F;
                double              D;
                uint16_t            U16;
                uint32_t            U32;
        } Conv;

};

#endif // MODBUSRTU_H
