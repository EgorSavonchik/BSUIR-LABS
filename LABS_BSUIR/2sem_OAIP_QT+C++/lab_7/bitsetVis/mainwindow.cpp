#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->setNumberButton->hide();
    ui->setNumberEdit->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_allButton_clicked()
{
    ui->allLabel->setText(QString::number(bitsus.all()));
}


void MainWindow::on_sizeButton_clicked()
{
    ui->sizeLabel->setText(QString::number(bitsus.getSize()));
}


void MainWindow::on_toStringButton_clicked()
{
    ui->plainTextEdit->setPlainText((QString)bitsus.to_string().c_str());
}


void MainWindow::on_toUlongButton_clicked()
{
    ui->plainTextEdit->setPlainText(QString::number(bitsus.to_ulong()));
}


void MainWindow::on_toUllongButton_clicked()
{
    ui->plainTextEdit->setPlainText(QString::number(bitsus.to_ullong()));
}


void MainWindow::on_countButton_clicked()
{
    ui->countLabel->setText(QString::number(bitsus.count()));
}


void MainWindow::on_anyButton_clicked()
{
    ui->anyLabel->setText(QString::number(bitsus.any()));
}


void MainWindow::on_flipButton_clicked()
{
    if(ui->flipEdit->text().isEmpty())
    {
        bitsus.flip();
    }
    else
    {
       bitsus.flip(ui->flipEdit->text().toInt());
    }
}


void MainWindow::on_setButton_clicked()
{
    if(ui->setEdit->text().isEmpty())
    {
        bitsus.set();
    }
    else
    {
       bitsus.set(ui->setEdit->text().toInt());
    }
}


void MainWindow::on_resetButton_clicked()
{
    if(ui->resetEdit->text().isEmpty())
    {
        bitsus.reset();
    }
    else
    {
       bitsus.reset(ui->resetEdit->text().toInt());
    }
}


void MainWindow::on_noneButton_clicked()
{
    ui->noneLabel->setText(QString::number(bitsus.none()));
}

