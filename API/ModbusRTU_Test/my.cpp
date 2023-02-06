/*
setMasterToWrite - записали (Мастер готовит пакет для записи).
getSlaveToWrite  - получили ответ, что да, записали.
setMasterToRead  - прочитали то, что записали (весь пакет, а не конкретный регистр).
*/
#include "my.h"

my::my(QObject *parent)
    : QObject{parent}{
    connect(modbus,SIGNAL(signalConnected()),this,SLOT(toConnected()));
    connect(modbus,SIGNAL(signalDisconnected()),this,SLOT(toDisconnected()));
    connect(modbus,SIGNAL(signalAnswer(MyPackage::DataVector)),this,SLOT(toAnswer(MyPackage::DataVector)));
    connect(modbus,SIGNAL(signalError(QString)),this,SLOT(toError(QString)));
    connect(modbus,SIGNAL(signalWarning(int,QString)),this,SLOT(toWarning(int, QString)));

    modbus->disconnected();

    qDebug() << "COM Device:";
    for(const QString &COM : modbus->listDevice()) qDebug() << COM; // Показываем что подключено к COM порту.

    modbus->setTimeOut(200); // 200 мс - это интервал между перезапросами.

    /*
    В Modbus есть 2 параметра:
        1. Количество промахов.
        2. Количество ошибок.
     Количество промахов - это означает, что за это время программа не успела считать все данные.
     Когда мы отправляем команду по Modbus, мы точно знаем сколько байт нам придет, и мы ждем конкретное кол-во байт.
    */

    if(modbus->connected("COM4")){  // Указать актуальный COM-порт.
        FL = 1;
        QByteArray ARR = *new QByteArray(); // // JAVA-стиль работы с классами.
        ARR.append((char)0x00);
        ARR.append((char)0xff);
        /*
         Код функции - 0x03 - Функция  чтения содержимого регистров.
         Код функции - 0x10 - Функция записи в регистры.
         setMasterToWrite - МАСТЕР создает пакет для записи.
        */
        package->setMasterToWrite(0x01,0x10,0x0030,1,ARR); // 1 - это сколько регистров нужно записать.
        modbus->pushPackage(package);
    }
}

my::~my(){
    modbus->~ModbusRTU();
    package->~MyPackage();
}

void my::toAnswer(MyPackage::DataVector code){

    if(FL == 1){
        qDebug() << "WR:  " << modbus->answerPackage()->getSlaveToWrite();
        /*
         Код функции - 0x03 - Функция  чтения содержимого регистров
         Код функции - 0x10 - Функция записи в регистры
        */
        package->setMasterToRead(0x01,0x03,0x0030,1); FL = 2; // последняя 1 - это количество регистров, которое нужно прочитать.
        modbus->pushPackage(package);
    }

    else if(FL == 2){
        qDebug() << "RD:  " << modbus->answerPackage()->getSlaveToRead(); FL = 3;
    }
}

void my::toWarning(int code, QString message){ qDebug() << "SIG CODE: " << code << " | SIG WAR: " << message;}
void my::toError(QString message){ qDebug() << "SIG ER: " << message; }
void my::toConnected(){ qDebug() << "SIG toConnected: +"; }
void my::toDisconnected(){ qDebug() << "SIG toDisconnected: +"; }
