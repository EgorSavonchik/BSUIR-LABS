#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnWidth(1, 100);
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);

    ui->openFile->setText(filename);

    this->inintialyze();
}

MainWindow::~MainWindow()
{
    delete ui;

    if(!dataArray)
    {
        delete[] dataArray;
    }
}

void MainWindow::inintialyze()
{
    ui->correctData->clear();



    QFile file(ui->openFile->text());
    QTextStream in(&file);
    QFileInfo fileinfo(ui->openFile->text());
    arraySize = fileinfo.size() / 10 - fileinfo.size() / 120;

    dataArray = new Date[arraySize];// каждые 11 дат буедт скапливаться 10 пробелов, чтобы не выделялось лишнее
    if(!file.exists())
    {
        if(!dataArray)
        {
            delete[] dataArray;

            dataArray = nullptr;
        }

        arraySize = 0;

        ui->tableWidget->clear();
        ui->comboBox->clear();

        ui->alarmLabel->setText("file not exists");

        return;
    }

    file.open(QIODevice::ReadOnly);

    for(int i = 0; !in.atEnd(); i++)
    {
        dataArray[i] = in.read(10);

        if(!isData(dataArray[i].data))
        {
            delete[] dataArray;
            dataArray = nullptr;

            arraySize = 0;

            ui->alarmLabel->setText("uncorrect file");
            ui->tableWidget->clear();

            return;
        }

        if(!in.atEnd())
        {
            in.read(1);
        }
    }

    file.close();

    if(ui->tableWidget->rowCount() != 0)
    {
        ui->tableWidget->clear();
        ui->comboBox->clear();
    }

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("Data") << ("Next day") << ("Duration") << ("previous day") << ("number Week") << ("Is Leap") << ("Days till bithday"));


    ui->tableWidget->setRowCount(arraySize);

    for(int i = 0; i < arraySize; i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(dataArray[i].data));

        ui->comboBox->addItem(QString::number(i + 1), i);
    }
}

Date* MainWindow::pushBack(Date data)
{
    arraySize++;

    Date *newArray = new Date[arraySize];

    for(int i = 0; i < arraySize - 1; i++)
    {
        newArray[i] = dataArray[i];
    }

    newArray[arraySize - 1] = data;

    delete[] dataArray;    

    return newArray;
}

bool MainWindow::isData(QString str)
{
    if(str.length() != 10)
    {
        return false;
    }
    else
    {
        Date tmp = str;

        if(tmp.isLeap())
        {
            tmp.daysinmonths[1]++;
        }

        if(tmp.months > 12 || tmp.months <= 0)
        {
            return false;
        }

        if(tmp.days <= 0 || tmp.days > tmp.daysinmonths[tmp.months - 1])
        {
            return false;
        }

        if(tmp.years == 0)
        {
            return false;
        }

        return true;
    }

}


void MainWindow::on_inintialization_clicked()
{
    ui->alarmLabel->clear();

    this->inintialyze();
}


void MainWindow::on_pushButton_2_clicked()
{
    if(arraySize == 0)
    {
        ui->alarmLabel->setText("file not open");

        return;
    }

    ui->alarmLabel->clear();

    ui->tableWidget->setItem(ui->comboBox->currentIndex(), 3, new QTableWidgetItem(dataArray[ui->comboBox->currentIndex()].PreviousDay().data));
}


void MainWindow::on_numberOfweek_clicked()
{
    if(arraySize == 0)
    {
        ui->alarmLabel->setText("file not open");

        return;
    }

    ui->alarmLabel->clear();

    ui->tableWidget->setItem(ui->comboBox->currentIndex(), 4, new QTableWidgetItem(QString::number(dataArray[ui->comboBox->currentIndex()].WeekNumber())));
}


