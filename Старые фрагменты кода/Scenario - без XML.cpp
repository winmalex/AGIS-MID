/*
// ------------------------------------------------------------------------------------------------------------------------------
// --------------- Кнопка - Сохранить сценарий на компьютер. Без XML
// ------------------------------------------------------------------------------------------------------------------------------
void Scenario::on_B_SaveTable_clicked(){

    QComboBox *comboBoxRead[10];    // Нужно для считывания ComboBox
    int IndexComboBox [10];         // Значения индексов в ComboBox
    QString ValueComboBox[4] = {"Не работает",
                                "Униполярный режим, положит. полярность",
                                "Униполярный режим, отрицат. полярность",
                                "Биполярный режим"};
    QString strFlag;

    if (!(CheckScenarioTable())) {
        QString Path = QFileDialog::getSaveFileName(0,"Укажите путь для сохранения","","Scenario Files (*.scn)");
        if(Path != ""){
            QFile FILE(Path);
            FILE.open(QFile::WriteOnly);
            if(FILE.isOpen()){

                for(int i = 0; i < 10; i++){

                    comboBoxRead[i] = qobject_cast< QComboBox* >(TAB->cellWidget(i, 0));
                    IndexComboBox[i] = comboBoxRead[i]->currentIndex();

                    switch(IndexComboBox[i])
                    {
                        case 0: strFlag = ValueComboBox[0];
                            break;
                        case 1: strFlag = ValueComboBox[1];
                            break;
                        case 2: strFlag = ValueComboBox[2];
                            break;
                        case 3: strFlag = ValueComboBox[3];
                            break;
                    }
                    FILE.write((strFlag + "\t").toUtf8());

                    FILE.write((TAB->item(i,1)->text() + "\t").toUtf8());
                    FILE.write((TAB->item(i,2)->text() + "\t").toUtf8());
                    FILE.write((TAB->item(i,3)->text() + "\t").toUtf8());
                    FILE.write((TAB->item(i,4)->text() + "\t").toUtf8());
                    FILE.write((TAB->item(i,5)->text() + "\t").toUtf8());
                    FILE.write((TAB->item(i,6)->text() + "\t").toUtf8());
                    FILE.write((TAB->item(i,7)->text() + "\t").toUtf8());
                    FILE.write((TAB->item(i,8)->text() + "\t").toUtf8());

                    FILE.write("\n");
                }
            }
            FILE.close();
        }
    }
    else {
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Неправильно введены данные в таблицу");
            messageBox.setFixedSize(500,200);
        }
}


// ------------------------------------------------------------------------------------------------------------------------------
// --------------- Кнопка - Загрузить сценарий с компьютера. Без XML
// ------------------------------------------------------------------------------------------------------------------------------
void Scenario::on_B_LoadTable_clicked(){

    TAB->resizeColumnsToContents();
    TAB->resizeRowsToContents();

    QComboBox *comboBox[10];        // Массив указателей на QComboBox. По одному ComboBox на каждый сценарий.

    QString Path = QFileDialog::getOpenFileName(0,"Выберите файл","","Scenario Files (*.scn)");
    if(Path != ""){
        QFile FILE(Path);
        FILE.open(QFile::ReadOnly);
        if(FILE.isOpen()){

            TAB->clear();
            TAB->setColumnCount(DEV_LEN[KEY-1]);
            TAB->setHorizontalHeaderLabels(DEV_HEADER[KEY-1]);

            QStringList Line;

            for(int i = 0; i < 10; i++){

                Line = ((QString)FILE.readLine()).split('\t');

                TAB->setItem(i,0, new QTableWidgetItem());
                TAB->item(i,0)->setTextAlignment(Qt::AlignCenter);
                comboBox[i] = new QComboBox();
                TAB->setCellWidget(i, 0, comboBox[i]);  // Помещаем в ячейку i, 0
                comboBox[i]->addItem("Не работает");
                comboBox[i]->addItem("Униполярный режим, положит. полярность");
                comboBox[i]->addItem("Униполярный режим, отрицат. полярность");
                comboBox[i]->addItem("Биполярный режим");

                if      (Line.at(0) == "Не работает")                               { comboBox[i]->setCurrentIndex(0); }
                else if (Line.at(0) == "Униполярный режим, положит. полярность")    { comboBox[i]->setCurrentIndex(1); }
                else if (Line.at(0) == "Униполярный режим, отрицат. полярность")    { comboBox[i]->setCurrentIndex(2); }
                else if (Line.at(0) == "Биполярный режим")                          { comboBox[i]->setCurrentIndex(3); }

                TAB->setItem(i,1,   new QTableWidgetItem(Line.at(1)));
                TAB->item(i,1)->setTextAlignment(Qt::AlignCenter);

                TAB->setItem(i,2,   new QTableWidgetItem(Line.at(2)));
                TAB->item(i,2)->setTextAlignment(Qt::AlignCenter);

                TAB->setItem(i,3,   new QTableWidgetItem(Line.at(3)));
                TAB->item(i,3)->setTextAlignment(Qt::AlignCenter);

                TAB->setItem(i,4,   new QTableWidgetItem(Line.at(4)));
                TAB->item(i,4)->setTextAlignment(Qt::AlignCenter);

                TAB->setItem(i,5,   new QTableWidgetItem(Line.at(5)));
                TAB->item(i,5)->setTextAlignment(Qt::AlignCenter);

                TAB->setItem(i,6,   new QTableWidgetItem(Line.at(6)));
                TAB->item(i,6)->setTextAlignment(Qt::AlignCenter);

                TAB->setItem(i,7,   new QTableWidgetItem(Line.at(7)));
                TAB->item(i,7)->setTextAlignment(Qt::AlignCenter);

                TAB->setItem(i,8,   new QTableWidgetItem(Line.at(8)));
                TAB->item(i,8)->setTextAlignment(Qt::AlignCenter);
            }
        }
    }
}
*/

