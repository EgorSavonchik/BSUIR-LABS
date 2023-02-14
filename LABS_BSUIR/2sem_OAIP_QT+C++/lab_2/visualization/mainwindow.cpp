#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    list = new doublelinks;

    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->pushEdit->setInputMask("99999999");
    ui->pushEdit->setCursorMoveStyle(Qt::CursorMoveStyle());

    ui->deletePos->hide();
    ui->insertPos->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_comboBox_activated(int index)
{
    mode = index;
    ui->countLabel->setText("0");

    if(index == 0)
    {
        ui->tableWidget->setColumnCount(1);
        ui->tableWidget->setRowCount(0);
        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("number in stack"));

        ui->deletePos->hide();
        ui->insertPos->hide();
        ui->headLabel->show();
        ui->label->show();

        ui->popButton->setText("Pop");
    }
    else if(index == 1)
    {
        if(list->doublelink_getlength(list) != 0)
        {
            int* disp = list->doublelink_display(list, list->doublelink_getlength(list));

            for(int i = 0; i < list->doublelink_getlength(list); i++)
            {
                ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(disp[i])));
            }

            delete[] disp;
        }

        ui->countLabel->setText(QString::number(list->doublelink_getlength(list)));



        ui->tableWidget->setColumnCount(1);
        ui->tableWidget->setRowCount(0);

        ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("number in List"));

        ui->popButton->setText("Delete");
        ui->insertPos->addItem("0", 0);

        //ui->deletePos->show();
        //ui->insertPos->show();
        ui->headLabel->hide();
        ui->label->hide();
    }
}

void MainWindow::on_pushButton_clicked()
{

    if(mode == 0)
    {
        st.push(ui->pushEdit->text().toInt());

        ui->tableWidget->setRowCount(st.Count());

        ui->tableWidget->setItem(st.Count() - 1, 0, new QTableWidgetItem(QString::number(st.Head())));

        ui->headLabel->setText(QString::number(st.Head()));
        ui->countLabel->setText(QString::number(st.Count()));
    }
    else if(mode == 1)
    {
        list->doublelink_insert(list, 0, ui->pushEdit->text().toInt());

        int* disp = list->doublelink_display(list, list->doublelink_getlength(list));

        ui->tableWidget->setRowCount(list->doublelink_getlength(list));

        for(int i = 0; i < list->doublelink_getlength(list); i++)
        {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(disp[i])));
        }

        ui->countLabel->setText(QString::number(list->doublelink_getlength(list)));
        ui->headLabel->setText(QString::number(list->getThisDate(list)));

        ui->insertPos->addItem(QString::number(list->doublelink_getlength(list)), list->doublelink_getlength(list));
        ui->deletePos->addItem(QString::number(list->doublelink_getlength(list)), list->doublelink_getlength(list));

        delete[] disp;
    }
}


void MainWindow::on_popButton_clicked()
{
    if(mode == 0)
    {
        st.pop();

        ui->tableWidget->removeRow(st.Count());

        ui->headLabel->setText(QString::number(st.Head()));
        ui->countLabel->setText(QString::number(st.Count()));
    }
    else if(mode == 1)
    {
        list->doublelink_erase(list, 0);

        int* disp = list->doublelink_display(list, list->doublelink_getlength(list));

        ui->tableWidget->setRowCount(list->doublelink_getlength(list));

        for(int i = 0; i < list->doublelink_getlength(list); i++)
        {
            ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(disp[i])));
        }

        ui->countLabel->setText(QString::number(list->doublelink_getlength(list)));

        ui->deletePos->clear();
        ui->insertPos->clear();

        for(int i = 0; i < list->doublelink_getlength(list); i++)
        {
            ui->insertPos->addItem(QString::number(i), i);
        }

        for(int i = 0; i < list->doublelink_getlength(list); i++)
        {
            ui->deletePos->addItem(QString::number(i), i);
        }

        delete[] disp;
    }
}


void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

