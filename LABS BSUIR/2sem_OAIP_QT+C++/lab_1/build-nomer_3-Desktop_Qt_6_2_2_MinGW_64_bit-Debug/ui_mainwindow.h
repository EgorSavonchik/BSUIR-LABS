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
    QPushButton *pushButton_3;
    QPushButton *inintialization;
    QPushButton *pushButton_2;
    QPushButton *numberOfweek;
    QPushButton *Nextday;
    QPushButton *Duration;
    QWidget *gridWidget1;
    QGridLayout *gridLayout_2;
    QPushButton *add;
    QPushButton *pushButton_4;
    QLineEdit *lineEdit;
    QPushButton *correct;
    QLineEdit *correctData;
    QLineEdit *addData;
    QWidget *gridWidget2;
    QGridLayout *gridLayout_3;
    QLabel *label;
    QComboBox *comboBox;
    QLineEdit *openFile;
    QPushButton *openFile_2;
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
        tableWidget->setGeometry(QRect(0, 0, 800, 400));
        gridWidget = new QWidget(centralwidget);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(0, 400, 340, 200));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pushButton_3 = new QPushButton(gridWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 1, 2, 1, 1);

        inintialization = new QPushButton(gridWidget);
        inintialization->setObjectName(QString::fromUtf8("inintialization"));

        gridLayout->addWidget(inintialization, 0, 1, 1, 1);

        pushButton_2 = new QPushButton(gridWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 2, 1, 1);

        numberOfweek = new QPushButton(gridWidget);
        numberOfweek->setObjectName(QString::fromUtf8("numberOfweek"));

        gridLayout->addWidget(numberOfweek, 1, 1, 1, 1);

        Nextday = new QPushButton(gridWidget);
        Nextday->setObjectName(QString::fromUtf8("Nextday"));

        gridLayout->addWidget(Nextday, 0, 0, 1, 1);

        Duration = new QPushButton(gridWidget);
        Duration->setObjectName(QString::fromUtf8("Duration"));

        gridLayout->addWidget(Duration, 1, 0, 1, 1);

        gridWidget1 = new QWidget(centralwidget);
        gridWidget1->setObjectName(QString::fromUtf8("gridWidget1"));
        gridWidget1->setGeometry(QRect(340, 400, 281, 200));
        gridLayout_2 = new QGridLayout(gridWidget1);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        add = new QPushButton(gridWidget1);
        add->setObjectName(QString::fromUtf8("add"));

        gridLayout_2->addWidget(add, 1, 1, 1, 1);

        pushButton_4 = new QPushButton(gridWidget1);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 1, 2, 1, 1);

        lineEdit = new QLineEdit(gridWidget1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout_2->addWidget(lineEdit, 0, 2, 1, 1);

        correct = new QPushButton(gridWidget1);
        correct->setObjectName(QString::fromUtf8("correct"));

        gridLayout_2->addWidget(correct, 1, 0, 1, 1);

        correctData = new QLineEdit(gridWidget1);
        correctData->setObjectName(QString::fromUtf8("correctData"));

        gridLayout_2->addWidget(correctData, 0, 0, 1, 1);

        addData = new QLineEdit(gridWidget1);
        addData->setObjectName(QString::fromUtf8("addData"));

        gridLayout_2->addWidget(addData, 0, 1, 1, 1);

        gridWidget2 = new QWidget(centralwidget);
        gridWidget2->setObjectName(QString::fromUtf8("gridWidget2"));
        gridWidget2->setGeometry(QRect(629, 400, 171, 200));
        gridLayout_3 = new QGridLayout(gridWidget2);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label = new QLabel(gridWidget2);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_3->addWidget(label, 0, 0, 1, 1);

        comboBox = new QComboBox(gridWidget2);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        gridLayout_3->addWidget(comboBox, 0, 1, 1, 1);

        openFile = new QLineEdit(gridWidget2);
        openFile->setObjectName(QString::fromUtf8("openFile"));

        gridLayout_3->addWidget(openFile, 1, 1, 1, 1);

        openFile_2 = new QPushButton(gridWidget2);
        openFile_2->setObjectName(QString::fromUtf8("openFile_2"));

        gridLayout_3->addWidget(openFile_2, 1, 0, 1, 1);

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
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Is Leap", nullptr));
        inintialization->setText(QCoreApplication::translate("MainWindow", "init", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Previous Day", nullptr));
        numberOfweek->setText(QCoreApplication::translate("MainWindow", "number of week", nullptr));
        Nextday->setText(QCoreApplication::translate("MainWindow", "Next day", nullptr));
        Duration->setText(QCoreApplication::translate("MainWindow", "Duration", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "add data", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Till bithday", nullptr));
        correct->setText(QCoreApplication::translate("MainWindow", "correct", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "choose date", nullptr));
        openFile_2->setText(QCoreApplication::translate("MainWindow", "open file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
