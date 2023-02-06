#ifndef MYPACKAGE_H
#define MYPACKAGE_H

#include <QObject>
#include "ModbusRTU_global.h"

class MODBUSRTU_EXPORT MyPackage : public QObject
{
    Q_OBJECT
public:

    // Направление данных
    enum DataVector{
        Default = 0,
        MasterRead  = 1,
        MasterWrite = 2,
        SlaveRead   = 3,
        SlaveWrite  = 4
    };


    // Основное
    explicit MyPackage();       // Конструктор
    ~MyPackage();               // Деструктор
    void clear();               // Очистка

    // Формируем пакет на чтение группы регистров
    void setMasterToRead(uint8_t _Addr_Device,
                         uint8_t _Code_Function,
                         uint8_t _Hi_Addr_Registr,
                         uint8_t _Lo_Addr_Registr,
                         uint8_t _Hi_Count_Registr,
                         uint8_t _Lo_Count_Registr,
                         uint8_t _Hi_CRC_Registr,
                         uint8_t _Lo_CRC_Registr
                         );

    void setMasterToRead(uint8_t _Addr_Device,
                         uint8_t _Code_Function,
                         uint8_t _Hi_Addr_Registr,
                         uint8_t _Lo_Addr_Registr,
                         uint8_t _Hi_Count_Registr,
                         uint8_t _Lo_Count_Registr
                         );

    void setMasterToRead(uint8_t _Addr_Device,
                         uint8_t _Code_Function,
                         uint16_t _Addr_Registr,
                         unsigned short _Count_Registr
                         );

    // Формируем пакет на запись группы регистров
    void setMasterToWrite(uint8_t _Addr_Device,
                          uint8_t _Code_Function,
                          uint8_t _Hi_Addr_Registr,
                          uint8_t _Lo_Addr_Registr,
                          uint8_t _Hi_Count_Registr,
                          uint8_t _Lo_Count_Registr,
                          uint8_t _Hi_CRC_Registr,
                          uint8_t _Lo_CRC_Registr,
                          QByteArray data);

    void setMasterToWrite(uint8_t _Addr_Device,
                          uint8_t _Code_Function,
                          uint8_t _Hi_Addr_Registr,
                          uint8_t _Lo_Addr_Registr,
                          uint8_t _Hi_Count_Registr,
                          uint8_t _Lo_Count_Registr,
                          QByteArray data);

    void setMasterToWrite(uint8_t _Addr_Device,
                          uint8_t _Code_Function,
                          uint16_t _Addr_Registr,
                          unsigned short _Count_Registr,
                          QByteArray data);

    // Формируем пакет ответа на запрос чтения
    void setSlaveToRead(uint8_t _Addr_Device,
                        uint8_t _Code_Function,
                        uint8_t _Hi_CRC_Registr,
                        uint8_t _Lo_CRC_Registr,
                        QByteArray data);

    // Формируем пакет ответа на запрос записи
    void setSlaveToWrite(uint8_t _Addr_Device,
                         uint8_t _Code_Function,
                         uint8_t _Hi_Addr_Registr,
                         uint8_t _Lo_Addr_Registr,
                         uint8_t _Hi_Count_Registr,
                         uint8_t _Lo_Count_Registr,
                         uint8_t _Hi_CRC_Registr,
                         uint8_t _Lo_CRC_Registr);


    // Возвращаем пакет
    QByteArray getMasterToRead();                   // Запрос на чтение группы регистров
    QByteArray getMasterToWrite();                  // Запрос на запись группы регистров
    QByteArray getSlaveToRead();                    // Ответ на запрос чтения
    QByteArray getSlaveToWrite();                   // Ответ на запрос записи


    // Устновка значений
    void set_Addr_Registr    (unsigned char value);
    void set_Code_Function   (unsigned char value);
    void set_Hi_Addr_Registr (unsigned char value);
    void set_Lo_Addr_Registr (unsigned char value);
    void set_Hi_Count_Registr(unsigned char value);
    void set_Lo_Count_Registr(unsigned char value);
    void set_Len_Byte_Registr(unsigned char value);
    void set_Hi_CRC_Registr  (unsigned char value);
    void set_Lo_CRC_Registr  (unsigned char value);

    // Получение значений
    unsigned char get_Addr_Registr    ();
    unsigned char get_Code_Function   ();
    unsigned char get_Hi_Addr_Registr ();
    unsigned char get_Lo_Addr_Registr ();
    unsigned char get_Hi_Count_Registr();
    unsigned char get_Lo_Count_Registr();
    unsigned char get_Len_Byte_Registr();
    unsigned char get_Hi_CRC_Registr  ();
    unsigned char get_Lo_CRC_Registr  ();

    // Запись старшего и младшего байта значений регистра
    void append(unsigned char Value);
    void append(unsigned char Hi_Value, unsigned char Lo_Value);
    void append(QByteArray Value);

    // Получение массива из старших и младших байтов значений регистров
    QByteArray get_ValueRegistr();

    // Узнать направление данных
    DataVector getCode();

    // CRC-16
    static uint16_t CRC16(char *Bufer, unsigned char Longbuf);

private:

    // Элементы пакета данных
    unsigned char Addr_Device       = 0x00;         // Адрес устройства
    unsigned char Addr_Registr      = 0x00;         // Адресс
    unsigned char Code_Function     = 0x00;         // Код функции
    unsigned char Hi_Addr_Registr   = 0x00;         // Hi Адрес первого регистра
    unsigned char Lo_Addr_Registr   = 0x00;         // Lo Адрес первого регистра
    unsigned char Hi_Count_Registr  = 0x00;         // Hi Кол-во требуемых регистров
    unsigned char Lo_Count_Registr  = 0x00;         // Lo Кол-во требуемых регистров
    unsigned char Len_Byte          = 0x00;         // Кол-во байтов
    unsigned char Hi_CRC_Registr    = 0x00;         // Hi Контрольная сумма
    unsigned char Lo_CRC_Registr    = 0x00;         // Lo Контрольная сумма

    DataVector CODE = DataVector::Default;          // Направление данных
    QByteArray ValueRegistr = *new QByteArray;      // Массив Hi значений
    QByteArray DATA = *new QByteArray();            // Массив для работы с пакетами в целом

    volatile union {
                    unsigned char       UC[2];
                    uint16_t            U16;
            } Conv;
};

#endif // MYPACKAGE_H
