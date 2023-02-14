#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->parametr1->hide();
    ui->parametr2->hide();
    ui->speshialButton1->hide();
    ui->speshialButton2->hide();

    ui->get_area->hide();
    ui->get_center->hide();
    ui->get_perimetr->hide();
    ui->moveDown->hide();
    ui->moveLeft->hide();
    ui->moveRigth->hide();
    ui->moveUp->hide();
    ui->rotateLeft->hide();
    ui->rotateRigth->hide();
    ui->zoomMinus->hide();
    ui->zoomPlus->hide();
    ui->label->hide();
    ui->label_2->hide();
    ui->label_3->hide();

    this->setFixedSize(800, 600);

    scene = new QGraphicsScene(this);
    timer = new QTimer(this);

    scene->setSceneRect(0, 0, 500, 500);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setMouseTracking(true);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);    // Настраиваем рендер
    ui->graphicsView->setCacheMode(QGraphicsView::CacheBackground); // Кэш фона
    ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);


    ui->alarmLabel->setText("Select figure");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete timer;

    if(!obj)
    {
        delete obj;
    }
}

void MainWindow::preparing_to_create()
{
    if(obj != 0)
    {
        delete obj;
    }

    scene->clear();
    canveMod = false;
    timer->disconnect();

    ui->perimetrLabel->clear();
    ui->areaLabel->clear();
    ui->centerofgravity->clear();
    ui->speshialButton1->hide();
    ui->speshialButton2->hide();
    ui->parametr1->hide();
    ui->parametr2->hide();
    ui->parametr1->clear();
    ui->parametr2->clear();
    ui->alarmLabel->clear();
}

