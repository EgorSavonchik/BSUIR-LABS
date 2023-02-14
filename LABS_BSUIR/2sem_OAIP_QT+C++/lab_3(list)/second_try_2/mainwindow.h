#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "stack.h"
#include <QMessageBox>
#include "../../libs/crutch_list/crutch_list.h"
#include <QFile>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool zadacha(QString* str);
    QString* gerArr(QList<QString> input);
private slots:
    void on_checkButton_clicked();

    void on_fileButton_clicked();

private:
    Ui::MainWindow *ui;

    int size;

    shared_ptr<list<int>> posPow = new list<int>, posST = new list<int>;
};
#endif // MAINWINDOW_H
