#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->outPlainText->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

std::string MainWindow::strToStd(string input)
{
    std::string temp;

    for(int i = 0; i < input.size(); i++)
    {
        temp += input[i];
    }

    return temp;
}

string MainWindow::StdTostr(std::string input)
{
    string temp = input.c_str();

    return temp;
}

string MainWindow::QStrTostr(QString input)
{
    string temp;

    for(int i = 0; i < input.size(); i++)
    {
        temp += input[i].unicode();
    }

    return temp;
}

QString MainWindow::strToQStr(string input)
{
    QString temp;

    for(int i = 0; i < input.size(); i++)
    {
        temp += input[i];
    }

    return temp;
}

void MainWindow::on_varNameButton_clicked()
{
    list<string> varInfo, name;
    list<int> count;

    std::regex reg("((size_t|int|double|float|char)\\s*[\\*]*)\\s*(((\\,\\s)?([\\w]+)\\s*((=\\s*[\\w+]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?)){0,});");

    std::smatch res;

    std::string str = ui->plainTextEdit->toPlainText().toStdString();

    while(std::regex_search(str, res, reg))
    {
        varInfo.push_back(StdTostr(res.str()));

        int exist = -1;

        for(int i = 0; i < name.size; i++)
        {
            if(name[i] == StdTostr(res[1].str()))
            {
                exist = i;
                qDebug() << strToQStr(name[i]);
                break;
            }
        }

        if(exist == -1)
        {
            count.push_back(strToQStr(StdTostr(res[3].str())).count(',') + 1);
            name.push_back(StdTostr(res[1].str()));
        }
        else
        {
            count[exist] += strToQStr(StdTostr(res[3].str())).count(',') + 1;
        }

        str = res.suffix();
    }

    ui->outPlainText->clear();

    for(int i = 0; i < varInfo.size; i++)
    {
        ui->outPlainText->appendPlainText(strToQStr(varInfo[i]));
    }

    ui->outPlainText->appendPlainText("amount");

    for(int i = 0; i < name.size; i++)
    {
        ui->outPlainText->appendPlainText(strToQStr(name[i]) + " " + QString::number(count[i]));
    }
}


void MainWindow::on_checkFileButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "choose file", "C:\\Users\\HP\\Desktop\\labs\\OAIP_C++_QT\\lab_4\\nomer_2(string+parser)\\parser\\123\\input.txt");

    QFile file(path);
    QTextStream in(&file);

    file.open(QFile::ReadOnly);

    ui->plainTextEdit->setPlainText(in.readAll());

    file.close();
}



