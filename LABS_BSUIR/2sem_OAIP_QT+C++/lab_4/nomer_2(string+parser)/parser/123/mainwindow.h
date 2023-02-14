#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "string.h"
#include <regex>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include "../../../../libs/crutch_list/crutch_list.h"
#include <QDebug>
#include "../StaticLib1/framework.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    string QStrTostr(QString input);
    QString strToQStr(string input);
    std::string  strToStd(string input);
    string StdTostr(std::string input);



private slots:
    void on_varNameButton_clicked();

    void on_checkFileButton_clicked();

    void on_classButton_clicked();

    void on_closeButton_clicked();

    void on_funcButton_clicked();

    void on_changeButton_clicked();

    void on_localButton_clicked();

    void on_overloadButton_clicked();

    void on_deppButton_clicked();

    void on_logicButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
