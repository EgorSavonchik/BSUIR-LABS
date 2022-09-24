#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);

    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("name") << ("brand") << ("data") << ("readiness"));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_openFileButton_clicked()
{
    ui->tableWidget->clear();
    List.reset(new list_array<product>);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("name") << ("brand") << ("data") << ("readiness"));


    path = QFileDialog::getOpenFileName(this, "choose file", "C:\\Users\\HP\\Desktop\\labs\\OAIP_C++_QT\\lab_3(list)\\nomer_1_2_onArray\\input.txt" , "Text file (*txt)");
    fileOpen = false;

    QFile file(path);
    QTextStream in(&file);
    QFileInfo info(file);
    file.open(QFile::ReadOnly);

    if(info.size() == 0)
    {
        ui->tableWidget->setRowCount(0);

        fileOpen = true;

        return;
    }

    QString tempstr;

    for(; !in.atEnd(); )
    {
        list_array<QString> tmp;
        tempstr.clear();


        for(int i = 0; i < 4; i++)
        {
            in >> tempstr;
            tmp.add(tempstr);
        }

        if(!isNormal(tmp))
        {
            QMessageBox::information(this, "Helper", "uncorrect file data");

            List.reset(new list_array<product>);

            return;
        }

        List->add(product(tmp));
    }

    this->view();
}




void MainWindow::on_viewButton_clicked()
{
    this->view();
}

void MainWindow::view()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    ui->tableWidget->setRowCount(List->count);

    ui->deleteBox->clear();

    for(int i = 0; i < List->count; i++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem((*List)[i].productname));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem((*List)[i].brand));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem((*List)[i].data));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem((*List)[i].readiness));

        ui->deleteBox->addItem(QString::number(i + 1), i);
    }
}

bool MainWindow::isNormal(list_array<QString> input)
{
    if(input.count != 4)
    {
        return false;
    }

    if(input[2].mid(0, 2).toInt() <= 0 || input[2].mid(0, 2).toInt() > 32 || input[2].count('.') != 2 || input[2][2] != '.' || input[2][5] != '.'
            || (input[2].mid(3, 2).toInt() <= 0) || (input[2].mid(3, 2).toInt() > 13) || input[2].mid(6, 4).toInt() <= 0 || input[2].size() != 10)
    {
        return false;
    }

    if(!(input[3] == "complete" || input[3] == "uncomplete"))
    {
        return false;
    }

    return true;
}


void MainWindow::on_addButton_clicked()
{
    if(List->isNull() && fileOpen == false)
    {
        QMessageBox::information(this, "Helper", "file not open");

        return;
    }

    list_array<QString> tmp;

    tmp.add(ui->nameAddEdit->text());
    tmp.add(ui->brandAddEdit->text());
    tmp.add(ui->dataAddEdit->text());
    tmp.add(ui->readinessAddEdit->text());

    if(!isNormal(tmp))
    {
        QMessageBox::information(this, "Helper", "uncorrect data");

        ui->nameAddEdit->clear();
        ui->brandAddEdit->clear();
        ui->dataAddEdit->clear();
        ui->readinessAddEdit->clear();

        return;
    }

    List->add(product(tmp));

    ui->nameAddEdit->clear();
    ui->brandAddEdit->clear();
    ui->dataAddEdit->clear();
    ui->readinessAddEdit->clear();

    this->view();
}



void MainWindow::on_correctButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    list_array<QString> tmp;

    tmp.add(ui->nameCorrectEdit->text());
    tmp.add(ui->brandCorrectEdit->text());
    tmp.add(ui->dataCorrectEdit->text());
    tmp.add(ui->readnessCorrectEdit->text());

    if(!isNormal(tmp))
    {
        QMessageBox::information(this, "Helper", "uncorrect data");

        this->on_deleteBox_currentIndexChanged(ui->deleteBox->currentIndex());

        return;
    }

    (*List)[ui->deleteBox->currentIndex()] = product(tmp);

    this->view();
}


void MainWindow::on_deleteBox_currentIndexChanged(int index)
{
    ui->nameCorrectEdit->setText((*List)[index].productname);
    ui->brandCorrectEdit->setText((*List)[index].brand);
    ui->dataCorrectEdit->setText((*List)[index].data);
    ui->readnessCorrectEdit->setText((*List)[index].readiness);
}