void MainWindow::on_classButton_clicked()
{
    ui->outPlainText->clear();

    list<string> className, classType, arrayName;
    list<int> classCounter, arrayCount;

    std::regex reg("(class|struct)\\s*(\\w+)\\s*\\{");

    std::smatch res;

    std::string str = ui->plainTextEdit->toPlainText().toStdString();

    while(std::regex_search(str, res, reg))
    {
        int exist = -1;

        for(int i = 0; i < className.size; i++)
        {
            if(className[i] == StdTostr(res[1].str()))
            {
                exist = i;
                qDebug() << strToQStr(className[i]);
                break;
            }
        }

        if(exist == -1)
        {
            className.push_back(StdTostr(res[2].str()));
            classType.push_back(StdTostr(res[1].str()));
            classCounter.push_back(0);
            arrayCount.push_back(0);
            arrayName.push_back(StdTostr(res[2].str()));
        }

        str = res.suffix();
    }

    for(int i = 0; i < className.size; i++)
    {
        str = ui->plainTextEdit->toPlainText().toStdString();
        reg = ("\\s+(" + strToStd(className[i]) + "\\s*[\\*]*)\\s*(((\\,\\s)?([\\w]+)\\s*((=\\s*[\\w+]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?(\\([\\w ,]+\\))?)){0,});");

        while(std::regex_search(str, res, reg))
        {
            classCounter[i] += strToQStr(StdTostr(res[2].str())).count(',') + 1;//считает плохо если одно название класса входит в другое

            str = res.suffix();
        }
    }

    arrayName.push_back("int");
    arrayCount.push_back(0);
    arrayName.push_back("char");
    arrayCount.push_back(0);
    arrayName.push_back("double");
    arrayCount.push_back(0);
    arrayName.push_back("float");
    arrayCount.push_back(0);
    arrayName.push_back("size_t");
    arrayCount.push_back(0);


    for(int i = 0; i < arrayName.size; i++)
    {
        str = ui->plainTextEdit->toPlainText().toStdString();
        reg = ("(" + strToStd(arrayName[i]) + "\\s*[\\*]*)\\s*(((\\,\\s)?([\\w]+)(\\[[\\w ,]+\\])\\s*((=\\s*[\\w+]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?)){0,});");

        while(std::regex_search(str, res, reg))
        {
            arrayCount[i] += strToQStr(StdTostr(res.str())).count('[');

            str = res.suffix();
        }
    }

    for(int i = 0; i < className.size; i++)
    {
        if(classCounter[i])
        {
            ui->outPlainText->appendPlainText(strToQStr(classType[i] + " " + className[i] + " ") + QString::number(classCounter[i]));
        }
    }

    for(int i = 0; i < arrayName.size; i++)
    {
        if(className.size > i)
        {
            if(arrayCount[i])
            {
                ui->outPlainText->appendPlainText(strToQStr(classType[i] + " " + arrayName[i] + "[]" + " ") + QString::number(arrayCount[i]));
            }
        }
        else
        {
            if(arrayCount[i])
            {
                ui->outPlainText->appendPlainText(strToQStr(arrayName[i] + "[]" + " ") + QString::number(arrayCount[i]));
            }
        }
    }
}


void MainWindow::on_closeButton_clicked()
{
    this->close();
}


void MainWindow::on_funcButton_clicked()
{
    list<string> funcName;

    std::regex reg("((\\w+)\\s+[\\*]*(\\w*::)?\\s*((([\\w]+)\\((\\s*[\\w]*\\s*[\\*]*\\s*\\w+\\s*\\,?\\s*){0,}\\))))\\s*\\{");

    std::smatch res;

    std::string str = ui->plainTextEdit->toPlainText().toStdString();

    while(std::regex_search(str, res, reg))
    {
        funcName.push_back(StdTostr(res[1].str()));

        str = res.suffix();
    }

    ui->outPlainText->clear();

    for(int i = 0; i < funcName.size; i++)
    {
        ui->outPlainText->appendPlainText(strToQStr(funcName[i]) + ";");
    }
}


void MainWindow::on_changeButton_clicked()
{
    ui->outPlainText->clear();

    std::regex reg("[\\};]\\s*(([\\*]*\\s*)?\\w+(\\[\\w+\\])?\\s*?(([+|-|^|*|\\/|&|\\|]?=)|\\++|--))");

    std::smatch res;

    std::string str = ui->plainTextEdit->toPlainText().toStdString();

    while(std::regex_search(str, res, reg))
    {
        str = res.suffix();

        ui->outPlainText->appendPlainText(QString::number(ui->plainTextEdit->toPlainText().mid(0, (ui->plainTextEdit->toPlainText().size() - str.size())).count('\n') + 1));
    }
}


