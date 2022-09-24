#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "product.h"
#include "../../libs/crutch_list/crutch_list.h"
#include <QFile>
#include <QFileDialog>
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

    void view();
    bool isNormal(list_array<QString> input);
    void quickSort(list_array<product>& A, int l, int h);
    int partition (list_array<product>& arr, int l, int h);

    template<class T>
    void swap(T& first, T& second);

private slots:
    void on_openFileButton_clicked();

    void on_viewButton_clicked();

    void on_addButton_clicked();

    void on_correctButton_clicked();

    void on_deleteBox_currentIndexChanged(int index);

    void on_informationButton_clicked();

    void on_orderButton_clicked();

    void on_saveButton_clicked();

    void on_orderIndayButton_clicked();

    void on_deleteButton_clicked();

    void on_sortButton_clicked();

private:
    Ui::MainWindow *ui;
    shared_ptr<list_array<product>> List = new list_array<product>;
    bool fileOpen = false;
    QString path;
};
#endif // MAINWINDOW_H
