/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QGraphicsView *graphicsView;
    QWidget *formWidget;
    QFormLayout *formLayout;
    QPushButton *get_area;
    QPushButton *get_perimetr;
    QLabel *perimetrLabel;
    QLabel *areaLabel;
    QPushButton *get_center;
    QLabel *centerofgravity;
    QPushButton *speshialButton1;
    QPushButton *speshialButton2;
    QLineEdit *parametr1;
    QLineEdit *parametr2;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QPushButton *moveUp;
    QLabel *label;
    QPushButton *moveLeft;
    QPushButton *moveRigth;
    QPushButton *moveDown;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *zoomPlus;
    QLabel *label_2;
    QPushButton *zoomMinus;
    QSpacerItem *horizontalSpacer;
    QPushButton *rotateLeft;
    QLabel *label_3;
    QPushButton *rotateRigth;
    QLabel *alarmLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(802, 655);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(510, 10, 101, 26));
        comboBox->setMaxVisibleItems(11);
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 500, 500));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setSceneRect(QRectF(0, 0, 0, 0));
        formWidget = new QWidget(centralwidget);
        formWidget->setObjectName(QString::fromUtf8("formWidget"));
        formWidget->setGeometry(QRect(619, 0, 181, 251));
        formLayout = new QFormLayout(formWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        get_area = new QPushButton(formWidget);
        get_area->setObjectName(QString::fromUtf8("get_area"));

        formLayout->setWidget(1, QFormLayout::LabelRole, get_area);

        get_perimetr = new QPushButton(formWidget);
        get_perimetr->setObjectName(QString::fromUtf8("get_perimetr"));

        formLayout->setWidget(0, QFormLayout::LabelRole, get_perimetr);

        perimetrLabel = new QLabel(formWidget);
        perimetrLabel->setObjectName(QString::fromUtf8("perimetrLabel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, perimetrLabel);

        areaLabel = new QLabel(formWidget);
        areaLabel->setObjectName(QString::fromUtf8("areaLabel"));

        formLayout->setWidget(1, QFormLayout::FieldRole, areaLabel);

        get_center = new QPushButton(formWidget);
        get_center->setObjectName(QString::fromUtf8("get_center"));

        formLayout->setWidget(2, QFormLayout::LabelRole, get_center);

        centerofgravity = new QLabel(formWidget);
        centerofgravity->setObjectName(QString::fromUtf8("centerofgravity"));

        formLayout->setWidget(2, QFormLayout::FieldRole, centerofgravity);

        speshialButton1 = new QPushButton(formWidget);
        speshialButton1->setObjectName(QString::fromUtf8("speshialButton1"));

        formLayout->setWidget(3, QFormLayout::LabelRole, speshialButton1);

        speshialButton2 = new QPushButton(formWidget);
        speshialButton2->setObjectName(QString::fromUtf8("speshialButton2"));

        formLayout->setWidget(4, QFormLayout::LabelRole, speshialButton2);

        parametr1 = new QLineEdit(formWidget);
        parametr1->setObjectName(QString::fromUtf8("parametr1"));

        formLayout->setWidget(3, QFormLayout::FieldRole, parametr1);

        parametr2 = new QLineEdit(formWidget);
        parametr2->setObjectName(QString::fromUtf8("parametr2"));

        formLayout->setWidget(4, QFormLayout::FieldRole, parametr2);

        gridWidget = new QWidget(centralwidget);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(500, 250, 300, 250));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        moveUp = new QPushButton(gridWidget);
        moveUp->setObjectName(QString::fromUtf8("moveUp"));

        gridLayout->addWidget(moveUp, 0, 1, 1, 1);

        label = new QLabel(gridWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        moveLeft = new QPushButton(gridWidget);
        moveLeft->setObjectName(QString::fromUtf8("moveLeft"));

        gridLayout->addWidget(moveLeft, 1, 0, 1, 1);

        moveRigth = new QPushButton(gridWidget);
        moveRigth->setObjectName(QString::fromUtf8("moveRigth"));

        gridLayout->addWidget(moveRigth, 1, 2, 1, 1);

        moveDown = new QPushButton(gridWidget);
        moveDown->setObjectName(QString::fromUtf8("moveDown"));

        gridLayout->addWidget(moveDown, 2, 1, 1, 1);

        horizontalWidget = new QWidget(centralwidget);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        horizontalWidget->setGeometry(QRect(0, 500, 800, 100));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(10, -1, 10, -1);
        zoomPlus = new QPushButton(horizontalWidget);
        zoomPlus->setObjectName(QString::fromUtf8("zoomPlus"));

        horizontalLayout->addWidget(zoomPlus);

        label_2 = new QLabel(horizontalWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        zoomMinus = new QPushButton(horizontalWidget);
        zoomMinus->setObjectName(QString::fromUtf8("zoomMinus"));

        horizontalLayout->addWidget(zoomMinus);

        horizontalSpacer = new QSpacerItem(150, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        rotateLeft = new QPushButton(horizontalWidget);
        rotateLeft->setObjectName(QString::fromUtf8("rotateLeft"));

        horizontalLayout->addWidget(rotateLeft);

        label_3 = new QLabel(horizontalWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        rotateRigth = new QPushButton(horizontalWidget);
        rotateRigth->setObjectName(QString::fromUtf8("rotateRigth"));

        horizontalLayout->addWidget(rotateRigth);

        alarmLabel = new QLabel(centralwidget);
        alarmLabel->setObjectName(QString::fromUtf8("alarmLabel"));
        alarmLabel->setGeometry(QRect(510, 210, 281, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 802, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "triangle", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "circle", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "ellips", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("MainWindow", "rhombus", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("MainWindow", "rectangle", nullptr));
        comboBox->setItemText(5, QCoreApplication::translate("MainWindow", "square", nullptr));
        comboBox->setItemText(6, QCoreApplication::translate("MainWindow", "hexagon", nullptr));
        comboBox->setItemText(7, QCoreApplication::translate("MainWindow", "5-pointed star", nullptr));
        comboBox->setItemText(8, QCoreApplication::translate("MainWindow", "6-pointed star", nullptr));
        comboBox->setItemText(9, QCoreApplication::translate("MainWindow", "8-pointed star", nullptr));

        get_area->setText(QCoreApplication::translate("MainWindow", "get area", nullptr));
        get_perimetr->setText(QCoreApplication::translate("MainWindow", "get perimetr", nullptr));
        perimetrLabel->setText(QString());
        areaLabel->setText(QString());
        get_center->setText(QCoreApplication::translate("MainWindow", "get center", nullptr));
        centerofgravity->setText(QString());
        speshialButton1->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        speshialButton2->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        parametr2->setText(QString());
        moveUp->setText(QCoreApplication::translate("MainWindow", "\342\207\221", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "      MOVE", nullptr));
        moveLeft->setText(QCoreApplication::translate("MainWindow", "\342\207\220", nullptr));
        moveRigth->setText(QCoreApplication::translate("MainWindow", "\342\207\222", nullptr));
        moveDown->setText(QCoreApplication::translate("MainWindow", "\342\207\223", nullptr));
        zoomPlus->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "        ZOOM", nullptr));
        zoomMinus->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        rotateLeft->setText(QCoreApplication::translate("MainWindow", "left", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "       ROTATE", nullptr));
        rotateRigth->setText(QCoreApplication::translate("MainWindow", "right", nullptr));
        alarmLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