void MainWindow::showInterfase()
{
    ui->get_area->show();
    ui->get_center->show();
    ui->get_perimetr->show();
    ui->moveDown->show();
    ui->moveLeft->show();
    ui->moveRigth->show();
    ui->moveUp->show();
    ui->rotateLeft->show();
    ui->rotateRigth->show();
    ui->zoomMinus->show();
    ui->zoomPlus->show();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(obj)
    {
        this->showInterfase();
    }

    if(arg1 == "rectangle")
    {
        this->preparing_to_create();

        obj = new rectangle;

        scene->addItem(obj);

        ui->speshialButton1->setText("Set width");
        ui->speshialButton2->setText("Set heigth");

        ui->parametr1->setText(QString::number(obj->speshialParametr1()));
        ui->parametr2->setText(QString::number(obj->speshialParametr2()));

        ui->speshialButton1->show();
        ui->speshialButton2->show();
        ui->parametr1->show();
        ui->parametr2->show();

        obj->setPos(250, 250);
    }
    else if(arg1 == "triangle")
    {
        this->preparing_to_create();

        obj = new triangle;

        scene->addItem(obj);

        ui->speshialButton1->setText("Set side");

        ui->parametr1->setText(QString::number(obj->speshialParametr1()));

        ui->speshialButton1->show();

        ui->parametr1->show();

        obj->setPos(250, 250);
    }
    else if(arg1 == "square")
    {
        this->preparing_to_create();

        obj = new square;

        scene->addItem(obj);

        ui->speshialButton1->setText("Set side");

        ui->parametr1->setText(QString::number(obj->speshialParametr1()));

        ui->speshialButton1->show();

        ui->parametr1->show();

        obj->setPos(250 , 250);
    }
    else if(arg1 == "hexagon")
    {
        this->preparing_to_create();

        obj = new hexagon;

        scene->addItem(obj);

        ui->speshialButton1->setText("Set side");

        ui->parametr1->setText(QString::number(obj->speshialParametr1()));

        ui->speshialButton1->show();

        ui->parametr1->show();

        obj->setPos(250, 250);
    }
    else if(arg1 == "ellips")
    {
        this->preparing_to_create();

        obj = new ellips;

        scene->addItem(obj);

        ui->speshialButton1->setText("Set x radius");
        ui->speshialButton2->setText("Set y radius");

        ui->parametr1->setText(QString::number(obj->speshialParametr1()));
        ui->parametr2->setText(QString::number(obj->speshialParametr2()));

        ui->speshialButton1->show();
        ui->speshialButton2->show();
        ui->parametr1->show();
        ui->parametr2->show();

        obj->setPos(250, 250);
    }
    else if(arg1 == "circle")
    {
        this->preparing_to_create();

        obj = new circle;

        scene->addItem(obj);

        ui->speshialButton1->setText("Set radius");

        ui->parametr1->setText(QString::number(obj->speshialParametr1()));

        ui->speshialButton1->show();

        ui->parametr1->show();

        obj->setPos(250, 250);
    }
    else if(arg1 == "rhombus")
    {
        this->preparing_to_create();

        obj = new rombus;

        scene->addItem(obj);

        ui->speshialButton1->setText("Set side");
        ui->speshialButton2->setText("Set angle");

        ui->parametr1->setText(QString::number(obj->speshialParametr1()));
        ui->parametr2->setText(QString::number(obj->speshialParametr2()));

        ui->speshialButton1->show();
        ui->speshialButton2->show();
        ui->parametr1->show();
        ui->parametr2->show();

        obj->setPos(250, 250);
    }
    else if(arg1 == "5-pointed star")
    {
        this->preparing_to_create();

        obj = new fivepointedstar;

        scene->addItem(obj);

        ui->speshialButton1->setText("Set outide radius");
        ui->speshialButton2->setText("Set inside radius");

        ui->parametr1->setText(QString::number(obj->speshialParametr1()));
        ui->parametr2->setText(QString::number(obj->speshialParametr2()));

        ui->speshialButton1->show();
        ui->speshialButton2->show();
        ui->parametr1->show();
        ui->parametr2->show();

        obj->setPos(250, 250);
    }
    else if(arg1 == "6-pointed star")
    {
        this->preparing_to_create();

        obj = new sixpointedstar;

        scene->addItem(obj);

        ui->speshialButton1->setText("Set outide radius");
        ui->speshialButton2->setText("Set inside radius");

        ui->parametr1->setText(QString::number(obj->speshialParametr1()));
        ui->parametr2->setText(QString::number(obj->speshialParametr2()));

        ui->speshialButton1->show();
        ui->speshialButton2->show();
        ui->parametr1->show();
        ui->parametr2->show();

        obj->setPos(250, 250);
    }
    else if(arg1 == "8-pointed star")
    {
        this->preparing_to_create();

        obj = new eigthpointedstar;

        scene->addItem(obj);

        ui->speshialButton1->setText("Set outide radius");
        ui->speshialButton2->setText("Set inside radius");

        ui->parametr1->setText(QString::number(obj->speshialParametr1()));
        ui->parametr2->setText(QString::number(obj->speshialParametr2()));

        ui->speshialButton1->show();
        ui->speshialButton2->show();
        ui->parametr1->show();
        ui->parametr2->show();

        obj->setPos(250, 250);
    }
    else if(arg1 == "canve")
    {
        this->preparing_to_create();

        canveMod = true;

        ui->get_area->hide();
        ui->get_center->hide();
        ui->get_perimetr->hide();
        ui->moveDown->hide();
        ui->moveLeft->hide();
        ui->moveRigth->hide();
        ui->moveUp->hide();
        ui->rotateLeft->hide();
        ui->rotateRigth->hide();
        ui->zoomMinus->hide();
        ui->zoomPlus->hide();
        ui->label->hide();
        ui->label_2->hide();
        ui->label_3->hide();
    }
}



void MainWindow::on_get_area_clicked()
{
    ui->areaLabel->setNum(obj->area());
}


void MainWindow::on_get_perimetr_clicked()
{
    ui->perimetrLabel->setNum(obj->perimetr());
}

void MainWindow::on_get_center_clicked()
{
    ui->centerofgravity->setText(obj->getcenter());
}



void MainWindow::on_rotateLeft_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateLeftslot()));

    timer->start(100);
}

void MainWindow::on_rotateLeft_released()
{
    timer->stop();

    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateLeftslot()));
}



void MainWindow::on_rotateRigth_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(rotateRigthslot()));

    timer->start(100);
}

void MainWindow::on_rotateRigth_released()
{
    timer->stop();

    disconnect(timer, SIGNAL(timeout()), this, SLOT(rotateRigthslot()));
}


void MainWindow::rotateLeftslot()
{
    obj->rotateLeft();
}

void MainWindow::rotateRigthslot()
{
    obj->rotateRigth();
}

void MainWindow::moveUpslot()
{
    if(obj->x > 500 || obj->x < 0 || obj->y > 500 || obj->y < 0)
    {
        obj->setPos(250,250);

        obj->x = 250;
        obj->y = 250;

        ui->alarmLabel->setText("going beyond");
    }

    obj->moveUp();
}

void MainWindow::moveLeftslot()
{
    if(obj->x > 500 || obj->x < 0 || obj->y > 500 || obj->y < 0)
    {
        obj->setPos(250,250);

        obj->x = 250;
        obj->y = 250;

        ui->alarmLabel->setText("going beyond");
    }

    obj->moveLeft();
}

