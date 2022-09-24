#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    List = new list<sportsman>;
    
    ui->tableWidget->setColumnCount(7);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("country") << ("team") <<
                                                                  ("name") << ("number") <<  ("age") <<
                                                                 ("heigth") << ("weigth"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::view()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    ui->tableWidget->setRowCount(List->size);
    list<sportsman>::iterator it = List->begin();
    ui->deleteBox->clear();

    for(int i = 0; i < List->size; i++, it++)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem((*it).country));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem((*it).team));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem((*it).fullname));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number((*it).number)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number((*it).age)));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number((*it).heigth)));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number((*it).weigth)));

        ui->deleteBox->addItem(QString::number(i + 1), i);
    }
}


void MainWindow::on_openFileButton_clicked()
{
    ui->tableWidget->clear();
    List.reset(new list<sportsman>);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("country") << ("team") <<
                                                                  ("name") << ("number") <<  ("age") <<
                                                                 ("heigth") << ("weigth"));


    path = QFileDialog::getOpenFileName(this, "choose file", "C:\\Users\\HP\\Desktop\\labs\\OAIP_C++_QT\\lab_3(list)\\nomer_1-1_normal_list\\input.txt" , "Text file (*txt)");
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
        list<QString> tmp;
        tempstr.clear();


        for(int i = 0; i < 9; i++)
        {
            in >> tempstr;
            tmp.push_back(tempstr);
        }

        if(!isNormal(tmp))
        {
            QMessageBox::information(this, "Helper", "uncorrect file data");

            List.reset(new list<sportsman>);

            return;
        }

        List->push_back(sportsman(tmp));
    }
    
    in.read(1);

    file.close();

    this->view();
}


void MainWindow::on_surnameInfo_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    if(ui->surnameEdit->text() == "")
    {
        QMessageBox::information(this, "Helper", "empty field");

        return;
    }

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("country") << ("team") <<
                                                                  ("name") << ("number") <<  ("age") <<
                                                                 ("heigth") << ("weigth"));

    list<sportsman>::iterator it = List->begin();

    for(int i = 0, count = 0; i < List->size; i++, it++)
    {
        if(ui->surnameEdit->text() == (*it).surname)
        {
            ui->tableWidget->setRowCount(count + 1);

            ui->tableWidget->setItem(count, 0, new QTableWidgetItem((*it).country));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem((*it).team));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem((*it).fullname));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(QString::number((*it).number)));
            ui->tableWidget->setItem(count, 4, new QTableWidgetItem(QString::number((*it).age)));
            ui->tableWidget->setItem(count, 5, new QTableWidgetItem(QString::number((*it).heigth)));
            ui->tableWidget->setItem(count, 6, new QTableWidgetItem(QString::number((*it).weigth)));

            count++;
        }
    }
}


void MainWindow::on_viewButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    this->view();
}


void MainWindow::on_deleteButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    if(!(ui->deleteEdit->text().toInt() > 0 && ui->deleteEdit->text().toInt() <= List->size))
    {
        QMessageBox::information(this, "Helper", "uncorrect number");

        return;
    }


    List->deleteNode(ui->deleteEdit->text().toInt() - 1);

    this->view();

    ui->deleteEdit->clear();
}


void MainWindow::on_addButton_clicked()
{
    if(List->isNull() && fileOpen == false)
    {
        QMessageBox::information(this, "Helper", "file not open");

        return;
    }

    list<QString> tmp;

    tmp.push_back(ui->countryEdit->text());
    tmp.push_back(ui->teamEdit->text());
    tmp.push_back(ui->nameEdit->text());
    tmp.push_back(ui->surnameAddEdit->text());
    tmp.push_back(ui->patronymicEdit->text());
    tmp.push_back(ui->numberEdit->text());
    tmp.push_back(ui->ageEdit->text());
    tmp.push_back(ui->heigthEdit->text());
    tmp.push_back(ui->weigthEdit->text());

    if(!isNormal(tmp))
    {
        QMessageBox::information(this, "Helper", "uncorrect data");

        ui->countryEdit->clear();
        ui->teamEdit->clear();
        ui->nameEdit->clear();
        ui->surnameAddEdit->clear();
        ui->patronymicEdit->clear();
        ui->numberEdit->clear();
        ui->ageEdit->clear();
        ui->heigthEdit->clear();
        ui->weigthEdit->clear();

        return;
    }

    List->push_back(sportsman(tmp));

    this->view();
}


