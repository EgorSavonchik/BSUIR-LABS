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
#include <QtWidgets/QDateEdit>
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
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *searchButton;
    QLineEdit *searchKeyEdit;
    QLineEdit *deleteEdit;
    QLineEdit *keyEdit;
    QLabel *label;
    QPushButton *eraseButton;
    QPushButton *sizeButton;
    QLabel *sizeLabel;
    QPushButton *insertButton;
    QLabel *label_5;
    QLabel *label_2;
    QLabel *searchResultButton;
    QDateEdit *dateEdit;
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
        tableWidget->setGeometry(QRect(50, 20, 251, 461));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(490, 50, 251, 351));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        searchButton = new QPushButton(gridLayoutWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        gridLayout->addWidget(searchButton, 4, 0, 1, 1);

        searchKeyEdit = new QLineEdit(gridLayoutWidget);
        searchKeyEdit->setObjectName(QString::fromUtf8("searchKeyEdit"));

        gridLayout->addWidget(searchKeyEdit, 4, 2, 1, 1);

        deleteEdit = new QLineEdit(gridLayoutWidget);
        deleteEdit->setObjectName(QString::fromUtf8("deleteEdit"));

        gridLayout->addWidget(deleteEdit, 2, 2, 1, 1);

        keyEdit = new QLineEdit(gridLayoutWidget);
        keyEdit->setObjectName(QString::fromUtf8("keyEdit"));

        gridLayout->addWidget(keyEdit, 1, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 1, 1, 1, 1);

        eraseButton = new QPushButton(gridLayoutWidget);
        eraseButton->setObjectName(QString::fromUtf8("eraseButton"));

        gridLayout->addWidget(eraseButton, 2, 0, 1, 1);

        sizeButton = new QPushButton(gridLayoutWidget);
        sizeButton->setObjectName(QString::fromUtf8("sizeButton"));

        gridLayout->addWidget(sizeButton, 3, 0, 1, 1);

        sizeLabel = new QLabel(gridLayoutWidget);
        sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));

        gridLayout->addWidget(sizeLabel, 3, 1, 1, 1);

        insertButton = new QPushButton(gridLayoutWidget);
        insertButton->setObjectName(QString::fromUtf8("insertButton"));

        gridLayout->addWidget(insertButton, 1, 0, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 1, 1, 1);

        searchResultButton = new QLabel(gridLayoutWidget);
        searchResultButton->setObjectName(QString::fromUtf8("searchResultButton"));

        gridLayout->addWidget(searchResultButton, 4, 3, 1, 1);

        dateEdit = new QDateEdit(centralwidget);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(390, 440, 110, 26));
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
        searchButton->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        eraseButton->setText(QCoreApplication::translate("MainWindow", "erase", nullptr));
        sizeButton->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        sizeLabel->setText(QString());
        insertButton->setText(QCoreApplication::translate("MainWindow", "insert", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        searchResultButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
