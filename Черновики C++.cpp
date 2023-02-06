    if(!setupReadPackage(MID_REG::Adr_Mem_Home,90,FLAG_DATA::FlashReadTest)){
        qDebug() << " Тестовое чтение Flash не прокатило ( ";
    }


    // Тест-массив
    QByteArray ArrTest0; // Тестовый массив
    for(int i = 0; i < 180; i++){
        ArrTest0.append((char)0x00);
    }

    // Тест-массив
    QByteArray ArrTest1; // Тестовый массив
    for(quint8 i = 0; i < 90; i++){
        ArrTest1.append(i);
    }


    /*
    // Настройки обмена
    //DEVICE->setTimeOut(2000);
    //DEVICE->setCountCheck(2);
    //DEVICE->setCountMiss(2);

    if(!setupReadPackage(MID_REG::Adr_Mem_Home,70,FLAG_DATA::FlashRead)){
        qDebug() << "Ошибка чтения блока памяти";
    //DEVICE->setTimeOut(20);
    //DEVICE->setCountCheck(0);
    //DEVICE->setCountMiss(0);
    }
    */

    int msec = QTime::currentTime().msec();
    qDebug() << "МиллиСекунды: " << msec;
    int sec = QTime::currentTime().second();
    qDebug() << "Секунды: " << sec;
    int min = QTime::currentTime().minute();
    qDebug() << "Минуты: " << min;
    int hour = QTime::currentTime().hour();
    qDebug() << "Часы: " << hour;

    qDebug() << " * * * * * * * * * * * * * * * * * * * * *  ";
	
	qDebug() << "_6_" << QTime::currentTime().minute() << " " << QTime::currentTime().second() << " " << QTime::currentTime().msec();
	

    QDate date (2022, 10, 7);
    int day = date.day();
    qDebug() << "День: " << day;
    int month = date.month();
    qDebug() << "Месяц " << month;
    int year = date.year();
    qDebug() << "Год " << year;

    qDebug() << " * * * * * * * * * * * * * * * * * * * * *  ";

    QDate D1 = QDateTime::currentDateTime().date();
    qDebug () << "D1:" << D1; // Получить текущую дату
    qDebug () << "year:" << D1.year (); // Получить год
             qDebug () << "month:" << D1.month (); // Получить месяц
             qDebug () << "day:" << D1.day (); // Получить день
             qDebug () << "isValid:" << D1.isValid (); // Допустима ли дата
             qDebug () << "dayOfWeek:" << D1.dayOfWeek (); // Сегодня день недели
             qDebug () << "dayOfYear:" << D1.dayOfYear (); // Сколько дней текущий год
             qDebug () << "daysInMonth:" << D1.daysInMonth (); // сколько дней в этом месяце
             qDebug () << "daysInYear:" << D1.daysInYear (); // Сколько дней в этом году
             qDebug () << "isNull:" << D1.isNull (); // Если дата пуста, вернуть true
             qDebug () << "isLeapYear:" << QDate :: isLeapYear (D1.year ()); // Будь то високосный год

    qDebug() << " * * * * * * * * * * * * * * * * * * * * *  ";

    qDebug() << QTime::currentTime().toString("HH:mm:ss");
    qDebug() << QDateTime::currentDateTime().toString("dd.MM.yyyy HH:mm:ss");
	
	
	int sec = QTime::currentTime().second();    qDebug() << "Секунды: " << sec;     // Секунда
    int min = QTime::currentTime().minute();    qDebug() << "Минуты: " << min;      // Минута
    int hour = QTime::currentTime().hour();     qDebug() << "Часы: " << hour;       // Час
    
    int dayOfWeek = D1.dayOfWeek(); qDebug () << "dayOfWeek:" << dayOfWeek;         // День недели
    int day = D1.day();             qDebug () << "day:" << day;                     // День
    int month = D1.month();         qDebug () << "month:" << month;                 // Месяц
    int year = D1.year() % 100;     qDebug () << "year:" << year;                   // Год 22
	
	
	/*
    // Вставим в таблицу ComboBox
    TAB->setCellWidget(0, 0, COMBO_1);  // Помещаем в ячейку 0, 0
    TAB->setCellWidget(1, 0, COMBO_2);  // Помещаем в ячейку 1, 0
    */

	
	/*
    QComboBox *comboBoxRead = qobject_cast< QComboBox* >(TAB->cellWidget(0, 0));
    QString valueComboBox [10];

    for (int i = 0; i < 10; ++i)
    {
        valueComboBox[i] =
    }
    */

    //QString value = comboBoxRead->currentText();
	
    TAB->item(2,2)->setBackground(Qt::red);
    TAB->item(1,1)->setBackground(QColor(0,60,10));
	
		
	QComboBox *comboBoxRead[10];    // Нужно для считывания ComboBox
	int IndexComboBox [10];     // Значения индексов в ComboBox
	
	comboBoxRead[i] = qobject_cast< QComboBox* >(TAB->cellWidget(i, 0));    // Если нужно прочитать содержимое comboBox
	IndexComboBox[i] = comboBoxRead[i]->currentIndex();                     // Тут просто индекс выбранного элемента
	
	comboBox[i]->addItem("Не работает");
	comboBox[i]->addItem("Униполярный режим, положит. полярность");
	comboBox[i]->addItem("Униполярный режим, отрицат. полярность");
	comboBox[i]->addItem("Биполярный режим");
	
	comboBox[i]->setCurrentIndex(IndexComboBox[i]);    // Значение по умолчанию
	
	
	