void MainWindow::on_categotyButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    if(ui->categoryEdit->text().size() == 0 || ui->categoryEdit->text().count('-') != 1)
    {
        QMessageBox::information(this, "Helper", "uncorrect input");

        ui->categoryEdit->clear();

        return;
    }

    for(int i = 0; i < ui->categoryEdit->text().size(); i++)
    {
        if(!(ui->categoryEdit->text()[i].isDigit() || ui->categoryEdit->text()[i] == '-'))
        {
            QMessageBox::information(this, "Helper", "uncorrect input");

            ui->categoryEdit->clear();

            return;
        }
    }


    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("country") << ("team") <<
                                                                  ("name") << ("number") <<  ("age") <<
                                                                 ("heigth") << ("weigth"));

    QString tmp = ui->categoryEdit->text();
    int min, max, pos;

    for(int i = 0; i < ui->categoryEdit->text().size(); i++)
    {
        if(tmp[i] == '-')
        {
            pos = i;
        }
    }

    min = ui->categoryEdit->text().mid(0, pos).toInt();
    max = ui->categoryEdit->text().mid(pos + 1, ui->categoryEdit->text().size() - pos).toInt();

    list<sportsman>::iterator it = List->begin();

    for(int i = 0, count = 0; i < List->size; i++, it++)
    {
        if((*it).weigth >= min && (*it).weigth <= max)
        {
            ui->tableWidget->setRowCount(count + 1);

            ui->tableWidget->setItem(count, 0, new QTableWidgetItem((*it).country));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem((*it).team));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem((*it).fullname));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(QString::number((*it).number)));
            ui->tableWidget->setItem(count, 4, new QTableWidgetItem(QString::number((*it).age)));
            ui->tableWidget->setItem(count, 5, new QTableWidgetItem(QString::number((*it).heigth)));
            ui->tableWidget->setItem(count, 6, new QTableWidgetItem(QString::number((*it).weigth)));

            count++;
        }
    }
}


void MainWindow::on_limitButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    if(!(ui->limitEdit->text().toInt() > 0))
    {
        QMessageBox::information(this, "Helper", "uncorrect number");

        return;
    }

    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("country") << ("team") <<
                                                                  ("name") << ("number") <<  ("age") <<
                                                                 ("heigth") << ("weigth"));


    shared_ptr<list<sportsman>> command_list = new list<sportsman>, ignore_list = new list<sportsman>;
    list<sportsman>::iterator it = List->begin();
    int limit = ui->limitEdit->text().toInt();

    for(int i = 0; i < List->size; i++, it++)
    {
        if(isLocatedTeam((*it).team, ignore_list) != -1)
        {
            continue;
        }

        if(isLocatedTeam((*it).team, command_list) == -1 && (*it).heigth <= limit)
        {
            command_list->push_back(*it);
            continue;
        }

        for(int j = 0; j < command_list->size; j++)
        {
            if(isLocatedTeam((*it).team, command_list) == -1 && (*it).heigth <= limit)
            {
                command_list->push_back(*it);
                break;
            }
            if(isLocatedTeam((*it).team, command_list) != -1 && (*it).heigth > limit)
            {
                for(int k = 0; k < command_list->size; k++)
                {
                    if((*command_list)[k].team == (*it).team)
                    {
                        command_list->deleteNode(k--);
                    }
                }

                ignore_list->push_back(*it);
                break;
            }
            else if(isLocatedTeam((*it).team, command_list) != -1 && (*it).heigth <= limit)
            {
                command_list->push_back(*it);
                break;
            }
        }


    }

    if(command_list->isNull())
    {
        return;
    }

    list<sportsman>::iterator command_it = command_list->begin();

    for(int i = 0; i < command_list->size; i++, command_it++)
    {
        ui->tableWidget->setRowCount(i + 1);

        ui->tableWidget->setItem(i, 0, new QTableWidgetItem((*command_it).country));
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem((*command_it).team));
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem((*command_it).fullname));
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem(QString::number((*command_it).number)));
        ui->tableWidget->setItem(i, 4, new QTableWidgetItem(QString::number((*command_it).age)));
        ui->tableWidget->setItem(i, 5, new QTableWidgetItem(QString::number((*command_it).heigth)));
        ui->tableWidget->setItem(i, 6, new QTableWidgetItem(QString::number((*command_it).weigth)));
    }
}

