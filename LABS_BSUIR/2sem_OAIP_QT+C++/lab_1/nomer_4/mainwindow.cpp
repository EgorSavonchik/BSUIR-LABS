 #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    add = new DialogAdd();
    correct = new DialogCorrect();

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->text1->hide();
    ui->text2->hide();
    ui->fileEdit->setText(filename);

    connect(add, SIGNAL(addclose()), this, SLOT(up()));
    connect(correct, SIGNAL(correctClose()), this, SLOT(forcorrect()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete add;

    if(!trainList)
    {
        delete[] trainList;
    }
}

void MainWindow::inut()
{
    if(!trainList)
    {
        delete[] trainList;
    }

    arraySize = 0;
    trainList = new train[1];
    ui->deleteList->clear();

    QFile file(filename);
    QTextStream in(&file);

    if(!file.exists())
    {
        ui->alarmLabel->setText("file not exist");
        ui->deleteList->clear();
        ui->destinationList->clear();

        return;
    }

    file.open(QIODevice::ReadOnly);

    ui->destinationList->clear();
    ui->destinationList->addItem("", 0);

    if(!destinationList)
    {
        delete[] destinationList;
    }

    QString tmp = "";

    for(int i = 0; !in.atEnd() ; i++)
    {
        tmp = in.readLine();

        if(!isTrain(tmp))
        {
            arraySize = 0;
            if(!trainList)
            {
                delete[] trainList;
            }

            if(!destinationList)
            {
                delete[] destinationList;
            }

            destinationListSize = 0;

            ui->alarmLabel->setText("uncorrect file");
            ui->destinationList->clear();

            return;
        }

        this->pushBack(tmp);

        append(trainList[i].destination);

        ui->deleteList->addItem(QString::number(i + 1), i);
    }

    file.close();

    for(int i = 0; i < destinationListSize; i++)
    {
        ui->destinationList->addItem(destinationList[i], i + 1);
    }
}

void MainWindow::save()
{
    QFile file(filename);
    QTextStream out(&file);

    file.open(QIODevice::WriteOnly);

    for(int i = 0; i < arraySize; i++)
    {
        out << trainList[i].fullname << '\n';
    }

    file.close();

    this->inut();

    this->on_viewFileButton_clicked();
}

bool MainWindow::isTrain(QString input)
{
    if(input.count(',') == 7 && input.count('.') == 4)
    {
        int i = 0;
        QString tmp;

        for(; i < input.length(); i++)
        {
            if(input[i] != ',')
            {
                tmp += input[i];
            }
            else
            {
                i++;
                break;
            }
        }

        if(tmp.length() == 10 && tmp.count('.') == 2)
        {
            if(tmp.mid(0, 2).toInt() && tmp.mid(3, 2).toInt() && tmp.mid(6, 4).toInt())
            {

            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        tmp.clear();

        for(; i < input.length(); i++)
        {

            if(input[i] != ',')
            {
                tmp += input[i];
            }
            else
            {
                i++;
                break;
            }
        }

        if(add->normalToInt(tmp) && tmp.toInt() >= 0)
        {

        }
        else
        {
            return false;
        }

        tmp.clear();

        for(; i < input.length(); i++)
        {
            if(input[i] != ',')
            {
                tmp += input[i];
            }
            else
            {
                i++;
                break;
            }
        }

        if(tmp == "")
        {
            return false;
        }

        tmp.clear();

        for(; i < input.length(); i++)
        {
            if(input[i] != ',')
            {
                tmp += input[i];
            }
            else
            {
                i++;
                break;
            }
        }

        if(tmp.length() == 5 && add->normalToInt(tmp.mid(0, 2)) && tmp.mid(0, 2).toInt() < 24 &&
                add->normalToInt(tmp.mid(3, 2)) && tmp.mid(3, 2).toInt() < 60)
        {
            if(tmp[2] != '.')
            {
                return false;
            }
        }
        else
        {
            return false;
        }

        tmp.clear();

        for(; i < input.length(); i++)
        {
            if(input[i] != ',')
            {
                tmp += input[i];
            }
            else
            {
                i++;
                break;
            }
        }

        if(!add->normalToInt(tmp))
        {
            return false;
        }

        tmp.clear();

        for(; i < input.length(); i++)
        {
            if(input[i] != ',')
            {
                tmp += input[i];
            }
            else
            {
                i++;
                break;
            }
        }

        if(!add->normalToInt(tmp))
        {
            return false;
        }

        tmp.clear();

        for(; i < input.length(); i++)
        {
            if(input[i] != ',')
            {
                tmp += input[i];
            }
            else
            {
                i++;
                break;
            }
        }

        if(!add->normalToInt(tmp))
        {
            return false;
        }

        tmp.clear();

        for(; i < input.length(); i++)
        {
            if(input[i] != '.')
            {
                tmp += input[i];
            }
            else
            {
                i++;
                break;
            }
        }

        if(!add->normalToInt(tmp))
        {
            return false;
        }

        return true;
    }

    return false;
}

void MainWindow::append(QString destination)
{
    bool isRepeat = false;

    if(destinationListSize == 0)
    {
        destinationList = new QString[1];

        destinationListSize += 1;
        destinationList[0] = destination;

        return;
    }

    for(int i = 0; i < destinationListSize; i++)
    {
        if(destinationList[i] == destination)
        {
            isRepeat = true;

            break;
        }
    }

    if(!isRepeat)
    {
        destinationListSize++;

        QString *temp = new QString[destinationListSize];

        for(int i = 0; i < destinationListSize - 1; i++)
        {
            temp[i] = destinationList[i];
        }

        if(!destinationList)
        {
            delete [] destinationList;
        }

        destinationList = temp;
        destinationList[destinationListSize - 1] = destination;
        temp = nullptr;
    }
}


void MainWindow::on_viewFileButton_clicked()
{

    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setRowCount(arraySize);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("departure date") << ("number") <<
                                                                  ("destination") << ("departure time") <<  ("compartment") <<
                                                                 ("reserved") << ("free compartment") << ("free reserved"));

    for(int i = 0; i < arraySize; i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(trainList[i].data));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(trainList[i].number)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(trainList[i].destination));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(trainList[i].time));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(trainList[i].compart)));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(trainList[i].reserved)));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number(trainList[i].compartFree)));
        ui->tableWidget->setItem(i, 7, new QTableWidgetItem(QString::number(trainList[i].reservedFree)));
    }
}

