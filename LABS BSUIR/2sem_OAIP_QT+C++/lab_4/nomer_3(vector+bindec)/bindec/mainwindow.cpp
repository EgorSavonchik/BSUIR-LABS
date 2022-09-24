#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->outPlainTextEdit->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool MainWindow::k_bit(std::string str, int k)
{
    int bit = 0, i = 0;
    int lenstr = str.size();

    for( ; i != (k); i++)
    {
        bit = (str[lenstr - 1] - '0') % 2;
        str[lenstr - 1] = str[lenstr - 1] - bit;

        for(int j = lenstr - 1; j >= 0; j--)
        {
            if((str[j] - '0') % 2 == 0)
            {
                str[j] = (str[j] - '0') / 2 + '0';
            }
            else
            {
                str[j] = (str[j] - '0') / 2 + '0';

                if(j != lenstr - 1)
                {
                    str[j + 1] = str[j + 1] + 5;
                }

            }
        }
    }

    return bit;
}

std::string MainWindow::powstr(const std::string& str, int k)
{
    std::string deg = "1";

    if(k == 0)
    {
        return("1");
    }

    for(int i = 0; i < k; i++)
    {
        deg += '0';
    }

    for(int i = deg.size() - 1, j = str.size() - 1; i >= 0 && j >= 0; i--, j--)
    {
        deg[i] = str[j];
    }

    return(deg);
}


void MainWindow::on_calcButton_clicked()
{
    if(ui->enterEdit->text().toInt() <= 0 || ui->enterEdit->text().toInt() > 10000)
    {
        QMessageBox::warning(this, "incorrect number", "incorrect number");

        return;
    }

    std::string* A = new std::string[10000];
    std::string* B = new std::string[10000];

    A[0] = "0";

    int counterB, n, counterA = 1, k = 1, counterBIN = 1, tmp;

    n = ui->enterEdit->text().toInt();

    while(n >= counterBIN)
    {
        tmp = counterB = 0;

        for(int i = 0; i < counterA; i++)
        {
            bool temp  = k_bit(A[i], k);

            if(!temp)
            {
                A[tmp] = A[i];
                tmp++;
            }
        }

        counterA = tmp;

        for(int i = 0; i < counterA; i++)
        {
            B[i] = powstr(A[i], k - 1);
            counterB++;
        }

        for(int i = 0; i < counterB; i++)
        {
            A[counterA] = B[i];
            counterA++;
        }

        counterBIN += counterB;
        k++;
    }

    ui->outPlainTextEdit->clear();
    ui->outPlainTextEdit->appendPlainText((QString)B[counterB - (counterBIN - n)].c_str());

    delete[] A;
    delete[] B;
}


