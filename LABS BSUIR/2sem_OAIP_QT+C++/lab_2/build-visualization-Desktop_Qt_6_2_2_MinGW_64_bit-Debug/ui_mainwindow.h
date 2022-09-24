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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QWidget *gridWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QLineEdit *pushEdit;
    QPushButton *popButton;
    QComboBox *insertPos;
    QComboBox *deletePos;
    QComboBox *comboBox;
    QWidget *gridWidget1;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *countLabel;
    QLabel *headLabel;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 400, 200));
        gridWidget = new QWidget(centralwidget);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(400, 0, 291, 111));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton = new QPushButton(gridWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushEdit = new QLineEdit(gridWidget);
        pushEdit->setObjectName(QString::fromUtf8("pushEdit"));

        gridLayout->addWidget(pushEdit, 0, 1, 1, 1);

        popButton = new QPushButton(gridWidget);
        popButton->setObjectName(QString::fromUtf8("popButton"));

        gridLayout->addWidget(popButton, 1, 0, 1, 1);

        insertPos = new QComboBox(gridWidget);
        insertPos->setObjectName(QString::fromUtf8("insertPos"));

        gridLayout->addWidget(insertPos, 0, 2, 1, 1);

        deletePos = new QComboBox(gridWidget);
        deletePos->setObjectName(QString::fromUtf8("deletePos"));

        gridLayout->addWidget(deletePos, 1, 2, 1, 1);

        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(0, 290, 111, 31));
        gridWidget1 = new QWidget(centralwidget);
        gridWidget1->setObjectName(QString::fromUtf8("gridWidget1"));
        gridWidget1->setGeometry(QRect(0, 200, 201, 81));
        gridLayout_2 = new QGridLayout(gridWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(gridWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        label_2 = new QLabel(gridWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 1, 0, 1, 1);

        countLabel = new QLabel(gridWidget1);
        countLabel->setObjectName(QString::fromUtf8("countLabel"));

        gridLayout_2->addWidget(countLabel, 1, 1, 1, 1);

        headLabel = new QLabel(gridWidget1);
        headLabel->setObjectName(QString::fromUtf8("headLabel"));

        gridLayout_2->addWidget(headLabel, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(690, 490, 93, 29));
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
        pushButton->setText(QCoreApplication::translate("MainWindow", "Push", nullptr));
        popButton->setText(QCoreApplication::translate("MainWindow", "Pop", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "unique_ptr", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "shared and weak_ptr", nullptr));

        label->setText(QCoreApplication::translate("MainWindow", "Head", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Count", nullptr));
        countLabel->setText(QString());
        headLabel->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
