#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tree.h"
#include "../../../libs/crutch_list/crutch_list.h"
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

    void on_addButton_clicked();

    void on_postOrderButton_clicked();

    void on_inOrderButton_clicked();

    void on_preOrderButton_clicked();

    void on_deleteButton_clicked();

    void on_searchButton_clicked();

    void on_countButton_clicked();

    void on_pushButton_clicked();

private:
   // treeNode<int>* test = nullptr;
    //BST tree;
    new_tree tree;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