void MainWindow::on_pushButton_3_clicked()
{
    if(arraySize == 0)
    {
        ui->alarmLabel->setText("file not open");

        return;
    }

    ui->alarmLabel->clear();

    if(dataArray[ui->comboBox->currentIndex()].isLeap())
    {
        ui->tableWidget->setItem(ui->comboBox->currentIndex(), 5, new QTableWidgetItem("Yes"));
    }
    else
    {
        ui->tableWidget->setItem(ui->comboBox->currentIndex(), 5, new QTableWidgetItem("No"));
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if(arraySize == 0)
    {
        ui->alarmLabel->setText("file not open");

        return;
    }

    ui->alarmLabel->clear();

    if(isData(ui->lineEdit->text()) && arraySize != 0)
    {
        ui->tableWidget->setItem(ui->comboBox->currentIndex(), 6, new QTableWidgetItem(QString::number(dataArray[ui->comboBox->currentIndex()].Duration(ui->lineEdit->text()))));
    }
    else
    {
        ui->lineEdit->clear();

        ui->alarmLabel->setText("uncorrect data");
    }
}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->alarmLabel->clear();

    if(index != -1)
    {
        ui->correctData->setText(dataArray[index].data);
    }
}


void MainWindow::on_correct_clicked()
{
    if(arraySize == 0)
    {
        ui->alarmLabel->setText("file not open");

        return;
    }

    ui->alarmLabel->clear();


    if(isData(ui->correctData->text()) && arraySize != 0)
    {
        dataArray[ui->comboBox->currentIndex()] = ui->correctData->text();

        for (int i = 0; i < 7; ++i)
            ui->tableWidget->setItem(ui->comboBox->currentIndex(), i, new QTableWidgetItem);

        ui->tableWidget->setItem(ui->comboBox->currentIndex(), 0, new QTableWidgetItem(dataArray[ui->comboBox->currentIndex()].data));

        QFile file(ui->openFile->text());
        QTextStream out(&file);

        file.open(QIODevice::ReadWrite);

        file.seek(ui->comboBox->currentIndex() * 11);

        out << dataArray[ui->comboBox->currentIndex()].data << " ";

        file.close();
    }
    else
    {
        if(arraySize != 0)
        {
            ui->correctData->setText(dataArray[ui->comboBox->currentIndex()].data);
        }

        ui->alarmLabel->setText("uncorrect data");
    }

}


void MainWindow::on_Nextday_clicked()
{
    if(arraySize == 0)
    {
        ui->alarmLabel->setText("file not open");

        return;
    }

    ui->alarmLabel->clear();

    ui->tableWidget->setItem(ui->comboBox->currentIndex(), 1, new QTableWidgetItem(dataArray[ui->comboBox->currentIndex()].NextDay().data));
}


void MainWindow::on_Duration_clicked()
{
    if(arraySize == 0)
    {
        ui->alarmLabel->setText("file not open");

        return;
    }

    ui->alarmLabel->clear();

    if(ui->comboBox->currentIndex() == arraySize - 1)
    {
         ui->tableWidget->setItem(ui->comboBox->currentIndex(), 2, new QTableWidgetItem("-"));
    }
    else
    {
       ui->tableWidget->setItem(ui->comboBox->currentIndex(), 2,
                                new QTableWidgetItem(QString::number(dataArray[ui->comboBox->currentIndex()].Duration(dataArray[ui->comboBox->currentIndex() + 1]))));
    }
}


void MainWindow::on_add_clicked()
{
    if(arraySize == 0)
    {
        ui->alarmLabel->setText("file not open");

        return;
    }

    ui->alarmLabel->clear();

    if(isData(ui->addData->text()))
    {
        dataArray = pushBack(Date(ui->addData->text()));

        ui->addData->clear();

        ui->tableWidget->setRowCount(arraySize);

        ui->tableWidget->setItem(arraySize - 1, 0, new QTableWidgetItem(dataArray[arraySize - 1].data));
        ui->comboBox->addItem(QString::number(arraySize - 1 + 1), arraySize - 1);

        QFile file(ui->openFile->text());
        QTextStream out(&file);

        file.open(QIODevice::Append);


        out << " " << dataArray[arraySize - 1].data;

        file.close();
    }
    else
    {
         ui->addData->clear();

         ui->alarmLabel->setText("uncorrect data");
    }


}


void MainWindow::on_openFile_2_clicked()
{
    ui->alarmLabel->clear();

    this->inintialyze();
}



