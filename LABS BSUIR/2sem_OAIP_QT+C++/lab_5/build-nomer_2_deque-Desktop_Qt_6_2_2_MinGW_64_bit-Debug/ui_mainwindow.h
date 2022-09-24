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
    QPlainTextEdit *plainTextEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *popFrontButton;
    QPushButton *emptyButton;
    QLabel *sizeLabel;
    QPushButton *pushBackButton;
    QPushButton *pushFrontButton;
    QLabel *emptyLabel;
    QPushButton *popBackButton;
    QPushButton *sizeButton;
    QPushButton *clearButton;
    QLabel *itLabel;
    QPushButton *incButton;
    QPushButton *decrButton;
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
        plainTextEdit->setGeometry(QRect(580, 20, 161, 451));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(40, 30, 295, 451));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        popFrontButton = new QPushButton(gridLayoutWidget);
        popFrontButton->setObjectName(QString::fromUtf8("popFrontButton"));

        gridLayout->addWidget(popFrontButton, 3, 1, 1, 1);

        emptyButton = new QPushButton(gridLayoutWidget);
        emptyButton->setObjectName(QString::fromUtf8("emptyButton"));

        gridLayout->addWidget(emptyButton, 5, 1, 1, 1);

        sizeLabel = new QLabel(gridLayoutWidget);
        sizeLabel->setObjectName(QString::fromUtf8("sizeLabel"));

        gridLayout->addWidget(sizeLabel, 4, 2, 1, 1);

        pushBackButton = new QPushButton(gridLayoutWidget);
        pushBackButton->setObjectName(QString::fromUtf8("pushBackButton"));

        gridLayout->addWidget(pushBackButton, 0, 1, 1, 1);

        pushFrontButton = new QPushButton(gridLayoutWidget);
        pushFrontButton->setObjectName(QString::fromUtf8("pushFrontButton"));

        gridLayout->addWidget(pushFrontButton, 1, 1, 1, 1);

        emptyLabel = new QLabel(gridLayoutWidget);
        emptyLabel->setObjectName(QString::fromUtf8("emptyLabel"));

        gridLayout->addWidget(emptyLabel, 5, 2, 1, 1);

        popBackButton = new QPushButton(gridLayoutWidget);
        popBackButton->setObjectName(QString::fromUtf8("popBackButton"));

        gridLayout->addWidget(popBackButton, 2, 1, 1, 1);

        sizeButton = new QPushButton(gridLayoutWidget);
        sizeButton->setObjectName(QString::fromUtf8("sizeButton"));

        gridLayout->addWidget(sizeButton, 4, 1, 1, 1);

        clearButton = new QPushButton(gridLayoutWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout->addWidget(clearButton, 6, 1, 1, 1);

        itLabel = new QLabel(centralwidget);
        itLabel->setObjectName(QString::fromUtf8("itLabel"));
        itLabel->setGeometry(QRect(440, 210, 63, 20));
        incButton = new QPushButton(centralwidget);
        incButton->setObjectName(QString::fromUtf8("incButton"));
        incButton->setGeometry(QRect(420, 160, 93, 29));
        decrButton = new QPushButton(centralwidget);
        decrButton->setObjectName(QString::fromUtf8("decrButton"));
        decrButton->setGeometry(QRect(420, 240, 93, 29));
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
        popFrontButton->setText(QCoreApplication::translate("MainWindow", "pop front", nullptr));
        emptyButton->setText(QCoreApplication::translate("MainWindow", "empty", nullptr));
        sizeLabel->setText(QString());
        pushBackButton->setText(QCoreApplication::translate("MainWindow", "push back", nullptr));
        pushFrontButton->setText(QCoreApplication::translate("MainWindow", "push front", nullptr));
        emptyLabel->setText(QString());
        popBackButton->setText(QCoreApplication::translate("MainWindow", "pop back", nullptr));
        sizeButton->setText(QCoreApplication::translate("MainWindow", "size", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "clear", nullptr));
        itLabel->setText(QString());
        incButton->setText(QCoreApplication::translate("MainWindow", "++", nullptr));
        decrButton->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