void MainWindow::on_informationButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    if(!(ui->informationEdit->text().toInt() > 0 && ui->informationEdit->text().toInt() <= List->count))
    {
        QMessageBox::information(this, "Helper", "uncorrect number");

        ui->informationEdit->clear();

        return;
    }

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("name") << ("brand") << ("data") << ("readiness"));

    ui->tableWidget->setItem(0, 0, new QTableWidgetItem((*List)[ui->informationEdit->text().toInt() - 1].productname));
    ui->tableWidget->setItem(0, 1, new QTableWidgetItem((*List)[ui->informationEdit->text().toInt() - 1].brand));
    ui->tableWidget->setItem(0, 2, new QTableWidgetItem((*List)[ui->informationEdit->text().toInt() - 1].data));
    ui->tableWidget->setItem(0, 3, new QTableWidgetItem((*List)[ui->informationEdit->text().toInt() - 1].readiness));

    ui->informationEdit->clear();
}


void MainWindow::on_orderButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    if(!(ui->orderEdit->text().toInt() > 0 && ui->orderEdit->text().toInt() <= List->count))
    {
        QMessageBox::information(this, "Helper", "there is no such number");

        ui->orderEdit->clear();

        return;
    }

    if((*List)[ui->orderEdit->text().toInt() - 1].readiness == "uncomplete")
    {
        (*List)[ui->orderEdit->text().toInt() - 1].readiness = "complete";

        ui->orderEdit->clear();

        this->view();
    }
    else
    {
        QMessageBox::information(this, "Helper", "the order was already fulfilled");
    }
}


void MainWindow::on_saveButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    QFile file(path);
    QTextStream out(&file);

    file.open(QFile::WriteOnly);

    for(int i = 0; i < List->count; i++)
    {
        if(i == List->count - 1)
        {
            out << (*List)[i].fullname;

            break;
        }

        out << (*List)[i].fullname << '\n';
    }

    file.close();
}

void MainWindow::on_orderIndayButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    bool isContains = false;

    for(int i = 0; i < List->count; i++)
    {
        if((*List)[i].productname == ui->nameEnterEdit->text())
        {
            isContains = true;

            break;
        }
    }

    if(!isContains)
    {
        QMessageBox::information(this, "Helper", "order no contains in list");

        return;
    }

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("name") << ("brand") << ("data") << ("readiness"));

    QString date = QDateTime::currentDateTime().toString("dd.MM.yyyy");
    ui->label->setText(date);

    for(int i = 0, count = 0; i < List->count; i++)
    {
        if((*List)[i].data == date && (*List)[i].productname == ui->nameEnterEdit->text())
        {
            ui->tableWidget->setRowCount(count + 1);

            ui->tableWidget->setItem(count, 0, new QTableWidgetItem((*List)[i].productname));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem((*List)[i].brand));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem((*List)[i].data));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem((*List)[i].readiness));

            count++;
        }
    }

    ui->nameEnterEdit->clear();
}


void MainWindow::on_deleteButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    if(!(ui->deleteEdit->text().toInt() > 0 && ui->deleteEdit->text().toInt() <= List->count))
    {
        QMessageBox::information(this, "Helper", "there is no such number");

        ui->orderEdit->clear();

        return;
    }

    List->del(ui->deleteEdit->text().toInt() - 1);
    ui->deleteEdit->clear();

    if(List->count == 0)
    {
        ui->tableWidget->setRowCount(0);

        fileOpen = true;
    }
    else
    {
        this->view();
    }
}


void MainWindow::on_sortButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    this->quickSort(*List, 0, List->count - 1);

    this->view();
}


int MainWindow::partition (list_array<product>& arr, int l, int h)
{
    QString x = arr[h].productname;
    int i = (l - 1);


    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j].productname <= x)
        {
            i++;

            swap(arr[i].productname, arr[j].productname);
            swap(arr[i].brand, arr[j].brand);
            swap(arr[i].data, arr[j].data);
            swap(arr[i].readiness, arr[j].readiness);
            swap(arr[i].fullname, arr[j].fullname);
        }
    }

    swap(arr[i + 1].productname, arr[h].productname);
    swap(arr[i + 1].brand, arr[h].brand);
    swap(arr[i + 1].data, arr[h].data);
    swap(arr[i + 1].readiness, arr[h].readiness);
    swap(arr[i + 1].fullname, arr[h].fullname);

    return (i + 1);
}

void MainWindow::quickSort(list_array<product>& A, int l, int h)
{
    if (l < h)
    {
        int p = partition(A, l, h); /* Partitioning index */
        quickSort(A, l, p - 1);
        quickSort(A, p + 1, h);
    }
}

template<class T>
void MainWindow::swap(T& first, T& second)
{
    T tmp = first;
    first =  second;
    second = tmp;
}
