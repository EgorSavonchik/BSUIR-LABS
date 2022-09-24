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


void MainWindow::on_checkButton_clicked()
{
    if(zadacha(ui->plainTextEdit->toPlainText()))
    {
        QMessageBox::information(this, "result", "Yes");
    }
    else
    {
        QMessageBox::information(this, "result", "no, mistake in " + QString::number((*failRow)[0]) + " row and " + QString::number((*failIndex)[0]) + " index");
    }

}

bool MainWindow::zadacha(QString str)
{

    Stack st, posPow, posST;
    QChar ch;
    QChar bracket;
    int i = 0, row = 1, index = 1;

    failIndex.reset(new list<int>);
    failRow.reset(new list<int>);

    for (; i < str.size(); i++, index++)
    {
        ch = str[i];

        if(ch == '\n')
        {
            row++;
            index = 0;
        }


        if(ch == '(' || ch == '[' || ch == '{')
        {
            st.push(ch);

            failIndex->push_back(index);
            failRow->push_back(row);
        }
        else if(ch == ')' || ch == ']' || ch == '}')
        {
            if (st.st_empty())
            {

                failIndex->push_back(index);
                failRow->push_back(row);

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
            else if(bracket == ']')
            {
                bracket = ']';
            }

            if (bracket != ch)
            {
                failIndex->push_back(index);
                failRow->push_back(row);

                return false;
            }

            st.pop();
            failIndex->deleteNode(failIndex->size - 1);
            failRow->deleteNode(failRow->size - 1);
        }
    }

   // failIndex->push_back(index);
    //failRow->push_back(row);

    return st.st_empty() ? true : false;
}