int MainWindow::isLocatedTeam(QString input, shared_ptr<list<sportsman>> lis)
{
    if(lis->isNull())
    {
        return -1;
    }

    list<sportsman>::iterator it = lis->begin();

    for(int i = 0; i < lis->size; i++, it++)
    {
        if((*it).team == input)
        {
            return i;
        }
    }

    return -1;
}

bool MainWindow::isNormal(list<QString> input)
{
    if(input.size != 9)
    {
        return false;
    }

    for(int i = 0; i < 6; i++)
    {
        if(input[i] == "")
        {
            return false;
        }
    }

    for(int i = 6; i < 9; i++)
    {
        if(!(input[i].toInt() > 0))
        {
            return false;
        }
    }

    return true;
}

void MainWindow::on_youngTeamButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }


    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << ("country") << ("team") <<
                                                                  ("name") << ("number") <<  ("age") <<
                                                                 ("heigth") << ("weigth"));


    shared_ptr<list<sportsman>> tmp = new list<sportsman>;
    list<sportsman>::iterator it = List->begin();
    list<int> age, players;
    list<QString> teams;

    for(int i = 0; i < List->size; i++, it++)
    {
        if(isLocatedTeam((*it).team, tmp) == -1)
        {
            age.push_back((*it).age);
            players.push_back(1);
            teams.push_back((*it).team);
        }
        else
        {
            age[isLocatedTeam((*it).team, tmp)] += (*it).age;
            players[isLocatedTeam((*it).team, tmp)]++;
        }
    }

    list<int>::iterator age_it = age.begin(), players_it = players.begin();

    for(int i = 0; i < age.size; i++, age_it++, players_it++)
    {
        *age_it /= *players_it;
    }

    int pos = 0;


    for(int i = 0; i < age.size - 1; i++)
    {
        if(age[i] > age[i + 1])
        {
            pos = i + 1;
        }
    }

    it = List->begin();

    for(int i = 0, count = 0; i < List->size; i++, it++)
    {
        if((*it).team == teams[pos])
        {
            ui->tableWidget->setRowCount(count + 1);

            ui->tableWidget->setItem(count, 0, new QTableWidgetItem((*it).country));
            ui->tableWidget->setItem(count, 1, new QTableWidgetItem((*it).team));
            ui->tableWidget->setItem(count, 2, new QTableWidgetItem((*it).fullname));
            ui->tableWidget->setItem(count, 3, new QTableWidgetItem(QString::number((*it).number)));
            ui->tableWidget->setItem(count, 4, new QTableWidgetItem(QString::number((*it).age)));
            ui->tableWidget->setItem(count, 5, new QTableWidgetItem(QString::number((*it).heigth)));
            ui->tableWidget->setItem(count, 6, new QTableWidgetItem(QString::number((*it).weigth)));

            count++;
        }
    }
}


