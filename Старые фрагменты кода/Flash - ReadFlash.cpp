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
    4. Проверить, что "указатель памяти" увеличился на размер блока, прочитанного в пункте №3.
    5. Прочитать следующий блок памяти начиная с того же регистра Adr_Mem_Home, и далее как в пункте №3.
    6. Признак завершения Flash: последовательность подряд не менее 10 нулей '\0' или FF
*/
    DEVICE->setTimeOut(1);   // Лучше 1 !!! (Раньше было 2000)
    // Кол-во проверок длины ответа
    DEVICE->setCountCheck(10);   // Лучше 10 !!! (Раньше было 2)
    // После кол-ва итераций CountCheck делаем перезапрос
    DEVICE->setCountMiss(0);    // раньше было 0

    // Создать bin файл на компьютер: Выбрать имя и путь для файла
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

    QByteArray ArrNull; // 4 байта нулей, которые потом запишем в "указатель памяти" (2 регистра по 2 байта)
    ArrNull.append(char(0x00));
    ArrNull.append(char(0x00));
    ArrNull.append(char(0x00));
    ArrNull.append(char(0x00));
    if((DEVICE->isEnabled()) && (InitComplete == true)){
        // Обнуление регистров адреса начала блока памяти
        if(!setupWritePackage(MID_REG::Adr_Mem_Hi,ArrNull,2,FLAG_DATA::Adr_Mem_ptr_Reset)){
            qDebug() << "Ошибка обнуления регистра адреса начала блока памяти";
            localError(MyError::ScenarioLose, __PRETTY_FUNCTION__, "Запрос не отправлен.");
            DEVICE->setTimeOut(20);
            DEVICE->setCountCheck(0);
            DEVICE->setCountMiss(0);
        }
    }
}

void AGIS_MID::Adr_Mem_ptr_Reset()
{
    qDebug() << "Обнуление регистров адреса начала блока памяти OK";
    if((DEVICE->isEnabled()) && (InitComplete == true)){
        // Прочитать "указатель памяти".
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
            // Прочитали первый блок памяти (начиная с регистра Adr_Mem_Home).
            if(!setupReadPackage(MID_REG::Adr_Mem_Home,num_reg_to_read,FLAG_DATA::Adr_Mem_Read_block)){
            qDebug() << "ERROR";
            DEVICE->setTimeOut(20);
            DEVICE->setCountCheck(0);
            DEVICE->setCountMiss(0);
            }
        }
    } else {
        qDebug() <<" 'Указатель памяти' не соответствует реальному количеству прочитанных блоков памяти";

        return; // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        // Тут нужно отправить повторный запрос на чтение !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

        DEVICE->setTimeOut(20);
        DEVICE->setCountCheck(0);
        DEVICE->setCountMiss(0);
        }
}

// Чтение блока памяти
void AGIS_MID::Adr_Mem_Read_block()
{
    // На каждой итерации будем добавлять прочитанный блок памяти в массив Mem_block.
    Mem_block.append(PACKAGE->get_ValueRegistr());
    if (binfile.open(QIODevice::Append))
    {
        /* Добавить прочитанный блок памяти в конец bin файла.
        (Mem_block.size() - num_reg_to_read*2) - тут мы указываем с какого байта массива Mem_block начинаем записывать в файл binfile.
        В binfile записываем последний блок памяти массива Mem_block.
        num_reg_to_read * 2 - умножаем на 2 потому что в регистре содержится 2 байта */
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
        //if ( (QString(Mem_block.at(i)) == '\0') || (QString(Mem_block.at(i)).toInt() == 0xFF) ) {
        if  (QString(Mem_block.at(i)) == '\0') {
            ++temp_null;
        }
        else
        {
            // В массив запишем все варианты нулевых последовательностей.
            // Каждый элемент массива - это количество следований подряд нулей до ненулевого символа.
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
    qDebug() <<" Размер bin файла в байтах: " << binfile.size();

    if (count_null_max > 40) {
        qDebug() <<"Блок памяти завершен. Дальше нули или 0xFF...";

        DEVICE->setTimeOut(20);
        DEVICE->setCountCheck(0);
        DEVICE->setCountMiss(0);

        QMessageBox::information(blockDevice, "FlashRead", "Flash память из прибора прочитана", QMessageBox::Ok);

        return; // Процесс считывания Flash памяти прибора завершен

    } else {
        // Проверить, что "указатель памяти" увеличился на размер блока, прочитанного ранее
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