void MainWindow::pushBack(QString add)
{
    arraySize++;

    train *newArray = new train[arraySize];

    for(int i = 0; i < arraySize - 1; i++)
    {
        newArray[i] = trainList[i];
    }

    newArray[arraySize - 1] = add;

    delete[] trainList;

    trainList = newArray;

    newArray = nullptr;
}


void MainWindow::on_initialization_clicked()
{
    this->inut();
}

void MainWindow::on_freePlaces_clicked()
{
    ui->tableWidget->setColumnCount(6);
    ui->tableWidget->setRowCount(arraySize);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("departure date") << ("number") <<
                                                                  ("destination") << ("departure time") << ("free compartment") << ("free reserved"));

    for(int i = 0; i < arraySize; i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(trainList[i].data));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(trainList[i].number)));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem(trainList[i].destination));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(trainList[i].time));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number(trainList[i].compartFree)));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number(trainList[i].reservedFree)));
    }
}


void MainWindow::on_destinationList_currentTextChanged(const QString &arg1)
{
    if(arg1 == "")
    {
        ui->freeLabel->hide();
        ui->sellLabel->hide();
        ui->text1->hide();
        ui->text2->hide();

        ui->tableWidget->clear();

        return;
    }


    int allFree = 0, allSell = 0;

    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setRowCount(arraySize);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("departure date") << ("number") <<
                                                                  ("destination") << ("departure time") <<  ("compartment") <<
                                                                 ("reserved") << ("free compartment") << ("free reserved"));

    for(int i = 0, number = 0; i < arraySize; i++)
    {
        if(trainList[i].destination == arg1)
        {
            number++;
            ui->tableWidget->setRowCount(number);


            ui->tableWidget->setItem(number - 1, 0, new QTableWidgetItem(trainList[i].data));
            ui->tableWidget->setItem(number - 1, 1, new QTableWidgetItem(QString::number(trainList[i].number)));
            ui->tableWidget->setItem(number - 1, 2, new QTableWidgetItem(trainList[i].destination));
            ui->tableWidget->setItem(number - 1, 3, new QTableWidgetItem(trainList[i].time));
            ui->tableWidget->setItem(number - 1, 4, new QTableWidgetItem(QString::number(trainList[i].compart)));
            ui->tableWidget->setItem(number - 1, 5, new QTableWidgetItem(QString::number(trainList[i].reserved)));
            ui->tableWidget->setItem(number - 1, 6, new QTableWidgetItem(QString::number(trainList[i].compartFree)));
            ui->tableWidget->setItem(number - 1, 7, new QTableWidgetItem(QString::number(trainList[i].reservedFree)));

            allFree += trainList[i].reservedFree + trainList[i].compartFree;
            allSell += trainList[i].compart + trainList[i].reserved;
        }
    }

    ui->text1->show();
    ui->text2->show();
    ui->freeLabel->show();
    ui->sellLabel->show();

    ui->freeLabel->setNum(allFree);
    ui->sellLabel->setNum(allSell);
}


