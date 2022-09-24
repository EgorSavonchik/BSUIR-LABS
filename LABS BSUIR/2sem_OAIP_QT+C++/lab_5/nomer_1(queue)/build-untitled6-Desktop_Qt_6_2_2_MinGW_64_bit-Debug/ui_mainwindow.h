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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *List;
    QLabel *label;
    QLabel *label_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *sizeLabel;
    QPushButton *backButton;
    QPushButton *popButton;
    QLabel *frontLabel;
    QPushButton *pushButton;
    QPushButton *sizeButton;
    QLabel *backLabel;
    QPushButton *frontButton;
    QPushButton *funcButton;
    QPlainTextEdit *plainTextList_1;
    QPlainTextEdit *plainTextList_2;
    QPlainTextEdit *plainTextResult;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        List = new QPlainTextEdit(centralwidget);
        List->setObjectName(QString::fromUtf8("List"));
        List->setGeometry(QRect(540, 60, 181, 421));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(560, 500, 63, 20));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(560, 30, 63, 20));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 80, 171, 371));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        sizeLabel = new QLabel(gridLayoutWidget);
        sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));

        gridLayout->addWidget(sizeLabel, 4, 2, 1, 1);

        backButton = new QPushButton(gridLayoutWidget);
        backButton->setObjectName(QString::fromUtf8("backButton"));

        gridLayout->addWidget(backButton, 3, 1, 1, 1);

        popButton = new QPushButton(gridLayoutWidget);
        popButton->setObjectName(QString::fromUtf8("popButton"));

        gridLayout->addWidget(popButton, 1, 1, 1, 1);

        frontLabel = new QLabel(gridLayoutWidget);
        frontLabel->setObjectName(QString::fromUtf8("frontLabel"));

        gridLayout->addWidget(frontLabel, 2, 2, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 1, 1, 1);

        sizeButton = new QPushButton(gridLayoutWidget);
        sizeButton->setObjectName(QString::fromUtf8("sizeButton"));

        gridLayout->addWidget(sizeButton, 4, 1, 1, 1);

        backLabel = new QLabel(gridLayoutWidget);
        backLabel->setObjectName(QString::fromUtf8("backLabel"));

        gridLayout->addWidget(backLabel, 3, 2, 1, 1);

        frontButton = new QPushButton(gridLayoutWidget);
        frontButton->setObjectName(QString::fromUtf8("frontButton"));

        gridLayout->addWidget(frontButton, 2, 1, 1, 1);

        funcButton = new QPushButton(gridLayoutWidget);
        funcButton->setObjectName(QString::fromUtf8("funcButton"));

        gridLayout->addWidget(funcButton, 5, 1, 1, 1);

        plainTextList_1 = new QPlainTextEdit(centralwidget);
        plainTextList_1->setObjectName(QString::fromUtf8("plainTextList_1"));
        plainTextList_1->setGeometry(QRect(240, 80, 81, 371));
        plainTextList_2 = new QPlainTextEdit(centralwidget);
        plainTextList_2->setObjectName(QString::fromUtf8("plainTextList_2"));
        plainTextList_2->setGeometry(QRect(330, 80, 81, 371));
        plainTextResult = new QPlainTextEdit(centralwidget);
        plainTextResult->setObjectName(QString::fromUtf8("plainTextResult"));
        plainTextResult->setGeometry(QRect(420, 80, 81, 371));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(240, 50, 63, 20));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(330, 50, 63, 20));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(420, 50, 63, 20));
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
        label->setText(QCoreApplication::translate("MainWindow", "down", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "up", nullptr));
        sizeLabel->setText(QString());
        backButton->setText(QCoreApplication::translate("MainWindow", "back", nullptr));
        popButton->setText(QCoreApplication::translate("MainWindow", "pop front", nullptr));
        frontLabel->setText(QString());
        pushButton->setText(QCoreApplication::translate("MainWindow", "push front", nullptr));
        sizeButton->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        backLabel->setText(QString());
        frontButton->setText(QCoreApplication::translate("MainWindow", "front", nullptr));
        funcButton->setText(QCoreApplication::translate("MainWindow", "variant 10", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "list 1", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "list 2", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "result", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
