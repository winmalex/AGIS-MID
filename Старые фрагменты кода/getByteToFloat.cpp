
QString FileDAT_AGIS::getByteToFloat(float value){
    Conv.F = value;
    QByteArray line;
    line.append(Conv.UC[3]); line.append(Conv.UC[2]);
    line.append(Conv.UC[1]); line.append(Conv.UC[0]);

    QString val = "";
    val += line[0]; val += line[1];
    val += line[2]; val += line[3];

    return val;
}


Второй вариант

// Функций получает QString, преобразует в QByteArray и возвращает снова QString
std::string getByteToFloat(float value);

// Преобразование: float -> std::string
std::string FileDAT_AGIS::getByteToFloat(float number){
    Conv.F = number;
    std::string val = "";
    val += Conv.UC[0];  // Сначала - младший (так было в примере DAT файла)
    val += Conv.UC[1];
    val += Conv.UC[2];
    val += Conv.UC[3];
    return val;
}

void FileDAT_AGIS::save(QString path, DataGraph *data){
    AGISMetaDataList = data->getMetaData().split(" ");  // Поместим в AGISMetaDataList все МетаДанные из драйвера
    NAME_DEVICE = AGISMetaDataList.at(0);               // Имя прибора
    NUMBER_DEVICE = AGISMetaDataList.at(1);             // Номер прибора

    // Ищем файл
    QFile *Files = new QFile(path);

    // Открываем файл
    if(Files->open(QIODevice::WriteOnly)){

        qDebug() << "FileDAT_AGIS::len -> (кол-во Векторов в Записи)" << data->getSizeTimeLine(0);  

        std::string DataLine = NAME_DEVICE.toStdString() + "-" + NUMBER_DEVICE.toStdString();   // Строка №1
        Files->write(DataLine.data(),10);

        // Для тестовой проверки глубину DEPTH для каждого Вектора будем увеличчивать на 1
        int offset = 0;
        for(ID id = 0; id < data->getSizeTimeLine(0); id++){  // id - это номер Вектора из bin файла записи приора
            DataLine = getByteToFloat(DEPTH += 1);                                              // Строка №2
            DataLine += getByteToFloat(data->getData(7,id));                                    // Строка №3
            for (int i = 2; i < 53; ++i){
                DataLine += getByteToFloat(AGISMetaDataList.at(i+offset).toFloat());            // Строка №4
            }
            DataLine += getByteToFloat(data->getData(4,id));                                    // Строка №5
            DataLine += getByteToFloat(data->getData(9,id));                                    // Строка №6
            for (int i = 53; i < 95; ++i){
                DataLine += getByteToFloat(AGISMetaDataList.at(i+offset).toFloat());            // Строка №7
            }
            DataLine += getByteToFloat(Pressure);                                               // Строка №8
            DataLine += getByteToFloat(Temperature);                                            // Строка №9
            DataLine += getByteToFloat(data->getData(3,id));                                    // Строка №10
            offset += 93;
            Files->write(DataLine.data(),400);
        }

        qDebug() << "FileDAT_AGIS::save -> Completed!!!";
        Files->close();
        return;
    }
    qDebug() << "FileDAT_AGIS::save -> ERROR: File not open";
}
