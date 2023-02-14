#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->addKeyEdit->setInputMask("00000");
    ui->addValueEdit->setInputMask("00000");
    ui->deleteEdit->setInputMask("00000");
    ui->searchEdit->setInputMask("00000");

    ui->mainTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->mainTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->mainTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->minusTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->minusTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->minusTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->plusTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->plusTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->plusTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->randomTable->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->randomTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->randomTable->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->mainTable->setColumnCount(2);
    ui->minusTable->setColumnCount(2);
    ui->plusTable->setColumnCount(2);
    ui->randomTable->setColumnCount(2);

    ui->mainTable->setHorizontalHeaderLabels(QStringList() << ("key") << ("value"));
    ui->minusTable->setHorizontalHeaderLabels(QStringList() << ("key") << ("value"));
    ui->plusTable->setHorizontalHeaderLabels(QStringList() << ("key") << ("value"));
    ui->randomTable->setHorizontalHeaderLabels(QStringList() << ("key") << ("value"));

    ui->mainTable->setRowCount(50);
    ui->minusTable->setRowCount(50);
    ui->plusTable->setRowCount(50);
    ui->randomTable->setRowCount(50);

    hash.print(ui->mainTable);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addButton_clicked()
{
    if(ui->addKeyEdit->text().isEmpty() || ui->addValueEdit->text().isEmpty())
    {
        QMessageBox::information(this, "sosi", "edit empty");

        return;
    }

    hash.add(ui->addKeyEdit->text().toInt(), ui->addValueEdit->text().toInt());

    hash.print(ui->mainTable);
}


void MainWindow::on_deleteButton_clicked()
{
    if(ui->deleteEdit->text().isEmpty())
    {
        QMessageBox::information(this, "sosi", "edit empty");

        return;
    }

    hash.delet(ui->deleteEdit->text().toInt());

    hash.print(ui->mainTable);
}


void MainWindow::on_searchButton_clicked()
{
    if(ui->searchEdit->text().isEmpty())
    {
        QMessageBox::information(this, "sosi", "edit empty");

        return;
    }

    hash.search(ui->searchEdit->text().toInt(), ui->searchResultLabel);
}


void MainWindow::on_plusMinusButton_clicked()
{
    hash_func temp;

    temp.plusMinus(ui->randomTable, ui->plusTable, ui->minusTable);
}

