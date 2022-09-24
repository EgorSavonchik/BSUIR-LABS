#include "dialogadd.h"
#include "ui_dialogadd.h"

DialogAdd::DialogAdd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogAdd)
{
    ui->setupUi(this);
}

DialogAdd::~DialogAdd()
{
    delete ui;
}

bool DialogAdd::normalToInt(QString str)
{
    if(str == "")
    {
        return false;
    }

    for(int i = 0;  i < str.length(); i++)
    {
        if(str[i].isDigit() == 0 && str[i] != '0')
        {
            return false;
        }
    }

    return true;
}

void DialogAdd::setFile(QString file)
{
    filename = file;
}

void DialogAdd::on_pushButton_clicked()
{
    ui->dataAlarm->clear();
    ui->numberAlarm->clear();
    ui->destinationAlarm->clear();
    ui->timeAlarm->clear();
    ui->compartAlarm->clear();
    ui->reservedAlarm->clear();
    ui->freecompartAlarm->clear();
    ui->freereservedAlarm->clear();

    normaltrain = true;

    if(ui->dataEdit->text().length() == 10 && ui->dataEdit->text().count('.') == 2)
    {
        if(ui->dataEdit->text().mid(0, 2).toInt() && ui->dataEdit->text().mid(3, 2).toInt() && ui->dataEdit->text().mid(6, 4).toInt())
        {
            returnAdd.data = ui->dataEdit->text();
        }
    }
    else
    {
        ui->dataAlarm->setText("uncorrect");

        normaltrain = false;
    }

    if(ui->numberEdit->text().toInt() && ui->numberEdit->text().toInt() > 0)
    {
        returnAdd.number = ui->numberEdit->text().toInt();
    }
    else
    {
        ui->numberAlarm->setText("uncorrect");

        normaltrain = false;

    }

    if(ui->timeEdit->text().length() == 5 && normalToInt(ui->timeEdit->text().mid(0, 2)) && ui->timeEdit->text().mid(0, 2).toInt() < 24 &&
            normalToInt(ui->timeEdit->text().mid(3, 2)) && ui->timeEdit->text().mid(3, 2).toInt() < 60)
    {
        if(ui->timeEdit->text()[2] == '.')
        {
            returnAdd.time = ui->timeEdit->text();
        }
    }
    else
    {
        ui->timeAlarm->setText("uncorrect");

        normaltrain = false;

    }

    if(ui->destinationEdit->text() != "")
    {
        returnAdd.destination = ui->destinationEdit->text();
    }
    else
    {
        ui->destinationAlarm->setText("uncorrect");

        normaltrain = false;
    }

    if(normalToInt(ui->compartEdit->text()))
    {
        returnAdd.compart = ui->compartEdit->text().toInt();
    }
    else
    {
        ui->compartAlarm->setText("uncorrect");

        normaltrain = false;

    }

    if(normalToInt(ui->reservedEdit->text()))
    {
        returnAdd.reserved = ui->reservedEdit->text().toInt();
    }
    else
    {
        ui->reservedAlarm->setText("uncorrect");

        normaltrain = false;
    }

    if(normalToInt(ui->freecompartEdit->text()))
    {
        returnAdd.compartFree = ui->freecompartEdit->text().toInt();
    }
    else
    {
        ui->freecompartAlarm->setText("uncorrect");

        normaltrain = false;
    }

    if(normalToInt(ui->freereservedEdit->text()))
    {
        returnAdd.reservedFree = ui->freereservedEdit->text().toInt();
    }
    else
    {
        ui->freereservedAlarm->setText("uncorrect");

        normaltrain = false;
    }

    returnAdd.fullname = returnAdd.data + ',' + QString::number(returnAdd.number) + ',' + returnAdd.destination + ',' + returnAdd.time + ',' +
            QString::number(returnAdd.compart) + ',' + QString::number(returnAdd.reserved) + ',' + QString::number(returnAdd.compartFree) + ',' +
                                                                       QString::number(returnAdd.reservedFree) + '.';

    if(normaltrain)
    {
        QFile file(filename);
        QTextStream out(&file);

        file.open(QIODevice::Append);

        out << returnAdd.fullname << '\n';

        file.close();

        this->close();

        emit addclose();
    }

    ui->dataEdit->clear();
    ui->numberEdit->clear();
    ui->destinationEdit->clear();
    ui->timeEdit->clear();
    ui->compartEdit->clear();
    ui->reservedEdit->clear();
    ui->freecompartEdit->clear();
    ui->freereservedEdit->clear();
}

