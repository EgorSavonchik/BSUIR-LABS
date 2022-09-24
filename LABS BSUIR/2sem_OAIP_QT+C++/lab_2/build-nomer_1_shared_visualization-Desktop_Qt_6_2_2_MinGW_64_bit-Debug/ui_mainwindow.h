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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGraphicsView *graphicsView;
    QComboBox *comboBox;
    QLabel *objectLabel;
    QLabel *pointer1Label;
    QLabel *pointer2Label;
    QLabel *pointer3Label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 600, 575));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(610, 10, 121, 21));
        objectLabel = new QLabel(centralwidget);
        objectLabel->setObjectName(QString::fromUtf8("objectLabel"));
        objectLabel->setGeometry(QRect(260, 285, 80, 30));
        QFont font;
        font.setPointSize(14);
        objectLabel->setFont(font);
        objectLabel->setTextFormat(Qt::AutoText);
        objectLabel->setAlignment(Qt::AlignCenter);
        pointer1Label = new QLabel(centralwidget);
        pointer1Label->setObjectName(QString::fromUtf8("pointer1Label"));
        pointer1Label->setGeometry(QRect(50, 125, 100, 50));
        QFont font1;
        font1.setPointSize(12);
        pointer1Label->setFont(font1);
        pointer1Label->setAlignment(Qt::AlignCenter);
        pointer2Label = new QLabel(centralwidget);
        pointer2Label->setObjectName(QString::fromUtf8("pointer2Label"));
        pointer2Label->setGeometry(QRect(250, 125, 100, 50));
        pointer2Label->setFont(font1);
        pointer2Label->setAlignment(Qt::AlignCenter);
        pointer3Label = new QLabel(centralwidget);
        pointer3Label->setObjectName(QString::fromUtf8("pointer3Label"));
        pointer3Label->setGeometry(QRect(450, 125, 100, 50));
        pointer3Label->setFont(font1);
        pointer3Label->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
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
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "shared_ptr", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "weak_ptr", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("MainWindow", "unique_ptr", nullptr));

        objectLabel->setText(QCoreApplication::translate("MainWindow", "Object", nullptr));
        pointer1Label->setText(QCoreApplication::translate("MainWindow", "Pointer 1", nullptr));
        pointer2Label->setText(QCoreApplication::translate("MainWindow", "Pointer 2", nullptr));
        pointer3Label->setText(QCoreApplication::translate("MainWindow", "Pointer 3", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
