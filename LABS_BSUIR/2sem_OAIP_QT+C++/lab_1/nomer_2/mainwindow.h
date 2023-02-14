#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include "rectangle.h"
#include "figure.h"
#include "triangle.h"
#include "square.h"
#include "hexagon.h"
#include "circle.h"
#include "ellips.h"
#include "rombus.h"
#include "fivepointedstar.h"
#include "sixpointedstar.h"
#include "eigthpointedstar.h"
#include <QTimer>
#include <QMouseEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void preparing_to_create();
    void showInterfase();

public slots:
    void rotateLeftslot();
    void rotateRigthslot();

    void moveUpslot();
    void moveLeftslot();
    void moveRigthslot();
    void moveDownslot();

    void scaleMinusslot();
    void scalePlusslot();


private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_get_area_clicked();

    void on_get_perimetr_clicked();

    void on_get_center_clicked();

    void on_rotateLeft_pressed();

    void on_rotateLeft_released();

    void on_moveUp_pressed();

    void on_moveUp_released();

    void on_moveLeft_pressed();

    void on_moveLeft_released();

    void on_moveRigth_pressed();

    void on_moveRigth_released();

    void on_moveDown_pressed();

    void on_moveDown_released();

    void on_zoomPlus_pressed();

    void on_rotateRigth_pressed();

    void on_rotateRigth_released();

    void on_zoomPlus_released();

    void on_zoomMinus_pressed();

    void on_zoomMinus_released();

    void on_speshialButton1_clicked();

    void on_speshialButton2_clicked();

    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    figure *obj;
    QTimer *timer;

    QPoint previousPoint;
    bool canveMod = false;
};
#endif // MAINWINDOW_H
