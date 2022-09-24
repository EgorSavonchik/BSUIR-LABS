#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../map/map/Header.h"
#include "../map/map/map.cpp"

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
    void on_allButton_clicked();

    void on_sizeButton_clicked();

    void on_toStringButton_clicked();

    void on_toUlongButton_clicked();

    void on_toUllongButton_clicked();

    void on_countButton_clicked();

    void on_anyButton_clicked();

    void on_flipButton_clicked();

    void on_setButton_clicked();

    void on_resetButton_clicked();

    void on_noneButton_clicked();

private:
    Ui::MainWindow *ui;

    bitset<80> bitsus = bitset<80>(20);
};
#endif // MAINWINDOW_H
