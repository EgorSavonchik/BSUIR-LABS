#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setSceneRect(0, 0, 600, 600);

    ui->objectLabel->hide();
    ui->pointer1Label->hide();
    ui->pointer2Label->hide();
    ui->pointer3Label->hide();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
}


void MainWindow::on_comboBox_activated(int index)
{
    if(index == 0)
    {
        shared_slaid *shared = new shared_slaid();

        scene->addItem(shared);
        shared->setPos(0, 0);

        ui->objectLabel->show();
        ui->pointer1Label->show();
        ui->pointer2Label->show();
        ui->pointer3Label->show();
    }
}

