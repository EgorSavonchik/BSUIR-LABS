#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("expression") << ("opz") <<("a") << ("b") <<  ("c") << ("d") << ("e") << ("number"));

    double a, b, c, d, e;
    QString expr;
    opz temp;

    QFile file("C:\\Users\\HP\\Desktop\\labs\\OAIP_C++_QT\\lab_3(list)\\nomer_3\\input.txt");
    QTextStream in(&file);


    file.open(QFile::ReadOnly);

    for( ; !in.atEnd(); counter++)
    {
        in >> expr >> a >> b >> c >> d >> e;
        in.read(1);

        temp = opz(expr + '\n', a, b, c ,d , e);

        ui->tableWidget->setRowCount(counter + 1);

        ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(expr));
        ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(temp.OPN()));
        ui->tableWidget->setItem(counter, 2, new QTableWidgetItem(QString::number(a)));
        ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(QString::number(b)));
        ui->tableWidget->setItem(counter, 4, new QTableWidgetItem(QString::number(c)));
        ui->tableWidget->setItem(counter, 5, new QTableWidgetItem(QString::number(d)));
        ui->tableWidget->setItem(counter, 6, new QTableWidgetItem(QString::number(e)));
        ui->tableWidget->setItem(counter, 7, new QTableWidgetItem(QString::number(temp.Calc())));
    }

    file.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_addButton_clicked()
{
    if(ui->exprEdit->text() == "" || (!ui->aEdit->text().toInt() && ui->aEdit->text() != '0') || (!ui->bEdit->text().toInt() && ui->bEdit->text() != '0') || (!ui->cEdit->text().toInt() && ui->cEdit->text() != '0') || (!ui->dEdit->text().toInt() && ui->dEdit->text() != '0') || (!ui->eEdit->text().toInt() && ui->eEdit->text() != '0'))
    {
        QMessageBox::information(this, "helper", "uncorrect data");

        return;
    }

    double a = ui->aEdit->text().toInt(), b = ui->bEdit->text().toInt(), c = ui->cEdit->text().toInt(), d = ui->dEdit->text().toInt(), e = ui->eEdit->text().toInt();
    QString expr = ui->exprEdit->text();
    opz temp = opz(expr + '\n', a, b, c ,d , e);

    ui->tableWidget->setRowCount(counter + 1);

    ui->tableWidget->setItem(counter, 0, new QTableWidgetItem(expr));
    ui->tableWidget->setItem(counter, 1, new QTableWidgetItem(temp.OPN()));
    ui->tableWidget->setItem(counter, 2, new QTableWidgetItem(QString::number(a)));
    ui->tableWidget->setItem(counter, 3, new QTableWidgetItem(QString::number(b)));
    ui->tableWidget->setItem(counter, 4, new QTableWidgetItem(QString::number(c)));
    ui->tableWidget->setItem(counter, 5, new QTableWidgetItem(QString::number(d)));
    ui->tableWidget->setItem(counter, 6, new QTableWidgetItem(QString::number(e)));
    ui->tableWidget->setItem(counter, 7, new QTableWidgetItem(QString::number(temp.Calc())));

    counter++;
}

