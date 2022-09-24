#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../map/map/Header.h"
#include "../map/map/map.cpp"
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

private slots:
    void on_insertButton_clicked();

    void on_eraseButton_clicked();

    void on_sizeButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::MainWindow *ui;

    map<int, int> mapa;
};
#endif // MAINWINDOW_H