void MainWindow::on_localButton_clicked()
{
    list<string> name;
    list<int> count, localOn, localOff, index;

    int bracket = 0;

    std::regex reg("((size_t|int|double|float|char)\\s*[\\*]*)\\s*(((\\,\\s)?([\\w]+)\\s*((=\\s*[\\w+]*|\\([\\w]+\\))?(\\{[\\w ,]+\\})?)){0,});");

    std::smatch res;

    std::string str;

    for(int i = 0; i < ui->plainTextEdit->toPlainText().size(); i++)
    {
        if(ui->plainTextEdit->toPlainText()[i] == '{' && ui->plainTextEdit->toPlainText()[i + 1] == '\n')
        {
            if(bracket == 0)
            {
                localOn.push_back(i);
            }

            bracket++;
        }
        else if(ui->plainTextEdit->toPlainText()[i] == '}' && ui->plainTextEdit->toPlainText()[i + 1] == '\n')
        {
            if(bracket == 1)
            {
                localOff.push_back(i);
            }

            bracket--;
        }
    }

    ui->outPlainText->clear();
    ui->outPlainText->appendPlainText("cords");

    for(int i = 0; i < localOn.size; i++)
    {
        str = ui->plainTextEdit->toPlainText().mid(localOn[i], localOff[i] - localOn[i]).toStdString();

        while(std::regex_search(str, res, reg))
        {
            int exist = -1;

            for(int i = 0; i < name.size; i++)
            {
                if(name[i] == StdTostr(res[1].str()))
                {
                    exist = i;

                    break;
                }
            }

            if(exist == -1)
            {
                count.push_back(strToQStr(StdTostr(res[3].str())).count(',') + 1);
                name.push_back(StdTostr(res[1].str()));
                qDebug() << strToQStr(StdTostr(res.str()));
            }
            else
            {
                count[exist] += strToQStr(StdTostr(res[3].str())).count(',') + 1;
            }

            str = res.suffix();

            if(exist == -1)
            {
                ui->outPlainText->appendPlainText(QString::number(ui->plainTextEdit->toPlainText().mid(0, localOff[i]).count('\n') - strToQStr(StdTostr(str)).count('\n') + 1));            }
            else
            {
                ui->outPlainText->appendPlainText(QString::number(ui->plainTextEdit->toPlainText().mid(0, localOff[i]).count('\n') - strToQStr(StdTostr(str)).count('\n') + 1));
            }
        }
    }

    ui->outPlainText->appendPlainText("amount");

    for(int i = 0; i < name.size; i++)
    {
        ui->outPlainText->appendPlainText(strToQStr(name[i]) + " " + QString::number(count[i]));
    }
}


void MainWindow::on_overloadButton_clicked()//только для == тупая реализация
{
    ui->outPlainText->clear();

    list<string> funcName;
    list<int> pos;
    list<bool> over;

    int count = 0;

    std::regex reg("(((\\w+)\\s+[\\*]*(\\w*::)?\\s*[\\w]+)\\((\\s*[\\w]*\\s*[\\*]*\\s*\\w+\\s*\\,?\\s*){0,}\\))\\s*\\{");
    //std::regex reg("((\\w+)\\s+[\\*]*(\\w*::)?\\s*((([\\w]+)\\((\\s*[\\w]*\\s*[\\*]*\\s*\\w+\\s*\\,?\\s*){0,}\\))))\\s*\\{");

    std::smatch res;

    std::string str = ui->plainTextEdit->toPlainText().toStdString();

    while(std::regex_search(str, res, reg))
    {
        funcName.push_back(StdTostr(res[2].str()));
        qDebug() << strToQStr(funcName[funcName.size - 1]);

        str = res.suffix();

        pos.push_back((ui->plainTextEdit->toPlainText().mid(0, (ui->plainTextEdit->toPlainText().size() - str.size())).count('\n')));
    }

    for(int i = 0; i < funcName.size; i++)
    {
        over.push_back(false);
    }

    for(int i = 0; i < funcName.size; i++)
    {
        for(int j = i + 1; j < funcName.size; j++)
        {
            qDebug() << strToQStr(funcName[i]) << strToQStr(funcName[j]) << (funcName[i] == funcName[j]);

            if(funcName[i] == funcName[j])
            {
                if(!over[i])
                {
                    ui->outPlainText->appendPlainText(QString::number(pos[i]));
                }

                if(!over[j])
                {
                    ui->outPlainText->appendPlainText(QString::number(pos[j]));
                }


                if(over[i] && over[j])
                {

                }
                else if(over[i] || over[j])
                {
                    count += 1;
                }
                else
                {
                    count += 2;
                }
                over[i] = over[j] = true;
            }

        }

    }


    ui->outPlainText->appendPlainText("amount");
    ui->outPlainText->appendPlainText(QString::number(count));
}



