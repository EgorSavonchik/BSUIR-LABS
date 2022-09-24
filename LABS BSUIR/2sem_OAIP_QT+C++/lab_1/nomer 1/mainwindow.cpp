#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rect.h"
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedSize(800, 600);

    scene = new QGraphicsScene;
    timerMove = new QTimer(this);
    timerChassis = new QTimer(this);
    plan = new class plane();

    scene->setSceneRect(0, 0, 800, 550);

    ui->graphicsView->setScene(scene);


    scene->addItem(plan);
    plan->setPos(0, 0);

    connect(timerChassis, SIGNAL(timeout()), this, SLOT(chassisOnSlot()));
    connect(timerMove, SIGNAL(timeout()), this, SLOT(moveclickedSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete plan;
    delete scene;
    delete timerMove;
    delete timerChassis;
}

void MainWindow::moveclickedSlot()
{
    plan->moveByslot();

    if(plan->x() >= 600)
    {
        timerMove->stop();
    }
}

void MainWindow::chassisOnSlot()
{
    plan->chassis_on();
    scene->update();
}


void MainWindow::on_move_clicked()
{

    timerMove->start(100);


    if(plan->x() >= 600)
    {
        timerChassis->stop();
        timerMove->stop();

        plan->chassis_off();

        plan->setPos(0, 0);
    }
}


void MainWindow::on_create_clicked()
{
    timerChassis->start(100);
}

