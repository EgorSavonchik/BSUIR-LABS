#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "plane.h"
#include <QGraphicsItem>
#include <QTimer>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void moveclickedSlot();
    void chassisOnSlot();

private slots:
    void on_move_clicked();

    void on_create_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    class plane *plan;
    QTimer *timerMove;
    QTimer *timerChassis;
};
#endif // MAINWINDOW_H
