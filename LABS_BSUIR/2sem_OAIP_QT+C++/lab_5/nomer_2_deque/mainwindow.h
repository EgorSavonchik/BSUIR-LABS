#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../../../git/queue/Header.h"
#include <QMessageBox>

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
    void on_pushBackButton_clicked();

    void on_pushFrontButton_clicked();

    void on_popBackButton_clicked();

    void on_popFrontButton_clicked();

    void on_sizeButton_clicked();

    void on_emptyButton_clicked();

    void on_clearButton_clicked();

    void on_incButton_clicked();

    void on_decrButton_clicked();

private:
    Ui::MainWindow *ui;

    deque<int> list;
    deque<int>::iterator it = list.begin_it();
};
#endif // MAINWINDOW_H
