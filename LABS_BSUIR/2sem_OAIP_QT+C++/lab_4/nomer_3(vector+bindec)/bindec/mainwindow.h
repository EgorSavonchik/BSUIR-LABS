#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
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

    std::string powstr(const std::string& str, int k);
    bool k_bit(std::string str, int k);

private slots:
    void on_calcButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
