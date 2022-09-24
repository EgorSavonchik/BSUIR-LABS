#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "queue_func.h"
#include "QMessageBox"


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
    void on_pushButton_clicked();

    void on_popButton_clicked();

    void on_frontButton_clicked();

    void on_backButton_clicked();

    void on_sizeButton_clicked();

    void on_funcButton_clicked();

private:
    Ui::MainWindow *ui;

    queue<int> list;
};
#endif // MAINWINDOW_H
