#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->deleteEdit->setInputMask("00000");
    ui->keyEdit->setInputMask("00000");
    ui->searchKeyEdit->setInputMask("00000");
    ui->valueEdit->setInputMask("00000");

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("key") << ("value"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::view()
{
    map<int, int>::iterator it = mapa.begin();

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("key") << ("value"));
    ui->tableWidget->setRowCount(mapa.size());

    for(int i = 0; it != mapa.end(); ++it, i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(it->first)));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(QString::number(it->second)));
    }
}


void MainWindow::on_insertButton_clicked()
{
    if(ui->valueEdit->text().isEmpty() || ui->keyEdit->text().isEmpty())
    {
        QMessageBox::information(this, "sosi", "edit empty");

        return;
    }

    mapa.insert(std::make_pair(ui->keyEdit->text().toInt(), ui->valueEdit->text().toInt()));

    ui->tableWidget->setRowCount(mapa.size());

    this->view();
}


void MainWindow::on_eraseButton_clicked()
{
    if(ui->deleteEdit->text().isEmpty())
    {
        QMessageBox::information(this, "sosi", "edit empty");

        return;
    }

    mapa.erase(ui->deleteEdit->text().toInt());

    this->view();
}


void MainWindow::on_sizeButton_clicked()
{
    ui->sizeLabel->setText(QString::number(mapa.size()));
}


void MainWindow::on_searchButton_clicked()
{
    if(ui->searchKeyEdit->text().isEmpty())
    {
        QMessageBox::information(this, "sosi", "edit empty");

        return;
    }

    map<int, int>::iterator it = mapa.search(ui->searchKeyEdit->text().toInt());

    if(it == mapa.end())
    {
        ui->searchResultButton->setText("not found");

        return;
    }

    ui->searchResultButton->setText(QString::number(it->second));
}

