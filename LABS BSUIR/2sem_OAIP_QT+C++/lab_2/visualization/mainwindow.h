#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stack.h"
#include "doublelinks.h"
#include "../../libs/smart_ptr/smart_ptrs.h"

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

    void on_comboBox_activated(int index);

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    STACK<int> st;
    shared_ptr<doublelinks>list;

    int mode;
};
#endif // MAINWINDOW_H
