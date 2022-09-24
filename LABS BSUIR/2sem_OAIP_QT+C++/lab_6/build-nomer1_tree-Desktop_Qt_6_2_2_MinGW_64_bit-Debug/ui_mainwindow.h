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
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *plainTextEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QPushButton *deleteButton;
    QLabel *label_5;
    QLineEdit *searchEdit;
    QLineEdit *keyEdit;
    QLabel *nomer;
    QPushButton *inOrderButton;
    QPushButton *countButton;
    QLabel *label_3;
    QLabel *resultSearchEdit;
    QLineEdit *valueEdit;
    QLabel *label_4;
    QPushButton *postOrderButton;
    QPushButton *searchButton;
    QPushButton *addButton;
    QPushButton *preOrderButton;
    QLineEdit *deleteEdit;
    QLabel *label_2;
    QPushButton *pushButton;
    QLineEdit *keysEdit;
    QLineEdit *valueEdit_2;
    QLabel *label_6;
    QLabel *label_7;
    QTreeWidget *treeWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(530, 30, 201, 131));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 140, 416, 331));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(gridLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 3, 1, 1);

        deleteButton = new QPushButton(gridLayoutWidget);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout->addWidget(deleteButton, 1, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 5, 1, 1);

        searchEdit = new QLineEdit(gridLayoutWidget);
        searchEdit->setObjectName(QString::fromUtf8("searchEdit"));

        gridLayout->addWidget(searchEdit, 2, 4, 1, 1);

        keyEdit = new QLineEdit(gridLayoutWidget);
        keyEdit->setObjectName(QString::fromUtf8("keyEdit"));

        gridLayout->addWidget(keyEdit, 0, 4, 1, 1);

        nomer = new QLabel(gridLayoutWidget);
        nomer->setObjectName(QString::fromUtf8("nomer"));

        gridLayout->addWidget(nomer, 6, 4, 1, 1);

        inOrderButton = new QPushButton(gridLayoutWidget);
        inOrderButton->setObjectName(QString::fromUtf8("inOrderButton"));

        gridLayout->addWidget(inOrderButton, 4, 2, 1, 1);

        countButton = new QPushButton(gridLayoutWidget);
        countButton->setObjectName(QString::fromUtf8("countButton"));

        gridLayout->addWidget(countButton, 6, 2, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 3, 1, 1);

        resultSearchEdit = new QLabel(gridLayoutWidget);
        resultSearchEdit->setObjectName(QString::fromUtf8("resultSearchEdit"));

        gridLayout->addWidget(resultSearchEdit, 2, 6, 1, 1);

        valueEdit = new QLineEdit(gridLayoutWidget);
        valueEdit->setObjectName(QString::fromUtf8("valueEdit"));

        gridLayout->addWidget(valueEdit, 0, 6, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 3, 1, 1);

        postOrderButton = new QPushButton(gridLayoutWidget);
        postOrderButton->setObjectName(QString::fromUtf8("postOrderButton"));

        gridLayout->addWidget(postOrderButton, 3, 2, 1, 1);

        searchButton = new QPushButton(gridLayoutWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));

        gridLayout->addWidget(searchButton, 2, 2, 1, 1);

        addButton = new QPushButton(gridLayoutWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 0, 2, 1, 1);

        preOrderButton = new QPushButton(gridLayoutWidget);
        preOrderButton->setObjectName(QString::fromUtf8("preOrderButton"));

        gridLayout->addWidget(preOrderButton, 5, 2, 1, 1);

        deleteEdit = new QLineEdit(gridLayoutWidget);
        deleteEdit->setObjectName(QString::fromUtf8("deleteEdit"));

        gridLayout->addWidget(deleteEdit, 1, 4, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 5, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 7, 2, 1, 1);

        keysEdit = new QLineEdit(gridLayoutWidget);
        keysEdit->setObjectName(QString::fromUtf8("keysEdit"));

        gridLayout->addWidget(keysEdit, 7, 4, 1, 1);

        valueEdit_2 = new QLineEdit(gridLayoutWidget);
        valueEdit_2->setObjectName(QString::fromUtf8("valueEdit_2"));

        gridLayout->addWidget(valueEdit_2, 7, 6, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 7, 3, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 7, 5, 1, 1);

        treeWidget = new QTreeWidget(centralwidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setGeometry(QRect(520, 220, 256, 301));
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
        label->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "value", nullptr));
        nomer->setText(QString());
        inOrderButton->setText(QCoreApplication::translate("MainWindow", "in order", nullptr));
        countButton->setText(QCoreApplication::translate("MainWindow", "count 2 list", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        resultSearchEdit->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "key", nullptr));
        postOrderButton->setText(QCoreApplication::translate("MainWindow", "post order", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        preOrderButton->setText(QCoreApplication::translate("MainWindow", "pre order", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "value", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "add array", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "keys", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "values", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