else if(xmlReader.name() == "SCENARIO") {
                        qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
                        qDebug() << "xmlReader.name:                "  << xmlReader.name();
                        qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("number");
                        qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("number").toString();
                        temp = xmlReader.attributes().value("number").toInt();
                        qDebug() << "!!! attributes INT: " << temp;
                        qDebug() << "";
                        xmlReader.readNext();	
else if(xmlReader.name() == "HOUR") {
	qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
	qDebug() << "xmlReader.name:                "  << xmlReader.name();
	qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("value");
	qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("value").toString();
	//qDebug() << "readElementText:               "  << xmlReader.readElementText();
	int temp1 = xmlReader.readElementText().toInt();
	qDebug() << "!!!!!!!!!" << temp1;
	qDebug() << "";
	xmlReader.readNext();
}
	
	
xmlWriter.writeStartElement("HOUR");
xmlWriter.writeAttribute("value", TAB->item(0,1)->text());
xmlWriter.writeCharacters("тратата");
xmlWriter.writeEndElement();	




while (!xmlReader.atEnd()) { // Если конец документа не читается и ошибки нет

                if(xmlReader.isStartElement()) {                        // StartElement
                    if(xmlReader.name() == "AGIS") {
                        /*
                        qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
                        qDebug() << "xmlReader.name:                "  << xmlReader.name();
                        qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("name_module");
                        qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("name_module").toString();
                        qDebug() << "";
                        */
                        xmlReader.readNext();
                    }
                    else if(xmlReader.name() == "SCENARIO") {
                        /*
                        qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
                        qDebug() << "xmlReader.name:                "  << xmlReader.name();
                        qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("number");
                        qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("number").toString();
                        qDebug() << "";
                        */
                        numScen = xmlReader.attributes().value("number").toInt();
                        --numScen;
                        mapScen[numScen].insert("SCENARIO",xmlReader.attributes().value("number").toString());
                        xmlReader.readNext();
                    }
                    else if(xmlReader.name() == "FLAG") {
                        /*
                        qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
                        qDebug() << "xmlReader.name:                "  << xmlReader.name();
                        qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("number");
                        qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("number").toString();
                        qDebug() << "";
                        */
                        mapScen[numScen].insert("FLAG",xmlReader.attributes().value("value").toString());
                        xmlReader.readNext();
                    }
                    else if(xmlReader.name() == "HOUR") {
                        /*
                        qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
                        qDebug() << "xmlReader.name:                "  << xmlReader.name();
                        qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("value");
                        qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("value").toString();
                        qDebug() << "";
                        */
                        mapScen[numScen].insert("HOUR",xmlReader.attributes().value("value").toString());
                        xmlReader.readNext();
                    }
                    else if(xmlReader.name() == "MINUTE") {
                        /*
                        qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
                        qDebug() << "xmlReader.name:                "  << xmlReader.name();
                        qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("value");
                        qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("value").toString();
                        qDebug() << "";
                        */
                        mapScen[numScen].insert("MINUTE",xmlReader.attributes().value("value").toString());
                        xmlReader.readNext();
                    }
                    else if(xmlReader.name() == "SECOND") {
                        /*
                        qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
                        qDebug() << "xmlReader.name:                "  << xmlReader.name();
                        qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("value");
                        qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("value").toString();
                        qDebug() << "";
                        */
                        mapScen[numScen].insert("SECOND",xmlReader.attributes().value("value").toString());
                        xmlReader.readNext();
                    }
                    else if(xmlReader.name() == "PULSE_DURATION_L") {
                        /*
                        qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
                        qDebug() << "xmlReader.name:                "  << xmlReader.name();
                        qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("value");
                        qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("value").toString();
                        qDebug() << "";
                        */
                        mapScen[numScen].insert("PULSE_DURATION_L",xmlReader.attributes().value("value").toString());
                        xmlReader.readNext();
                    }
                    else if(xmlReader.name() == "PULSE_DURATION_S") {
                        /*
                        qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
                        qDebug() << "xmlReader.name:                "  << xmlReader.name();
                        qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("value");
                        qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("value").toString();
                        qDebug() << "";
                        */
                        mapScen[numScen].insert("PULSE_DURATION_S",xmlReader.attributes().value("value").toString());
                        xmlReader.readNext();
                    }
                    else if(xmlReader.name() == "CURRENT_S") {
                        /*
                        qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
                        qDebug() << "xmlReader.name:                "  << xmlReader.name();
                        qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("value");
                        qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("value").toString();
                        qDebug() << "";
                        */
                        mapScen[numScen].insert("CURRENT_S",xmlReader.attributes().value("value").toString());
                        xmlReader.readNext();
                    }
                    else if(xmlReader.name() == "CURRENT_L") {
                        /*
                        qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
                        qDebug() << "xmlReader.name:                "  << xmlReader.name();
                        qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("value");
                        qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("value").toString();
                        qDebug() << "";
                        */
                        mapScen[numScen].insert("CURRENT_L",xmlReader.attributes().value("value").toString());
                        xmlReader.readNext();
                    }
                    else if(xmlReader.name() == "COMMENTS") {
                        /*
                        qDebug() << "xmlReader.tokenString() =      "  << xmlReader.tokenString();
                        qDebug() << "xmlReader.name:                "  << xmlReader.name();
                        qDebug() << "xmlReader.attributes():        "  << xmlReader.attributes().value("value");
                        qDebug() << "!!! attributes:                "  << xmlReader.attributes().value("value").toString();
                        qDebug() << "";
                        */
                        mapScen[numScen].insert("COMMENTS",xmlReader.attributes().value("value").toString());
                        xmlReader.readNext();
                    }
                    else {
                        xmlReader.readNext();
                    }
                }

                else if(xmlReader.isComment()) {                        // Comment
                    //qDebug() << xmlReader.text();
                    xmlReader.readNext();
                }

                else if(xmlReader.isEndElement()) {                     // EndElement
                    xmlReader.readNext();
                }

                else {
                    xmlReader.readNext();                               // NextElement
                }


                if (xmlReader.hasError()) {                             // Если во время чтения возникает ошибка, выведите сообщение об ошибке
                    qDebug() << "error: " << xmlReader.errorString();
                }
            }   qDebug() << "XML файл прочитан. OK!";
                qDebug() << "туту = " << mapScen[0]["SCENARIO"];
                qDebug() << "туту = " << mapScen[1]["SCENARIO"];
                qDebug() << "туту = " << mapScen[2]["SCENARIO"];
                qDebug() << "туту = " << mapScen[3]["SCENARIO"];
                qDebug() << "туту = " << mapScen[4]["SCENARIO"];
                qDebug() << "туту = " << mapScen[5]["SCENARIO"];
                qDebug() << "туту = " << mapScen[6]["SCENARIO"];
                qDebug() << "туту = " << mapScen[7]["SCENARIO"];
                qDebug() << "туту = " << mapScen[8]["SCENARIO"];
                qDebug() << "туту = " << mapScen[9]["SCENARIO"];
				
				
				
				
	
				
//comboBox[i]->setCurrentText(QString::number(scenRead.FLAG));

        //TAB->setItem(i,0, new QTableWidgetItem(QString::number(scenRead.FLAG)));
        //comboBox[i]->setCurrentText(QString::number(scenRead.FLAG));				
	
	
        mapScen[i].insert("SCENARIO",xmlAttributes);    // Номер сценария
        mapScen[i].insert("FLAG",xmlAttributes);
        mapScen[i].insert("HOUR",xmlAttributes);
        mapScen[i].insert("MINUTE",xmlAttributes);
        mapScen[i].insert("SECOND",xmlAttributes);
        mapScen[i].insert("PULSE_DURATION_L",xmlAttributes);
        mapScen[i].insert("PULSE_DURATION_S",xmlAttributes);
        mapScen[i].insert("CURRENT_S",xmlAttributes);
        mapScen[i].insert("CURRENT_L",xmlAttributes);
        mapScen[i].insert("COMMENTS",xmlAttributes);
	
	

// Цвет фона по умолчанию
blockDevice->T_DEVICE_TIME->setStyleSheet("QLabel { background-color : rgb(245,245,245) }");	

// Очистить содержимое
blockDevice->T_DEVICE_TIME->clear();

// Удалить StyleSheet
blockDevice->T_DEVICE_TIME->setStyleSheet("");
	
"QLabel{"
"	background-color: rgb(245,245,245);"
"	border: 1.4px solid gray;"
" 	border-radius: 2px;"
"    margin-left: 1ex; "
"}"	

T_VERSION


Имя прибора
QLabel{
	background-color: rgb(245,245,245);
	border: 1.4px solid gray;
 	border-radius: 2px;
    margin-left: 1ex; 
}
        blockDevice->T_DEVICE->setStyleSheet("QLabel{"
                                                  " background-color: rgb(245,245,245); "
                                                  " border: 1.4px solid gray; "
                                                  " border-radius: 2px; "
                                                  " margin-left: 1ex; "
                                                  "}");


Версия прошивки
QLabel{
	background-color: rgb(245,245,245);
	border: 1.4px solid gray;
 	border-radius: 2px;
    margin-left: 1ex; 
}
        blockDevice->T_VERSION->setStyleSheet("QLabel{"
                                                  " background-color: rgb(245,245,245); "
                                                  " border: 1.4px solid gray; "
                                                  " border-radius: 2px; "
                                                  " margin-left: 1ex; "
                                                  "}");


Заводской номер
QLabel{
	background-color: rgb(245,245,245);
	border: 1.4px solid gray;
 	border-radius: 2px;
    margin-left: 1ex; 
}
        blockDevice->T_NUMBER->setStyleSheet("QLabel{"
                                                  " background-color: rgb(245,245,245); "
                                                  " border: 1.4px solid gray; "
                                                  " border-radius: 2px; "
                                                  " margin-left: 1ex; "
                                                  "}");
												  
Напряжение питания батареи
QLabel{
	background-color: rgb(245,245,245);
	border: 1.4px solid gray;
 	border-radius: 2px;
    margin-left: 1ex; 
}
        blockDevice->T_BATTERY->setStyleSheet("QLabel{"
                                                  " background-color: rgb(245,245,245); "
                                                  " border: 1.4px solid gray; "
                                                  " border-radius: 2px; "
                                                  " margin-left: 1ex; "
                                                  "}");

	

// Цвет фона ячейки	
TAB->item(2,2)->setBackground(Qt::red);
TAB->item(3,3)->setBackground(QColor(255, 85, 127));

TAB->horizontalHeader()->setStretchLastSection(true); // Размер таблицы будет отмасштабирован по размеру основного окна	
	

 QTableWidget{
 background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,
                                   stop: 0 #cfcfcf, stop: 1 #ffffff);
 border: 1.5px solid gray;
 border-radius: 4px;
}


                // Версия XML
                QString version = xmlReader.documentVersion().toString();
                // Тип кодировки в данном документе XML
                QString encoding = xmlReader.documentEncoding().toString();
				
/*  Алгоритм работы с Flash памятью прибора:
    0. Создать bin файл на компьютер. Закрыть его.
    1. Записать нули в "указатель памяти" - регистры адреса начала блока памяти Adr_Mem_Hi (0x1029) и Adr_Mem_LO (0x102a).
    2. Прочитать "указатель памяти": Adr_Mem_Hi (0x1029) и Adr_Mem_LO (0x102a).
    3. Прочитать первый блок памяти (начиная с регистра Adr_Mem_Home), Количество регистров задаётся константной num_reg_to_read.
       Не забывать, что в регистре 2 байта. В bin файл данные записываются побайтно.
       Открыть файл - записать в него прочитанный блок - закрыть файл.
       Проверить, что данные в памяти закончились: признак завешения - последовательность подряд не менее 20 нулей '\0'.
    4. Проверить, что "указатель памяти" увеличился на размер блока, прочитанного в пункте №3.
    5. Прочитать следующий блок памяти начиная с того же регистра Adr_Mem_Home, и далее как в пункте №3.
*/	


УДАЛИЛ, но может еще пригодится

void AGIS_MID::ReadFlashPtr(){
    if((DEVICE->isEnabled()) && (InitComplete == true)){
        if(!setupReadPackage(MID_REG::Adr_Mem_Hi,2,FLAG_DATA::Adr_Mem_ptr_Read)){
            qDebug() << "ERROR";
        }
    }
}			



3 42df0a
4 0adfbe
5 dfb40a
6 df0ac4

DEVICE->setTimeOut(20);
DEVICE->setCountCheck(0);
DEVICE->setCountMiss(0);








Adr_Reg_Sost            = 0x600,    // Регистр состояния.
ADR_NUM_DEV             = 0x0001,   // Регистр хранения заводского номера устройства (чтение и запись).













// Отключение от COM порта
void  AGIS_MID::clicked_Disconnected(bool com){
    QMessageBox msgBox;
    msgBox.setWindowTitle("Disconnected");
    msgBox.setText("Отключить прибор?");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    if(msgBox.exec() == QMessageBox::Yes){

        if(com){ DEVICE->disconnected(); }
        InitComplete = false;
        // Состояние кнопок после отключения от COM-порта
        blockDevice->B_CONNECTED   ->setEnabled(true);
        blockDevice->B_DISCONNECTED->setEnabled(false);
        blockDevice->B_UPDATE_COM  ->setEnabled(true);
        blockDevice->B_PLAY        ->setEnabled(false);
        blockDevice->B_SCENARIO    ->setEnabled(false);
        blockDevice->B_FLASH       ->setEnabled(false);
        blockDevice->B_CLEAR       ->setEnabled(false);
        blockDevice->B_DEPTH       ->setEnabled(false);
        blockDevice->B_TEST        ->setEnabled(false);

        blockDevice->B_CLOCK       ->setEnabled(false);
        blockDevice->B_CLOCK_START ->setEnabled(false);
        blockDevice->B_CLOCK_START->setChecked(false);
        blockDevice->B_CLOCK_START ->setIcon(QIcon(QPixmap (":/Image/Ico/Time_start.png")));
        blockDevice->B_PLAY->setIcon(QIcon(QPixmap (":/Image/Ico/Start.png")));

        TM_RTC_RunClock->stop(); // Остановить Таймер показа текущего значения часов RTC
        TM_PriborRun->stop();

        // Установим стиль отображения поля Часов реального времени по умолчанию
        blockDevice->T_DEVICE_TIME->setStyleSheet(" QLabel{ "
                                                  "	background-color: rgb(245,245,245); "
                                                  "	border: 1.4px solid gray; "
                                                  " border-radius: 2px; "
                                                  " margin-left: 1ex; "
                                                  " } ");
        // Поле Имя прибора
        blockDevice->T_DEVICE->setStyleSheet(" QLabel{ "
                                             " background-color: rgb(245,245,245); "
                                             " border: 1.4px solid gray; "
                                             " border-radius: 2px; "
                                             " margin-left: 1ex; "
                                             "}");
        // Поле Версия прошивки
        blockDevice->T_VERSION->setStyleSheet(" QLabel{ "
                                             " background-color: rgb(245,245,245); "
                                             " border: 1.4px solid gray; "
                                             " border-radius: 2px; "
                                             " margin-left: 1ex; "
                                             "}");
        // ПолеЗаводской номер
        blockDevice->T_NUMBER->setStyleSheet(" QLabel{ "
                                             " background-color: rgb(245,245,245); "
                                             " border: 1.4px solid gray; "
                                             " border-radius: 2px; "
                                             " margin-left: 1ex; "
                                             " } ");
        // Поле Напряжение питания батареи
        blockDevice->T_BATTERY->setStyleSheet(" QLabel{ "
                                              " background-color: rgb(245,245,245); "
                                              " border: 1.4px solid gray; "
                                              " border-radius: 2px; "
                                              " margin-left: 1ex; "
                                              " } ");

        blockDevice->T_DEVICE->clear();
        blockDevice->T_VERSION->clear();
        blockDevice->T_NUMBER->clear();
        blockDevice->T_BATTERY->clear();
        blockDevice->T_DEVICE_TIME->clear();


    }
}








        if(MyPackage::DataVector::SlaveRead == code){
            dataReadScen = PACKAGE->get_ValueRegistr();

            bool isVerification = true;
            for (int i = 0; i < 180; ++i) {
                if (dataReadScen.at(i) != scenario->dataScenToWrite.at(i))
                {
                    isVerification = false;
                }
            }
            if (isVerification)
                QMessageBox::information(scenario, "ScenWrite", "Сценарий в прибор записан!\nВерификация данных прошла успешно!", QMessageBox::Ok);
        }
        else{ WrongCheckbox(); }
        break;



// ------------------------------------------------------------------------------------------------------------------------------
// --------------- Кнопка READ FLASH - Чтение из Flash памяти
// ------------------------------------------------------------------------------------------------------------------------------

void  AGIS_MID::clicked_ReadFlash()
{
    localMessage("Кнопка ReadFlash", "Нажата");
/*  Алгоритм работы с Flash памятью прибора:
    0. Создать bin файл на компьютер. Закрыть его.
    1. Записать нули в "указатель памяти" - регистры адреса начала блока памяти Adr_Mem_Hi (0x1029) и Adr_Mem_LO (0x102a).
    2. Прочитать "указатель памяти": Adr_Mem_Hi (0x1029) и Adr_Mem_LO (0x102a).
    3. Прочитать первый блок памяти (начиная с регистра Adr_Mem_Home). Количество регистров задаётся константной num_reg_to_read.
       Не забывать, что в регистре 2 байта. В bin файл данные записываются побайтно.
       Открыть файл - записать в него прочитанный блок - закрыть файл.
       Проверить, что данные в памяти закончились: признак завешения - последовательность подряд не менее 10 нулей '\0'.
    4. Проверить, что "указатель памяти" увеличился на размер блока, прочитанного в пункте №3.
    5. Прочитать следующий блок памяти начиная с того же регистра Adr_Mem_Home, и далее как в пункте №3.
*/
    DEVICE->setTimeOut(2000);
    DEVICE->setCountCheck(2);   // Кол-во проверок длины ответа
    DEVICE->setCountMiss(2);    // После кол-ва итераций CountCheck делаем перезапрос

    // 0. Создать bin файл на компьютер: Выбрать имя и путь для файла
    QString Path = QFileDialog::getSaveFileName(blockDevice,
                                                        "Выбрать файл для сохранения FLASH прибора в формате bin",
                                                        "C:\\",
                                                        "All Files (*.*)");
    binfile.setFileName(Path);
    if(Path != "")
    {
        binfile.open(QIODevice::WriteOnly);
        binfile.close();
    } else { return; }

    // 1. Записали нули в "указатель памяти"
    QByteArray ArrNull; // 4 байта нулей, которые потом запишем в "указатель памяти" (2 регистра по 2 байта)
    ArrNull.append(char(0x00));
    ArrNull.append(char(0x00));
    ArrNull.append(char(0x00));
    ArrNull.append(char(0x00));
    if((DEVICE->isEnabled()) && (InitComplete == true)){
        if(!setupWritePackage(MID_REG::Adr_Mem_Hi,ArrNull,2,FLAG_DATA::Adr_Mem_ptr_Reset)){
            qDebug() << "Ошибка обнуления регистра адреса начала блока памяти";
            localError(MyError::ScenarioLose, "Device_AGIS_MID::command_WriteScen()", "Запрос не отправлен.");
            DEVICE->setTimeOut(20);
            DEVICE->setCountCheck(0);
            DEVICE->setCountMiss(0);
        }
    }
}

// Обнуление регистров адреса начала блока памяти
void AGIS_MID::Adr_Mem_ptr_Reset()
{
    qDebug() << "Обнуление регистров адреса начала блока памяти OK";
    if((DEVICE->isEnabled()) && (InitComplete == true)){
        // 2. Прочитать "указатель памяти".
        if(!setupReadPackage(MID_REG::Adr_Mem_Hi,2,FLAG_DATA::Adr_Mem_ptr_Read)){
        qDebug() << "ERROR";
        DEVICE->setTimeOut(20);
        DEVICE->setCountCheck(0);
        DEVICE->setCountMiss(0);
        }
    }
}

// Чтение "указателя памяти"
void AGIS_MID::Adr_Mem_ptr_Read()
{
    Adr_Mem_ptrData = PACKAGE->get_ValueRegistr();
    Conv.UC[0] = Adr_Mem_ptrData.at(3);
    Conv.UC[1] = Adr_Mem_ptrData.at(2);
    Conv.UC[2] = Adr_Mem_ptrData.at(1);
    Conv.UC[3] = Adr_Mem_ptrData.at(0);
    Adr_Mem_ptr = Conv.I32;
    /* Проверим, что "указатель памяти" изменился на количество прочитанных байтов памяти прибора.
    На первой итерации Mem_block.size()=0 (потому что еще ничего не прочитали) и Adr_Mem_ptr=0 (потому что только что
    обнулили "указатель памяти") */
    if (Mem_block.size() == Adr_Mem_ptr) {
        qDebug() <<"Указатель памяти увеличился на размер прочитанного блока памяти";
        if((DEVICE->isEnabled()) && (InitComplete == true)){
            // 3. Прочитали первый блок памяти (начиная с регистра Adr_Mem_Home).
            if(!setupReadPackage(MID_REG::Adr_Mem_Home,num_reg_to_read,FLAG_DATA::Adr_Mem_Read_block)){
            qDebug() << "ERROR";
            DEVICE->setTimeOut(20);
            DEVICE->setCountCheck(0);
            DEVICE->setCountMiss(0);
            }
        }
    } else {
        qDebug() <<" 'Указатель памяти' не соответствует реальному количеству прочитанных блоков памяти";
        DEVICE->setTimeOut(20);
        DEVICE->setCountCheck(0);
        DEVICE->setCountMiss(0);
        }
}

// Чтение блока памяти
void AGIS_MID::Adr_Mem_Read_block()
{
    Mem_block.append(PACKAGE->get_ValueRegistr());
    if (binfile.open(QIODevice::Append))
    {
        // Добавить прочитанный блок памяти в конец bin файла
        // num_reg_to_read * 2 - умножаем на 2 потому что в регистре 2 байта
        binfile.write(Mem_block.mid((Mem_block.size()-num_reg_to_read*2),-1));
    }
    binfile.close();

    qDebug() << "Mem_block.size() = " << Mem_block.size();
    qDebug() << "num_reg_to_read*2 = " << num_reg_to_read*2;
    qDebug() << "Mem_block.size() - num_reg_to_read*2 = " << (Mem_block.size() - num_reg_to_read*2);

    ++CountFlashBlock; // Счетчик прочитанных блоков памяти

    // Проверка завершения блока памяти
    // Просмотреть прочитанный блок на предмет наличия непрерывной последовательности нулей
    int i = 0;
    int j = 0;
    int temp_null = 0;
    for (i = (Mem_block.size() - num_reg_to_read*2); i < Mem_block.size(); ++i)
    {
        if (QString(Mem_block.at(i)) == '\0') {
            ++temp_null;
        }
        else
        {
            // В массив запишем все варианты нулевых последовательностей.
            // Каждый элемент массива - это число следований подряд нулей до ненулевого символа.
            count_null[j] = temp_null;
            ++j;
            temp_null = 0;
        }
    }

    // Найдем наибольшее кол-во следование нулей подряд
    int count_null_max = 0;
    for (i = 0; i < num_reg_to_read*2; ++i)
    {
        if (count_null[i] > count_null_max)
            count_null_max = count_null[i]; // Наибольшее кол-во следований нулей подряд
    }

    qDebug() << "Наибольшее кол-во подряд нулей в прочитанном блоке = " << count_null_max;
    qDebug() << "Текущий размер массива Mem_block: size() = " << Mem_block.size();
    qDebug() << "Прочитано блоков памяти CountFlashBlock = " << CountFlashBlock;

    qDebug() << "А сейчас вылетит птичка!";

    qDebug() <<" Размер bin файла в байтах: " << binfile.size();

    if (count_null_max > 10) {
        qDebug() <<"Блок памяти завершен. Дальше нули...";

        DEVICE->setTimeOut(20);
        DEVICE->setCountCheck(0);
        DEVICE->setCountMiss(0);

        QMessageBox::information(blockDevice, "FlashRead", "Flash память из прибора прочитана", QMessageBox::Ok);
        return; // Процесс считывания Flash памяти прибора завершен
    } else {
        // 4. Проверить, что "указатель памяти" увеличился на размер блока, прочитанного в пункте №3
        if((DEVICE->isEnabled()) && (InitComplete == true)){
            if(!setupReadPackage(MID_REG::Adr_Mem_Hi,2,FLAG_DATA::Adr_Mem_ptr_Read)){
                qDebug() << "ERROR";
                DEVICE->setTimeOut(20);
                DEVICE->setCountCheck(0);
                DEVICE->setCountMiss(0);
            }
        }
    }
}







    struct RGB
    {
        RGB(short red, 
			short green, 
			short blue) : 	red(red), 
							green(green), 
							blue(blue) {}
        short red;
        short green;
        short blue;
    };
    QVector<RGB> vec;

    short red = 10;
    short green = 20;
    short blue = 30;
    vec.append(RGB(red,green,blue));
    vec.append(RGB(1,2,3));

    qDebug() << vec.at(0).red;

    vec[0].red=1000;
    qDebug() << vec[0].red;


    //QVector<vector> VECTOR;


    QByteArray Arr;
    qDebug() << Arr.size();

    Arr.append(char(0x00));
    qDebug() << Arr.size();

    Arr.append(char(0x01));
    qDebug() << Arr.size();

    qDebug() << "* * * * * * * ";
    int a[1];
    qDebug() << sizeof(a);

    qDebug() << "* * * * * * * ";
    QByteArray ba;
    ba.resize(5);
    //ba[0] = 0x3c;
    //ba[1] = 0xb8;
    //ba[2] = 0x64;
    //ba[3] = 0x18;
    //ba[4] = 0xca;
    qDebug() << ba.size();

    VECTOR.append(v);
    VECTOR.append(v);
    VECTOR.append(v);
    VECTOR[0].day = 10;
    VECTOR[0].BCcouting[0] = 10;
	
	
	
	
struct header{
        char StartSign[16];         // Признак начала работы по включению питания или переходу на новый сценарий – 16 байт 0x11;
        char NameDevice[16];        // Имя прибора в текстовом виде – 16 байт
        char NumberDevice[16];      // № прибора в текстовом виде – 16 байт;
        uint16_t FirmwareVersion;   // № версии прошивки – 2 байта;
        char NumScen;               // Номер текущего сценария – 1 байт.
        char FileScen[180];         // Файл сценариев – 180 байт.
        char reserve[25];           // Резерв - 25 байт.
    };	
	
    struct header{
        char StartSign[16];         // Признак начала работы по включению питания или переходу на новый сценарий – 16 байт 0x11;
        char NameDevice[16];        // Имя прибора в текстовом виде – 16 байт
        char NumberDevice[16];      // № прибора в текстовом виде – 16 байт;
        char FirmwareVersion[2];    // № версии прошивки – 2 байта;
        char NumScen;               // Номер текущего сценария – 1 байт.
        char FileScen[180];         // Файл сценариев – 180 байт.
        char reserve[25];           // Резерв - 25 байт.
    };


    /* Поиск <ЗАПИСЕЙ>. <ЗАПИСЬ> состоит из: <ЗАГОЛОВОК> + <ВЕКТОР №1> + ... + <ВЕКТОР №n>
     <ЗАГОЛОВОК> начинается с последовательности - 16 байт 0x11. 
    Соответственно, ищем индексы в массиве ArrFileFull, с которых будут начинаться блоки по 16 байт 0x11 подряд */
    int UnitCounter = 0;        // Счетчик байтов 0x11
    int indexStartUnit = 0;     // Индекс байта, с которого началась последовательность 0x11
    QVector<int> ArrStartUnit;
    for (int i = 0; i < ArrFileFull.size(); ++i)
    {
        if (ArrFileFull.at(i) == 0x11)
        {
            ++UnitCounter;
            if (UnitCounter == 16)
            {
                indexStartUnit = i - 15; // 15 - потому что отсчет в массиве с 0
                ArrStartUnit.append(indexStartUnit);
                UnitCounter = 0;
            }
        } else UnitCounter = 0;
    }
	
	
/*
    // Заполним <ЗАГОЛОВОК> из bin файла
    int i = 0; // Индекс элемента в массиве ArrFileFull
    int j = 0;
    for (i = 0; i < 16; ++i){
        HEADER.StartSign[j] = ArrFileFull.at(i);
        ++j;
    } j = 0;

    for (i = 16; i < 32; ++i){
        HEADER.NameDevice[j] = ArrFileFull.at(i);
        ++j;
    } j = 0;

    for (i = 32; i < 48; ++i){
        HEADER.NumberDevice[j] = ArrFileFull.at(i);
        ++j;
    } j = 0;

    for (i = 48; i < 50; ++i){
        HEADER.FirmwareVersion[j] = ArrFileFull.at(i);
        ++j;
    } j = 0;

    // Версия прошивки в формате uint16_t
    uint16_t FirmwareVersion16_t = ((uint16_t)(HEADER.FirmwareVersion[0]) << 8) | (uint16_t)HEADER.FirmwareVersion[1];

    HEADER.NumScen = ArrFileFull.at(50);

    for (i = 51; i < 231; ++i){
        HEADER.FileScen[j] = ArrFileFull.at(i);
        ++j;
    }

    for (i = 231; i < 256; ++i){
        HEADER.reserve[j] = ArrFileFull.at(i);
        ++j;
    } j = 0;

    // Заполним <ВЕКТОР> из bin файла
    VECTOR.null = ArrFileFull.at(256);
    VECTOR.numscen = ArrFileFull.at(257);
    i = 258; // Индекс элемента в массиве ArrFileFull
    for (j = 0; j < 52; ++j) {
        VECTOR.BCcouting[j].byte[0] = ArrFileFull.at(i);
        VECTOR.BCcouting[j].byte[1] = ArrFileFull.at(i+1);
        VECTOR.BCcouting[j].byte[2] = ArrFileFull.at(i+2);
        i = i + 3;
    }
    uint32_t BCcouting32_t[52] = {0}; // в формате uint32_t
    for (j = 0; j < 52; ++j) {
    BCcouting32_t[j] = ((uint32_t)(VECTOR.BCcouting[j].byte[0]) << 16) | ((uint32_t)VECTOR.BCcouting[j].byte[1] << 8) | ((uint32_t)VECTOR.BCcouting[j].byte[2]);
    }

    i = 414;
    for (j = 0; j < 41; ++j) {
        VECTOR.SCcouting[j].byte[0] = ArrFileFull.at(i);
        VECTOR.SCcouting[j].byte[1] = ArrFileFull.at(i+1);
        VECTOR.SCcouting[j].byte[2] = ArrFileFull.at(i+2);
        i = i + 3;
    }
    uint32_t SCcouting32_t[41] = {0}; // Отсчеты Малой катушки в формате uint32_t
    for (j = 0; j < 41; ++j) {
    SCcouting32_t[j] = ((uint32_t)(VECTOR.SCcouting[j].byte[0]) << 16) | ((uint32_t)VECTOR.SCcouting[j].byte[1] << 8) | ((uint32_t)VECTOR.SCcouting[j].byte[2]);
    }

    Conv.UC[0] = ArrFileFull.at(540);
    Conv.UC[1] = ArrFileFull.at(539);
    Conv.UC[2] = ArrFileFull.at(538);
    Conv.UC[3] = ArrFileFull.at(537);
    VECTOR.Bcurrent = Conv.F;

    Conv.UC[0] = ArrFileFull.at(544);
    Conv.UC[1] = ArrFileFull.at(543);
    Conv.UC[2] = ArrFileFull.at(542);
    Conv.UC[3] = ArrFileFull.at(541);
    VECTOR.Scurrent = Conv.F;

    Conv.UC[0] = ArrFileFull.at(546);
    Conv.UC[1] = ArrFileFull.at(545);
    VECTOR.MAGN1 = Conv.U16;

    Conv.UC[0] = ArrFileFull.at(548);
    Conv.UC[1] = ArrFileFull.at(547);
    VECTOR.MAGN2 = Conv.U16;

    Conv.UC[0] = ArrFileFull.at(550);
    Conv.UC[1] = ArrFileFull.at(549);
    VECTOR.RAX_ADCU = Conv.U16;

    Conv.UC[0] = ArrFileFull.at(552);
    Conv.UC[1] = ArrFileFull.at(551);
    VECTOR.RAY_ADCU = Conv.U16;

    Conv.UC[0] = ArrFileFull.at(554);
    Conv.UC[1] = ArrFileFull.at(553);
    VECTOR.RAZ_ADCU = Conv.U16;

    VECTOR.second = ArrFileFull.at(555);
    VECTOR.minute = ArrFileFull.at(556);
    VECTOR.hour = ArrFileFull.at(557);
    VECTOR.dayWeek = ArrFileFull.at(558);
    VECTOR.day = ArrFileFull.at(559);
    VECTOR.month = ArrFileFull.at(560);
    VECTOR.year = ArrFileFull.at(561);

    Conv.UC[0] = ArrFileFull.at(565);
    Conv.UC[1] = ArrFileFull.at(564);
    Conv.UC[2] = ArrFileFull.at(563);
    Conv.UC[3] = ArrFileFull.at(562);
    VECTOR.U_V = Conv.F;
*/	

 


        /* Тут нужно передать в основную программу: NameDevice (Имя прибора в текстовом виде)
                                                    NumberDevice (№ прибора в текстовом виде)
                                                    FirmwareVersion (№ версии прошивки) */



            /*
            VECTOR.numscen = 0;
            VECTOR.Bcurrent = 0;
            VECTOR.Scurrent = 0;
            VECTOR.second = 0;
            VECTOR.minute = 0;
            VECTOR.hour = 0;
            VECTOR.dayWeek = 0;
            VECTOR.day = 0;
            VECTOR.month = 0;
            VECTOR.year = 0;
            VECTOR.MAGN1 = 0;
            VECTOR.MAGN2 = 0;
            VECTOR.RAX_ADCU = 0;
            VECTOR.RAY_ADCU = 0;
            VECTOR.RAZ_ADCU = 0;ы
            VECTOR.BCcouting->byte[0] = 0;
            VECTOR.BCcouting->byte[1] = 0;
            VECTOR.BCcouting->byte[2] = 0;
            VECTOR.SCcouting->byte[0] = 0;
            VECTOR.SCcouting->byte[1] = 0;
            VECTOR.SCcouting->byte[2] = 0;
            */
			
			
			// Акселерометр X [у.е.]
			GRAPH->addData(1,Conv.U16);     // Канал 1
    /*
    GRAPH->addData(N,Conv.XXX) - Здесь мы добавляем данные в канал номер N. Это точка по оси Y.
    Для оси Х временная точка для всех каналов одна. Чтобы её добавить нужно использовать addDateTime();
    */

    QDateTime DAT = QDateTime::currentDateTime(); // Текущее время на компьютере.
    //DAT = DAT.addSecs(1);
    GRAPH->addDateTime(DAT);	



    struct vector {
        char null           = 0;    // 0x00
        char numscen        = 0;    // Номер сценария
        uint24_t BCcouting[52];     // Отсчеты Большой катушки
        uint24_t SCcouting[41];     // Отсчеты Малой катушки
        float Bcurrent      = 0;    // Ток БК в амперах
        float Scurrent      = 0;    // Ток МК в амперах
        uint16_t MAGN1      = 0;    // Значение магнитного поля МК перед импульсом возбуждения
        uint16_t MAGN2      = 0;    // Значение магнитного поля МК в конце импульса возбуждения
        uint16_t RAX_ADCU   = 0;    // Значение акселерометра по оси X в битах АЦП
        uint16_t RAY_ADCU   = 0;    // Значение акселерометра по оси Y в битах АЦП
        uint16_t RAZ_ADCU   = 0;    // Значение акселерометра по оси Z в битах АЦП
        uint8_t second      = 0;    // Время – секунды
        uint8_t minute      = 0;    // Время – минуты
        uint8_t hour        = 0;    // Время – час
        uint8_t dayWeek     = 0;    // Время – день недели
        uint8_t day         = 0;    // Дата – день
        uint8_t month       = 0;    // Дата – месяц
        uint8_t year        = 0;    // Дата – год
        float U_V           = 0;    // Значение напряжения батареи
    };
	
	VECTOR.Bcurrent
	VECTOR.Scurrent
	VECTOR.MAGN1
	VECTOR.MAGN2
	VECTOR.RAX_ADCU
	VECTOR.RAY_ADCU
	VECTOR.RAZ_ADCU
	VECTOR.U_V
	VECTOR.
	VECTOR.
	
CPP
void ScenarioSelection::on_Button_OK_clicked()
{
    qDebug() << "1111111";
}

void ScenarioSelection::on_Button_CANSEL_clicked()
{
    qDebug() << "2222222";
}

H
private slots:
    void on_Button_OK_clicked();
    void on_Button_CANSEL_clicked();
	
    QMultiMap<QString, int> multimap;
    multimap.insert("a", 1);
    multimap.insert("a", 2);
    multimap.insert("b", 3);
    multimap.insert("c", 4);
    multimap.insert("c", 5);
    multimap.insert("plenty", 100);
    multimap.insert("plenty", 2000);

    QList<int> values = multimap.values("plenty");
    for (int i = 0; i < values.size(); ++i)
         qDebug() << values.at(i);	
	 
*********************************************************************************************************************************

Ходаковский Андрей Владимирович, [07.12.2022 11:25]
//**************структура запроса***********************************************
typedef __packed struct _QueryDataTypeDef
  {
  uint16_t   ModuleAddress;    //адрес опрашиваемого модуля
  uint8_t   CmdType;          //QUERY_DATA
  uint16_t  Size;              //общая длина пакета (включая CRC16)
  uint8_t    Flags;            //
  uint32_t  SystemTimeStamp;  //время отправки запроса мс
  uint32_t  SystemTime_tag;  //время опроса модуля мс
  uint8_t    LastPartNo;        //последняя полученная часть
  uint16_t  CRC16;
  }QueryDataTypeDef;

extern volatile QueryDataTypeDef* p_QueryData;

Ходаковский Андрей Владимирович, [07.12.2022 11:27]
extern volatile uint8_t hod_buffer_RX_decoder[RX_BUFER_SIZE];//Буфер декодированных команд

Ходаковский Андрей Владимирович, [07.12.2022 11:28]
//установим указатель  структуры команды p_QueryData на буфер декодированной команды 
 p_QueryData = (QueryDataTypeDef*)&hod_buffer_RX_decoder;

Ходаковский Андрей Владимирович, [07.12.2022 11:29]
if ((Flag_CRC_ok)&&((p_QueryData->ModuleAddress) == AnswerData.ModuleAddress)&&((p_QueryData->CmdType) == 0x05U))
      {  //Приняли команду выдать данные, проваливаемся на следующий case State_USART3_RX_Command_Get_Data 
            Global_main_State = State_Command_Get_Data;
            rx_OK++;
        }

















