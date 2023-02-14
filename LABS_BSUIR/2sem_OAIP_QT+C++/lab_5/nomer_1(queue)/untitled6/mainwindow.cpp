#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    srand(time(NULL));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    list.push_front(rand() % 1000);

    ui->List->clear();
    for(int i = 0; i < list.size(); i++)
    {
        ui->List->appendPlainText(QString::number(list[i]));
    }
}


void MainWindow::on_popButton_clicked()
{
    if(list.size() == 0)
    {
        QMessageBox::information(this, "helper", "queue not set");

        return;
    }

    list.pop_front();

    ui->List->clear();
    for(int i = 0; i < list.size(); i++)
    {
        ui->List->appendPlainText(QString::number(list[i]));
    }
}


void MainWindow::on_frontButton_clicked()
{
    if(list.size() == 0)
    {
        QMessageBox::information(this, "helper", "queue not set");

        return;
    }

    ui->frontLabel->setText(QString::number(list.front()));
}


void MainWindow::on_backButton_clicked()
{
    if(list.size() == 0)
    {
        QMessageBox::information(this, "helper", "queue not set");

        return;
    }

    ui->backLabel->setText(QString::number(list.back()));
}


void MainWindow::on_sizeButton_clicked()
{
    ui->sizeLabel->setText(QString::number(list.size()));
}


void MainWindow::on_funcButton_clicked()
{
    ui->plainTextList_1->clear();
    ui->plainTextList_2->clear();
    ui->plainTextResult->clear();

    queue<int> first, second, temp;

    for(int i = 0; i < 10; i++)
    {
        first.push_front(rand() % 1000);
        second.push_front(rand() % 1000);
    }

    queue_func op;

    temp = op.func(first, second);

    for(int i = 0; i < first.size(); i++)
    {
        ui->plainTextList_1->appendPlainText(QString::number(first[i]));
        ui->plainTextList_2->appendPlainText(QString::number(second[i]));
    }

    for(int i = 0; i < temp.size(); i++)
    {
        ui->plainTextResult->appendPlainText(QString::number(temp[i]));
    }
}

