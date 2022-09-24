#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "stack.h"
#include <QMessageBox>
#include "../../libs/crutch_list/crutch_list.h"
#include <QFile>
#include <QFileDialog>
#include "opz.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_addButton_clicked();

private:
    Ui::MainWindow *ui;

    int counter = 0;
};
#endif // MAINWINDOW_H
