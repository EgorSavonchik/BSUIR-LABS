#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include "stack.h"
#include <QMessageBox>
#include "../../libs/crutch_list/crutch_list.h"
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

    bool zadacha(QString str);

private slots:
    void on_checkButton_clicked();

private:
    Ui::MainWindow *ui;

    shared_ptr<list<int>> failRow = new list<int>;
    shared_ptr<list<int>> failIndex = new list<int>;
};
#endif // MAINWINDOW_H
