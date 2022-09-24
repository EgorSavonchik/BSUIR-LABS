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


void MainWindow::on_pushBackButton_clicked()
{
    ui->plainTextEdit->clear();

    list.push_back(rand() % 1000);

    for(int i = 0; i < list.size(); i++)
    {
        ui->plainTextEdit->appendPlainText(QString::number(list[i]));
    }
}


void MainWindow::on_pushFrontButton_clicked()
{
    ui->plainTextEdit->clear();

    list.push_front(rand() % 1000);

    for(int i = 0; i < list.size(); i++)
    {
        ui->plainTextEdit->appendPlainText(QString::number(list[i]));
    }
}


void MainWindow::on_popBackButton_clicked()
{
    if(list.size() == 0)
    {
        QMessageBox::information(this, "helper", "list not set");

        return;
    }

    ui->plainTextEdit->clear();

    list.pop_back();

    for(int i = 0; i < list.size(); i++)
    {
        ui->plainTextEdit->appendPlainText(QString::number(list[i]));
    }
}


void MainWindow::on_popFrontButton_clicked()
{
    if(list.size() == 0)
    {
        QMessageBox::information(this, "helper", "list not set");

        return;
    }

    ui->plainTextEdit->clear();

    list.pop_front();

    for(int i = 0; i < list.size(); i++)
    {
        ui->plainTextEdit->appendPlainText(QString::number(list[i]));
    }
}


void MainWindow::on_sizeButton_clicked()
{
    ui->sizeLabel->setText(QString::number(list.size()));
}


void MainWindow::on_emptyButton_clicked()
{
    if(list.isEmpty())
    {
        ui->emptyLabel->setText("true");
    }
    else
    {
        ui->emptyLabel->setText("false");
    }
}


void MainWindow::on_clearButton_clicked()
{
    list.clear();

    ui->plainTextEdit->clear();
}


void MainWindow::on_incButton_clicked()
{
    if(list.size() == 0)
    {
        QMessageBox::information(this, "helper", "list not set");

        return;
    }

    it++;

    ui->itLabel->setText(QString::number(*it));
}


void MainWindow::on_decrButton_clicked()
{
    if(list.size() == 0)
    {
        QMessageBox::information(this, "helper", "list not set");

        return;
    }

    it--;

    ui->itLabel->setText(QString::number(*it));
}

