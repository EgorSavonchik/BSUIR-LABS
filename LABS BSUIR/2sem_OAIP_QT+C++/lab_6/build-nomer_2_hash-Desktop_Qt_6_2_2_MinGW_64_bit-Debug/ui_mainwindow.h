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
    QTableWidget *randomTable;
    QTableWidget *plusTable;
    QTableWidget *minusTable;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *addKeyEdit;
    QPushButton *searchButton;
    QPushButton *deleteButton;
    QLineEdit *addValueEdit;
    QLabel *searchResultLabel;
    QLineEdit *deleteEdit;
    QLabel *label;
    QPushButton *addButton;
    QPushButton *plusMinusButton;
    QLineEdit *searchEdit;
    QLabel *label_2;
    QTableWidget *mainTable;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        randomTable = new QTableWidget(centralwidget);
        randomTable->setObjectName(QString::fromUtf8("randomTable"));
        randomTable->setGeometry(QRect(20, 230, 121, 261));
        plusTable = new QTableWidget(centralwidget);
        plusTable->setObjectName(QString::fromUtf8("plusTable"));
        plusTable->setGeometry(QRect(160, 230, 121, 261));
        minusTable = new QTableWidget(centralwidget);
        minusTable->setObjectName(QString::fromUtf8("minusTable"));
        minusTable->setGeometry(QRect(300, 230, 121, 261));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 10, 397, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        addKeyEdit = new QLineEdit(gridLayoutWidget);
        addKeyEdit->setObjectName(QString::fromUtf8("addKeyEdit"));

        gridLayout->addWidget(addKeyEdit, 0, 2, 1, 1);

        searchButton = new QPushButton(gridLayoutWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        gridLayout->addWidget(searchButton, 2, 0, 1, 1);

        deleteButton = new QPushButton(gridLayoutWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout->addWidget(deleteButton, 1, 0, 1, 1);

        addValueEdit = new QLineEdit(gridLayoutWidget);
        addValueEdit->setObjectName(QString::fromUtf8("addValueEdit"));

        gridLayout->addWidget(addValueEdit, 0, 4, 1, 1);

        searchResultLabel = new QLabel(gridLayoutWidget);
        searchResultLabel->setObjectName(QString::fromUtf8("searchResultLabel"));

        gridLayout->addWidget(searchResultLabel, 2, 4, 1, 1);

        deleteEdit = new QLineEdit(gridLayoutWidget);
        deleteEdit->setObjectName(QString::fromUtf8("deleteEdit"));

        gridLayout->addWidget(deleteEdit, 1, 2, 1, 1);

        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 1, 1, 1);

        addButton = new QPushButton(gridLayoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 0, 0, 1, 1);

        plusMinusButton = new QPushButton(gridLayoutWidget);
        plusMinusButton->setObjectName(QString::fromUtf8("plusMinusButton"));

        gridLayout->addWidget(plusMinusButton, 3, 0, 1, 1);

        searchEdit = new QLineEdit(gridLayoutWidget);
        searchEdit->setObjectName(QString::fromUtf8("searchEdit"));

        gridLayout->addWidget(searchEdit, 2, 2, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 3, 1, 1);

        mainTable = new QTableWidget(centralwidget);
        mainTable->setObjectName(QString::fromUtf8("mainTable"));
        mainTable->setGeometry(QRect(460, 10, 311, 491));
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
        deleteButton->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        searchResultLabel->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        plusMinusButton->setText(QCoreApplication::translate("MainWindow", "2 table", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "value", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