void MainWindow::on_weekButton_clicked()//первый день года - понедельник - в месяце 30 дней
{
    int dayList[7] = {0, 0, 0, 0, 0, 0, 0};
    QString tmp;

    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(arraySize);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Monday") << ("Tuesday") << ("Wednesday") << ("Thursday") <<  ("Friday") <<
                                                                 ("Saturday") << ("Sunday"));
    for(int i = 0; i < arraySize; i++)
    {
        tmp = trainList[i].data + " " + QString::number(trainList[i].number) + " " + trainList[i].destination + " " + trainList[i].time;
        ui->tableWidget->setItem(dayList[(trainList[i].days + trainList[i].months * 30 - 31) % 7], (trainList[i].days + trainList[i].months * 30 - 31) % 7, new QTableWidgetItem(tmp));
        dayList[(trainList[i].days + trainList[i].months * 30 - 31) % 7]++;
    }
}



void MainWindow::on_deleteButton_clicked()
{
    if(arraySize == 0)
    {
        ui->alarmLabel->setText("not left");

        return;
    }

    if(arraySize == 1)
    {
        delete[] trainList;
        arraySize--;

        this->on_viewFileButton_clicked();
        ui->deleteList->removeItem(arraySize);
        ui->destinationList->clear();
        delete[] destinationList;
        destinationListSize = 0;

        return;
    }

    arraySize--;

    ui->deleteList->removeItem(arraySize);

    train *tmp = new train[arraySize];

    for(int i = 0, j = 0; i < arraySize + 1; i++)
    {
        if(i != ui->deleteList->currentIndex() + 1)
        {
            tmp[j] = trainList[i];

            j++;
        }
    }

    delete[] trainList;

    trainList = tmp;
    tmp = nullptr;

    delete[] destinationList;
    destinationListSize = 0;
    ui->destinationList->clear();
    ui->destinationList->addItem("", 0);

    for(int i = 0; i < arraySize; i++)
    {
        append(trainList[i].destination);
    }

    this->on_viewFileButton_clicked();
    this->save();
}


void MainWindow::on_pushButton_clicked()
{
    add->setFile(filename);

    add->show();
}

void MainWindow::up()
{
    this->inut();
    this->on_viewFileButton_clicked();
}

void MainWindow::forcorrect()
{
    trainList[ui->deleteList->currentIndex()] = correct->returnAdd;

    this->save();
}


void MainWindow::on_correctButton_clicked()
{
    if(arraySize == 0)
    {
        ui->alarmLabel->setText("list if empty");

        return;
    }

    correct->setTrain(trainList[ui->deleteList->currentIndex()]);

    correct->show();
}


void MainWindow::on_fileButton_clicked()
{
    filename = ui->fileEdit->text();
}

