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

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->setColumnCount(1);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("key") << ("value"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::view()
{
    set<int, int>::iterator it = mapa.begin();

    ui->tableWidget->clear();
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("key"));
    ui->tableWidget->setRowCount(mapa.size());

    for(int i = 0; it != mapa.end(); ++it, i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(*it)));
    }
}


void MainWindow::on_insertButton_clicked()
{
    if(ui->keyEdit->text().isEmpty())
    {
        QMessageBox::information(this, "sosi", "edit empty");

        return;
    }

    mapa.insert(ui->keyEdit->text().toInt());

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

    set<int, int>::iterator it = mapa.search(ui->searchKeyEdit->text().toInt());

    if(it == mapa.end())
    {
        ui->searchResultButton->setText("not found");

        return;
    }

    ui->searchResultButton->setText(QString::number(*it));
}

