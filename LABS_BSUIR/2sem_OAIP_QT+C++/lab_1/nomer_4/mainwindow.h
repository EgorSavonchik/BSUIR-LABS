#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "train.h"
#include <QFile>
#include "dialogadd.h"
#include "dialogcorrect.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    void append(QString destination);
    void inut();
    void save();
    bool isTrain(QString input);

private slots:
    void on_viewFileButton_clicked();

    void on_initialization_clicked();

    void on_freePlaces_clicked();

    void on_destinationList_currentTextChanged(const QString &arg1);

    void on_weekButton_clicked();

    void on_deleteButton_clicked();

    void on_pushButton_clicked();

    void on_correctButton_clicked();

    void on_fileButton_clicked();

public slots:
    void up();
    void forcorrect();

private:
    Ui::MainWindow *ui;
    train *trainList;
    QString filename = "C:\\Users\\HP\\Desktop\\labs\\OAIP_C++_QT\\lab_1\\nomer_4\\input.txt";
    int arraySize = 0;
    QString *destinationList;
    int destinationListSize = 0;
    QString weekDays[7] = { "Monday" , "Tuesday" , "Wednesday" , "Thursday" , "Friday" , "Saturday" , "Sunday"};
    DialogAdd *add;
    DialogCorrect *correct;

    void pushBack(QString add);
};
#endif // MAINWINDOW_H