void MainWindow::on_deppButton_clicked()
{
    ui->outPlainText->clear();

    int bracket = 0;
    list<string> name;
    list<int> localOnTemp, localOffTemp, deep;

    std::regex reg("\\s*(if|else|else if)\\s*\\([^\\n.]*\\s*");

    std::string tm = ui->plainTextEdit->toPlainText().toStdString();

    for(int i = 0; i < ui->plainTextEdit->toPlainText().size() - 1; i++)
    {
        if(ui->plainTextEdit->toPlainText()[i] == '{' && ui->plainTextEdit->toPlainText()[i + 1] == '\n')
        {
            localOnTemp.push_back(ui->plainTextEdit->toPlainText().mid(0, i).count('\n'));

            bracket = 1;

            for(int j = i + 1; j < ui->plainTextEdit->toPlainText().size() - 1; j++)
            {
                if(ui->plainTextEdit->toPlainText()[j] == '{' && ui->plainTextEdit->toPlainText()[j + 1] == '\n')
                {
                    bracket++;
                }
                else if(ui->plainTextEdit->toPlainText()[j] == '}' && ui->plainTextEdit->toPlainText()[j + 1] == '\n')
                {
                    bracket--;

                    if(bracket == 0)
                    {
                        localOffTemp.push_back(ui->plainTextEdit->toPlainText().mid(0, j).count('\n'));

                        break;
                    }

                }

            }

        }

    }


    QList tmp = ui->plainTextEdit->toPlainText().split('\n');
    list<QString> text;

    for(int i = 0; i < tmp.size(); i++)
    {
        text.push_back(tmp[i]);
    }


    list<int> localOn, localOff;


    for(int i = 0; i < localOnTemp.size; i++)
    {
        if(std::regex_match(text[localOnTemp[i] - 1].toStdString(), reg))
        {
            qDebug() << text[localOnTemp[i] - 1] << localOnTemp[i] << localOffTemp[i];

            deep.push_back(1);
            localOn.push_back(localOnTemp[i]);
            localOff.push_back(localOffTemp[i]);
        }
    }

    for(int i = 0; i < localOn.size; i++)
    {
        for(int j = localOn[i] + 1; j <= localOff[i]; j++)
        {
            for(int k = 0; k < localOn.size; k++)
            {
                if(localOn[k] == j)
                {
                    deep[k]++;
                }
            }
        }
    }


    for(int i = 0; i < localOn.size; i++)
    {

        ui->outPlainText->appendPlainText(QString::number(deep[i]));
    }

}



void MainWindow::on_logicButton_clicked()
{
    ui->outPlainText->clear();

    std::regex reg("\\s*while\\s*\\(\\s*true\\s*\\)\\s*\\{\\s*\\}");
    std::smatch res;

    std::string str = ui->plainTextEdit->toPlainText().toStdString();

    while(std::regex_search(str, res, reg))
    {
        ui->outPlainText->appendPlainText("while(true) {}");

        str = res.suffix();
    }

    str = ui->plainTextEdit->toPlainText().toStdString();
    reg = ("\\s*while\\s*\\(\\s*false\\s*\\)\\s*\\{");

    while(std::regex_search(str, res, reg))
    {
        ui->outPlainText->appendPlainText("while(false) {...}");

        str = res.suffix();
    }

    str = ui->plainTextEdit->toPlainText().toStdString();
    reg = ("\\s*if\\s*\\(\\s*true\\s*\\)\\s*\\{");

    while(std::regex_search(str, res, reg))
    {
        ui->outPlainText->appendPlainText("if(true) {...}");

        str = res.suffix();
    }

    str = ui->plainTextEdit->toPlainText().toStdString();
    reg = ("\\s*if\\s*\\(\\s*false\\s*\\)\\s*\\{");

    while(std::regex_search(str, res, reg))
    {
        ui->outPlainText->appendPlainText("if(false) {...}");

        str = res.suffix();
    }
}

