#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../libs/crutch_list/crutch_list.h"
#include <QFileDialog>
#include "sportsman.h"
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
    int isLocatedTeam(QString input, shared_ptr<list<sportsman>> lis);
    bool isNormal(list<QString> input);
    void quickSort(list<sportsman>& A, int l, int h);
    int partition (list<sportsman>& arr, int l, int h);

    template<class T>
    void swap(T& first, T& second);

private slots:
    void on_openFileButton_clicked();

    void on_surnameInfo_clicked();

    void on_viewButton_clicked();

    void on_deleteButton_clicked();

    void on_addButton_clicked();

    void on_categotyButton_clicked();

    void on_limitButton_clicked();

    void on_youngTeamButton_clicked();

    void on_correctButton_clicked();

    void on_deleteBox_currentIndexChanged(int index);

    void on_saveButton_clicked();

    void on_sortButton_clicked();

private:
    Ui::MainWindow *ui;
    shared_ptr<list<sportsman>> List;
    QString path;
    bool fileOpen;
};
#endif // MAINWINDOW_H
