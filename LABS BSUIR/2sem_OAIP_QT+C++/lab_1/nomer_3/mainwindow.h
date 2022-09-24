#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qtablewidget.h>
#include <date.h>
#include <QFileInfo>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void inintialyze();

    Date* pushBack(Date data);

    bool isData(QString str);

private slots:
    void on_inintialization_clicked();

    void on_pushButton_2_clicked();

    void on_numberOfweek_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_correct_clicked();

    void on_Nextday_clicked();

    void on_Duration_clicked();

    void on_add_clicked();

    void on_openFile_2_clicked();

private:
    Ui::MainWindow *ui;
    Date *dataArray = nullptr;
    int arraySize;
    QString filename = "C:\\Users\\HP\\Desktop\\labs\\OAIP_C++_QT\\lab_1\\nomer_3\\input.txt.txt";
};
#endif // MAINWINDOW_H
