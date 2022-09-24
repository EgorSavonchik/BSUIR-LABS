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
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *nameAddEdit;
    QLineEdit *brandAddEdit;
    QPushButton *addButton;
    QLineEdit *readinessAddEdit;
    QLineEdit *dataAddEdit;
    QLabel *label_2;
    QLabel *label_9;
    QWidget *gridWidget_2;
    QGridLayout *gridLayout_2;
    QLineEdit *orderEdit;
    QLineEdit *informationEdit;
    QLabel *label;
    QLabel *label_11;
    QPushButton *saveButton;
    QPushButton *openFileButton;
    QPushButton *informationButton;
    QLabel *label_5;
    QPushButton *sortButton;
    QPushButton *viewButton;
    QLineEdit *nameEnterEdit;
    QPushButton *orderIndayButton;
    QPushButton *orderButton;
    QLineEdit *deleteEdit;
    QPushButton *deleteButton;
    QLabel *label_6;
    QWidget *gridWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_18;
    QLineEdit *readnessCorrectEdit;
    QPushButton *correctButton;
    QComboBox *deleteBox;
    QLabel *label_14;
    QLineEdit *brandCorrectEdit;
    QLineEdit *dataCorrectEdit;
    QLineEdit *nameCorrectEdit;
    QLabel *label_20;
    QLabel *label_13;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 636);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 800, 300));
        gridWidget = new QWidget(centralwidget);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(370, 300, 210, 170));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(gridWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        label_4 = new QLabel(gridWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        nameAddEdit = new QLineEdit(gridWidget);
        nameAddEdit->setObjectName(QString::fromUtf8("nameAddEdit"));

        gridLayout->addWidget(nameAddEdit, 0, 2, 1, 1);

        brandAddEdit = new QLineEdit(gridWidget);
        brandAddEdit->setObjectName(QString::fromUtf8("brandAddEdit"));

        gridLayout->addWidget(brandAddEdit, 1, 2, 1, 1);

        addButton = new QPushButton(gridWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 0, 0, 1, 1);

        readinessAddEdit = new QLineEdit(gridWidget);
        readinessAddEdit->setObjectName(QString::fromUtf8("readinessAddEdit"));

        gridLayout->addWidget(readinessAddEdit, 3, 2, 1, 1);

        dataAddEdit = new QLineEdit(gridWidget);
        dataAddEdit->setObjectName(QString::fromUtf8("dataAddEdit"));

        gridLayout->addWidget(dataAddEdit, 2, 2, 1, 1);

        label_2 = new QLabel(gridWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        label_9 = new QLabel(gridWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 3, 0, 1, 2);

        gridWidget_2 = new QWidget(centralwidget);
        gridWidget_2->setObjectName(QString::fromUtf8("gridWidget_2"));
        gridWidget_2->setGeometry(QRect(0, 300, 370, 300));
        gridLayout_2 = new QGridLayout(gridWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        orderEdit = new QLineEdit(gridWidget_2);
        orderEdit->setObjectName(QString::fromUtf8("orderEdit"));

        gridLayout_2->addWidget(orderEdit, 1, 1, 1, 1);

        informationEdit = new QLineEdit(gridWidget_2);
        informationEdit->setObjectName(QString::fromUtf8("informationEdit"));

        gridLayout_2->addWidget(informationEdit, 0, 1, 1, 1);

        label = new QLabel(gridWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 2, 1, 1);

        label_11 = new QLabel(gridWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_11, 2, 2, 1, 1);

        saveButton = new QPushButton(gridWidget_2);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout_2->addWidget(saveButton, 4, 1, 1, 1);

        openFileButton = new QPushButton(gridWidget_2);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));

        gridLayout_2->addWidget(openFileButton, 4, 0, 1, 1);

        informationButton = new QPushButton(gridWidget_2);
        informationButton->setObjectName(QString::fromUtf8("informationButton"));

        gridLayout_2->addWidget(informationButton, 0, 0, 1, 1);

        label_5 = new QLabel(gridWidget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_5, 1, 2, 1, 1);

        sortButton = new QPushButton(gridWidget_2);
        sortButton->setObjectName(QString::fromUtf8("sortButton"));

        gridLayout_2->addWidget(sortButton, 5, 1, 1, 1);

        viewButton = new QPushButton(gridWidget_2);
        viewButton->setObjectName(QString::fromUtf8("viewButton"));

        gridLayout_2->addWidget(viewButton, 5, 0, 1, 1);

        nameEnterEdit = new QLineEdit(gridWidget_2);
        nameEnterEdit->setObjectName(QString::fromUtf8("nameEnterEdit"));

        gridLayout_2->addWidget(nameEnterEdit, 2, 1, 1, 1);

        orderIndayButton = new QPushButton(gridWidget_2);
        orderIndayButton->setObjectName(QString::fromUtf8("orderIndayButton"));

        gridLayout_2->addWidget(orderIndayButton, 2, 0, 1, 1);

        orderButton = new QPushButton(gridWidget_2);
        orderButton->setObjectName(QString::fromUtf8("orderButton"));

        gridLayout_2->addWidget(orderButton, 1, 0, 1, 1);

        deleteEdit = new QLineEdit(gridWidget_2);
        deleteEdit->setObjectName(QString::fromUtf8("deleteEdit"));

        gridLayout_2->addWidget(deleteEdit, 3, 1, 1, 1);

        deleteButton = new QPushButton(gridWidget_2);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout_2->addWidget(deleteButton, 3, 0, 1, 1);

        label_6 = new QLabel(gridWidget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_6, 3, 2, 1, 1);

        gridWidget_3 = new QWidget(centralwidget);
        gridWidget_3->setObjectName(QString::fromUtf8("gridWidget_3"));
        gridWidget_3->setGeometry(QRect(580, 300, 210, 170));
        gridLayout_3 = new QGridLayout(gridWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_18 = new QLabel(gridWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_18, 0, 2, 1, 1);

        readnessCorrectEdit = new QLineEdit(gridWidget_3);
        readnessCorrectEdit->setObjectName(QString::fromUtf8("readnessCorrectEdit"));

        gridLayout_3->addWidget(readnessCorrectEdit, 3, 3, 1, 1);

        correctButton = new QPushButton(gridWidget_3);
        correctButton->setObjectName(QString::fromUtf8("correctButton"));

        gridLayout_3->addWidget(correctButton, 0, 1, 1, 1);

        deleteBox = new QComboBox(gridWidget_3);
        deleteBox->setObjectName(QString::fromUtf8("deleteBox"));

        gridLayout_3->addWidget(deleteBox, 1, 1, 1, 1);

        label_14 = new QLabel(gridWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_3->addWidget(label_14, 3, 1, 1, 2);

        brandCorrectEdit = new QLineEdit(gridWidget_3);
        brandCorrectEdit->setObjectName(QString::fromUtf8("brandCorrectEdit"));

        gridLayout_3->addWidget(brandCorrectEdit, 1, 3, 1, 1);

        dataCorrectEdit = new QLineEdit(gridWidget_3);
        dataCorrectEdit->setObjectName(QString::fromUtf8("dataCorrectEdit"));

        gridLayout_3->addWidget(dataCorrectEdit, 2, 3, 1, 1);

        nameCorrectEdit = new QLineEdit(gridWidget_3);
        nameCorrectEdit->setObjectName(QString::fromUtf8("nameCorrectEdit"));

        gridLayout_3->addWidget(nameCorrectEdit, 0, 3, 1, 1);

        label_20 = new QLabel(gridWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_20, 1, 2, 1, 1);

        label_13 = new QLabel(gridWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_13, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "brand", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "data", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "readiness", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "enter number", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "order in this day", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        openFileButton->setText(QCoreApplication::translate("MainWindow", "open file", nullptr));
        informationButton->setText(QCoreApplication::translate("MainWindow", "information", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "enter number", nullptr));
        sortButton->setText(QCoreApplication::translate("MainWindow", "Sort by number", nullptr));
        viewButton->setText(QCoreApplication::translate("MainWindow", "view", nullptr));
        orderIndayButton->setText(QCoreApplication::translate("MainWindow", "enter name", nullptr));
        orderButton->setText(QCoreApplication::translate("MainWindow", "complete order", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "delete", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "enter number", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "name", nullptr));
        correctButton->setText(QCoreApplication::translate("MainWindow", "correct", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "readiness", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "brand", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "data", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
