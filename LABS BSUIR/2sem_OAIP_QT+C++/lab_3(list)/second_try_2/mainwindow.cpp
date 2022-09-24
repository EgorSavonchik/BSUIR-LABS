#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString *MainWindow::gerArr(QList<QString> input)
{
    QString* tmp = new QString[input.size()];

    for(int i = 0; i < input.size(); i++)
    {
        tmp[i] = input[i];
    }

    size = input.size();

    return tmp;
}


bool MainWindow::zadacha(QString* str) {

    Stack st;
    QChar ch;
    QChar bracket;

    posPow.reset(new list<int>);
    posST.reset(new list<int>);

    for (int row = 0; row < size; row++)
    {
        for (int i = 0; i < str[row].size(); ++i) {

            ch = str[row][i];

            if(ch == '(' || ch == '[' || ch == '{')
            {
                st.push(ch);
                posPow->push_back(row);
                posST->push_back(i);
            }
            else if(ch == ')' || ch == ']' || ch == '}')
            {
                if (st.st_empty())
                {
                    posPow->push_back(row);
                    posST->push_back(i);

                    return false;
                }

                bracket = st.peek();

                if(bracket == '(')
                {
                    bracket = ')';
                }
                else if(bracket == '{')
                {
                    bracket = '}';
                }
                else if(bracket == '[')
                {
                    bracket = ']';
                }

                if (bracket != ch)
                {
                    posPow->push_back(row);
                    posST->push_back(i);

                    return false;
                }

                st.pop();
                posPow->deleteNode(posPow->size - 1);
                posST->deleteNode(posST->size - 1);
            }
        }
    }

    return st.st_empty() ? true : false;
}

void MainWindow::on_checkButton_clicked()
{
    if(zadacha(gerArr(ui->plainTextEdit->toPlainText().split('\n'))))
    {
        QMessageBox::information(this, "result", "Yes");
    }
    else
    {
        QMessageBox::information(this, "result", "no, mistake in "  + QString::number((*posPow)[0] + 1) + " row and " + QString::number((*posST)[0] + 1) + " index");
    }
}


void MainWindow::on_fileButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "choose file", "C:\\Users\\HP\\Desktop\\labs\\OAIP_C++_QT\\lab_3(list)\\second_try_2\\input.txt" , "Text file (*txt)");

    QFile file(path);
    QTextStream in(&file);

    file.open(QFile::ReadOnly);

    ui->plainTextEdit->setPlainText(in.readAll());

    file.close();

    this->on_checkButton_clicked();
}