void MainWindow::on_correctButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    list<QString> tmp;

    tmp.push_back(ui->countryEditCorrect->text());
    tmp.push_back(ui->teamEditCorrect->text());
    tmp.push_back(ui->nameEditCorrect->text());
    tmp.push_back(ui->surnameEditCorrect->text());
    tmp.push_back(ui->patronymicEditCorrect->text());
    tmp.push_back(ui->numberEditCorrect->text());
    tmp.push_back(ui->ageEditCorrect->text());
    tmp.push_back(ui->heigthEditCorrect->text());
    tmp.push_back(ui->weigthEditCorrect->text());

    if(!isNormal(tmp))
    {
        QMessageBox::information(this, "Helper", "uncorrect data");

        this->on_deleteBox_currentIndexChanged(ui->deleteBox->currentIndex());

        return;
    }

    (*List)[ui->deleteBox->currentIndex()] = tmp;

    this->view();
}


void MainWindow::on_deleteBox_currentIndexChanged(int index)
{
    ui->countryEditCorrect->setText((*List)[index].country);
    ui->teamEditCorrect->setText((*List)[index].team);

    int pos1 = 0, pos2 = 0;

    for(int i = 0; i < (*List)[index].fullname.size(); i++)
    {
        if((*List)[index].fullname[i] == ' ' && pos1 == 0)
        {
            pos1 = i;
        }
        else if((*List)[index].fullname[i] == ' ')
        {
            pos2 = i;
        }
    }

    ui->nameEditCorrect->setText((*List)[index].fullname.mid(0, pos1));
    ui->surnameEditCorrect->setText((*List)[index].fullname.mid(pos1 + 1, pos2 - pos1 - 1));
    ui->patronymicEditCorrect->setText((*List)[index].fullname.mid(pos2 + 1, (*List)[index].fullname.size() - pos2));
    ui->numberEditCorrect->setText(QString::number((*List)[index].number));
    ui->ageEditCorrect->setText(QString::number((*List)[index].age));
    ui->heigthEditCorrect->setText(QString::number((*List)[index].heigth));
    ui->weigthEditCorrect->setText(QString::number((*List)[index].weigth));
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

    list<sportsman>::iterator it = List->begin();

    for(int i = 0; i < List->size; i++, it++)
    {
        if(i == List->size - 1)
        {
            out << (*it).outname;

            break;
        }

        out << (*it).outname << '\n';
    }

    file.close();
}


void MainWindow::on_sortButton_clicked()
{
    if(List->isNull())
    {
        QMessageBox::information(this, "Helper", "the list is not set");

        return;
    }

    this->quickSort(*List, 0 , List->size - 1);

    this->view();
}



int MainWindow::partition (list<sportsman>& arr, int l, int h)
{
    int x = arr[h].number;
    int i = (l - 1);


    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j].number <= x)
        {
            i++;

            swap(arr[i].country, arr[j].country);
            swap(arr[i].team, arr[j].team);
            swap(arr[i].fullname, arr[j].fullname);
            swap(arr[i].outname, arr[j].outname);
            swap(arr[i].fullname, arr[j].fullname);
            swap(arr[i].surname, arr[j].surname);
            swap(arr[i].age, arr[j].age);
            swap(arr[i].number, arr[j].number);
            swap(arr[i].heigth, arr[j].heigth);
            swap(arr[i].weigth, arr[j].weigth);
        }
    }

    swap(arr[i + 1].country, arr[h].country);
    swap(arr[i + 1].team, arr[h].team);
    swap(arr[i + 1].fullname, arr[h].fullname);
    swap(arr[i + 1].outname, arr[h].outname);
    swap(arr[i + 1].fullname, arr[h].fullname);
    swap(arr[i + 1].surname, arr[h].surname);
    swap(arr[i + 1].age, arr[h].age);
    swap(arr[i + 1].number, arr[h].number);
    swap(arr[i + 1].heigth, arr[h].heigth);
    swap(arr[i + 1].weigth, arr[h].weigth);

    return (i + 1);
}

void MainWindow::quickSort(list<sportsman>& A, int l, int h)
{
    if (l < h)
    {
        int p = partition(A, l, h);
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