void MainWindow::moveRigthslot()
{
    if(obj->x > 500 || obj->x < 0 || obj->y > 500 || obj->y < 0)
    {
        obj->setPos(250,250);

        obj->x = 250;
        obj->y = 250;

        ui->alarmLabel->setText("going beyond");
    }

    obj->moveRigth();
}

void MainWindow::moveDownslot()
{
    if(obj->x > 500 || obj->x < 0 || obj->y > 500 || obj->y < 0)
    {
        obj->setPos(250,250);

        obj->x = 250;
        obj->y = 250;

        ui->alarmLabel->setText("going beyond");
    }

    obj->moveDown();
}



void MainWindow::scaleMinusslot()
{
    obj->scaleMinus();
}

void MainWindow::scalePlusslot()
{
    obj->scalePlus();
}



void MainWindow::on_moveUp_pressed()
{
    ui->alarmLabel->setText("");

    connect(timer, SIGNAL(timeout()), this, SLOT(moveUpslot()));

    timer->start(100);
}

void MainWindow::on_moveUp_released()
{
    timer->stop();

    timer->disconnect(timer, SIGNAL(timeout()), this, SLOT(moveUpslot()));
}



void MainWindow::on_moveLeft_pressed()
{
    ui->alarmLabel->setText("");

    connect(timer, SIGNAL(timeout()), this, SLOT(moveLeftslot()));

    timer->start(100);
}

void MainWindow::on_moveLeft_released()
{
    timer->stop();

    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveLeftslot()));
}



void MainWindow::on_moveRigth_pressed()
{
    ui->alarmLabel->setText("");

    connect(timer, SIGNAL(timeout()), this, SLOT(moveRigthslot()));

    timer->start(100);
}

void MainWindow::on_moveRigth_released()
{
    timer->stop();

    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveRigthslot()));
}



void MainWindow::on_moveDown_pressed()
{
    ui->alarmLabel->setText("");

    connect(timer, SIGNAL(timeout()), this, SLOT(moveDownslot()));

    timer->start(100);
}

void MainWindow::on_moveDown_released()
{
    timer->stop();

    disconnect(timer, SIGNAL(timeout()), this, SLOT(moveDownslot()));
}



void MainWindow::on_zoomPlus_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(scalePlusslot()));

    timer->start(100);
}

void MainWindow::on_zoomPlus_released()
{
    timer->stop();

    disconnect(timer, SIGNAL(timeout()), this, SLOT(scalePlusslot()));
}



void MainWindow::on_zoomMinus_pressed()
{
    connect(timer, SIGNAL(timeout()), this, SLOT(scaleMinusslot()));

    timer->start(100);
}

void MainWindow::on_zoomMinus_released()
{
    timer->stop();

    disconnect(timer, SIGNAL(timeout()), this, SLOT(scaleMinusslot()));
}


void MainWindow::on_speshialButton1_clicked()
{
    ui->alarmLabel->clear();

    if(ui->parametr1->text().toInt() && ui->parametr1->text().toInt() <= obj->upperbound() && ui->parametr1->text().toInt() > 0)
    {
        obj->speshialParametr1() = ui->parametr1->text().toInt();

        obj->Recalculation();//если круг то установит равные радиусы, если нет то ниче не сделает // и не только // нет все-таки только костыль для круга

        obj->update();
    }
    else
    {
        ui->alarmLabel->setText("uncorrect size");

        ui->parametr1->setText(QString::number(obj->speshialParametr1()));
    }

}


void MainWindow::on_speshialButton2_clicked()
{
    ui->alarmLabel->clear();

    if(ui->parametr2->text().toInt() && ui->parametr2->text().toInt() <= obj->upperbound2() && ui->parametr2->text().toInt() > 0)
    {
        obj->speshialParametr2() = ui->parametr2->text().toInt();

        obj->update();
    }
    else
    {
        ui->alarmLabel->setText("uncorrect size");

        ui->parametr2->setText(QString::number(obj->speshialParametr2()));
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if(canveMod)
    {
        scene->addEllipse(event->pos().x() - 5, event->pos().y() - 5, 5, 5, QPen(Qt::NoPen), QBrush(Qt::black));
        previousPoint = event->pos();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(canveMod)
    {
        scene->addLine(previousPoint.x(),previousPoint.y(), event->pos().x(), event->pos().y(), QPen(Qt::black,5,Qt::SolidLine,Qt::RoundCap));
        previousPoint = event->pos();
    }
}
