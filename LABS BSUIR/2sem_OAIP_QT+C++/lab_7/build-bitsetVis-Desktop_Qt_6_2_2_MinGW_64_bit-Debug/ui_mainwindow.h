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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
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
    QPlainTextEdit *plainTextEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *sizeLabel;
    QPushButton *toStringButton;
    QPushButton *countButton;
    QLabel *noneLabel;
    QPushButton *setButton;
    QPushButton *anyButton;
    QLabel *allLabel;
    QPushButton *allButton;
    QPushButton *flipButton;
    QLineEdit *flipEdit;
    QPushButton *toUllongButton;
    QPushButton *toUlongButton;
    QPushButton *resetButton;
    QLineEdit *resetEdit;
    QLineEdit *setEdit;
    QLabel *anyLabel;
    QPushButton *sizeButton;
    QPushButton *noneButton;
    QLabel *countLabel;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QPushButton *setNumberButton;
    QLineEdit *setNumberEdit;
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
        plainTextEdit->setGeometry(QRect(90, 50, 591, 121));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(110, 280, 541, 231));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        sizeLabel = new QLabel(gridLayoutWidget);
        sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));

        gridLayout->addWidget(sizeLabel, 1, 1, 1, 1);

        toStringButton = new QPushButton(gridLayoutWidget);
        toStringButton->setObjectName(QString::fromUtf8("toStringButton"));

        gridLayout->addWidget(toStringButton, 2, 0, 1, 1);

        countButton = new QPushButton(gridLayoutWidget);
        countButton->setObjectName(QString::fromUtf8("countButton"));

        gridLayout->addWidget(countButton, 0, 2, 1, 1);

        noneLabel = new QLabel(gridLayoutWidget);
        noneLabel->setObjectName(QString::fromUtf8("noneLabel"));

        gridLayout->addWidget(noneLabel, 0, 6, 1, 1);

        setButton = new QPushButton(gridLayoutWidget);
        setButton->setObjectName(QString::fromUtf8("setButton"));

        gridLayout->addWidget(setButton, 3, 2, 1, 1);

        anyButton = new QPushButton(gridLayoutWidget);
        anyButton->setObjectName(QString::fromUtf8("anyButton"));

        gridLayout->addWidget(anyButton, 1, 2, 1, 1);

        allLabel = new QLabel(gridLayoutWidget);
        allLabel->setObjectName(QString::fromUtf8("allLabel"));

        gridLayout->addWidget(allLabel, 0, 1, 1, 1);

        allButton = new QPushButton(gridLayoutWidget);
        allButton->setObjectName(QString::fromUtf8("allButton"));

        gridLayout->addWidget(allButton, 0, 0, 1, 1);

        flipButton = new QPushButton(gridLayoutWidget);
        flipButton->setObjectName(QString::fromUtf8("flipButton"));

        gridLayout->addWidget(flipButton, 2, 2, 1, 1);

        flipEdit = new QLineEdit(gridLayoutWidget);
        flipEdit->setObjectName(QString::fromUtf8("flipEdit"));

        gridLayout->addWidget(flipEdit, 2, 4, 1, 1);

        toUllongButton = new QPushButton(gridLayoutWidget);
        toUllongButton->setObjectName(QString::fromUtf8("toUllongButton"));

        gridLayout->addWidget(toUllongButton, 4, 0, 1, 1);

        toUlongButton = new QPushButton(gridLayoutWidget);
        toUlongButton->setObjectName(QString::fromUtf8("toUlongButton"));

        gridLayout->addWidget(toUlongButton, 3, 0, 1, 1);

        resetButton = new QPushButton(gridLayoutWidget);
        resetButton->setObjectName(QString::fromUtf8("resetButton"));

        gridLayout->addWidget(resetButton, 4, 2, 1, 1);

        resetEdit = new QLineEdit(gridLayoutWidget);
        resetEdit->setObjectName(QString::fromUtf8("resetEdit"));

        gridLayout->addWidget(resetEdit, 4, 4, 1, 1);

        setEdit = new QLineEdit(gridLayoutWidget);
        setEdit->setObjectName(QString::fromUtf8("setEdit"));

        gridLayout->addWidget(setEdit, 3, 4, 1, 1);

        anyLabel = new QLabel(gridLayoutWidget);
        anyLabel->setObjectName(QString::fromUtf8("anyLabel"));

        gridLayout->addWidget(anyLabel, 1, 4, 1, 1);

        sizeButton = new QPushButton(gridLayoutWidget);
        sizeButton->setObjectName(QString::fromUtf8("sizeButton"));

        gridLayout->addWidget(sizeButton, 1, 0, 1, 1);

        noneButton = new QPushButton(gridLayoutWidget);
        noneButton->setObjectName(QString::fromUtf8("noneButton"));

        gridLayout->addWidget(noneButton, 0, 5, 1, 1);

        countLabel = new QLabel(gridLayoutWidget);
        countLabel->setObjectName(QString::fromUtf8("countLabel"));

        gridLayout->addWidget(countLabel, 0, 4, 1, 1);

        formLayoutWidget = new QWidget(centralwidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(60, 210, 221, 41));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        setNumberButton = new QPushButton(formLayoutWidget);
        setNumberButton->setObjectName(QString::fromUtf8("setNumberButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, setNumberButton);

        setNumberEdit = new QLineEdit(formLayoutWidget);
        setNumberEdit->setObjectName(QString::fromUtf8("setNumberEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, setNumberEdit);

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
        sizeLabel->setText(QString());
        toStringButton->setText(QCoreApplication::translate("MainWindow", "to string", nullptr));
        countButton->setText(QCoreApplication::translate("MainWindow", "count", nullptr));
        noneLabel->setText(QString());
        setButton->setText(QCoreApplication::translate("MainWindow", "set", nullptr));
        anyButton->setText(QCoreApplication::translate("MainWindow", "any", nullptr));
        allLabel->setText(QString());
        allButton->setText(QCoreApplication::translate("MainWindow", "all", nullptr));
        flipButton->setText(QCoreApplication::translate("MainWindow", "flip", nullptr));
        toUllongButton->setText(QCoreApplication::translate("MainWindow", "to ullong", nullptr));
        toUlongButton->setText(QCoreApplication::translate("MainWindow", "to ulong", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "reset", nullptr));
        anyLabel->setText(QString());
        sizeButton->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        noneButton->setText(QCoreApplication::translate("MainWindow", "none", nullptr));
        countLabel->setText(QString());
        setNumberButton->setText(QCoreApplication::translate("MainWindow", "set number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
