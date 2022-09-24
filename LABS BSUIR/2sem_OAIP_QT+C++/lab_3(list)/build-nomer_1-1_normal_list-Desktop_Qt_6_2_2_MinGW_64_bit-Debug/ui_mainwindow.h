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
    QLabel *label_4;
    QLabel *label_9;
    QLineEdit *ageEdit;
    QLabel *label_8;
    QLineEdit *nameEdit;
    QLabel *label_10;
    QLabel *label_6;
    QLineEdit *surnameAddEdit;
    QLabel *label_2;
    QLineEdit *countryEdit;
    QLineEdit *teamEdit;
    QLineEdit *numberEdit;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *weigthEdit;
    QLineEdit *patronymicEdit;
    QLineEdit *heigthEdit;
    QPushButton *addButton;
    QWidget *gridWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *surnameInfo;
    QPushButton *openFileButton;
    QLineEdit *surnameEdit;
    QPushButton *deleteButton;
    QPushButton *limitButton;
    QLabel *label_11;
    QPushButton *categotyButton;
    QLineEdit *limitEdit;
    QLabel *label_12;
    QLineEdit *categoryEdit;
    QLabel *label;
    QPushButton *youngTeamButton;
    QLineEdit *deleteEdit;
    QPushButton *viewButton;
    QPushButton *saveButton;
    QPushButton *sortButton;
    QWidget *gridWidget_3;
    QGridLayout *gridLayout_3;
    QLabel *label_15;
    QLineEdit *patronymicEditCorrect;
    QLabel *label_19;
    QLineEdit *weigthEditCorrect;
    QLineEdit *heigthEditCorrect;
    QLabel *label_16;
    QLineEdit *ageEditCorrect;
    QLineEdit *nameEditCorrect;
    QLabel *label_18;
    QLineEdit *teamEditCorrect;
    QLabel *label_13;
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *countryEditCorrect;
    QLineEdit *numberEditCorrect;
    QLabel *label_14;
    QLabel *label_17;
    QLineEdit *surnameEditCorrect;
    QPushButton *correctButton;
    QComboBox *deleteBox;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(890, 627);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 800, 300));
        gridWidget = new QWidget(centralwidget);
        gridWidget->setObjectName(QString::fromUtf8("gridWidget"));
        gridWidget->setGeometry(QRect(370, 300, 210, 300));
        gridLayout = new QGridLayout(gridWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_4 = new QLabel(gridWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 2, 1, 1, 1);

        label_9 = new QLabel(gridWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_9, 3, 1, 1, 1);

        ageEdit = new QLineEdit(gridWidget);
        ageEdit->setObjectName(QString::fromUtf8("ageEdit"));

        gridLayout->addWidget(ageEdit, 6, 2, 1, 1);

        label_8 = new QLabel(gridWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 8, 1, 1, 1);

        nameEdit = new QLineEdit(gridWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));

        gridLayout->addWidget(nameEdit, 2, 2, 1, 1);

        label_10 = new QLabel(gridWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 4, 1, 1, 1);

        label_6 = new QLabel(gridWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_6, 6, 1, 1, 1);

        surnameAddEdit = new QLineEdit(gridWidget);
        surnameAddEdit->setObjectName(QString::fromUtf8("surnameAddEdit"));

        gridLayout->addWidget(surnameAddEdit, 3, 2, 1, 1);

        label_2 = new QLabel(gridWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        countryEdit = new QLineEdit(gridWidget);
        countryEdit->setObjectName(QString::fromUtf8("countryEdit"));

        gridLayout->addWidget(countryEdit, 0, 2, 1, 1);

        teamEdit = new QLineEdit(gridWidget);
        teamEdit->setObjectName(QString::fromUtf8("teamEdit"));

        gridLayout->addWidget(teamEdit, 1, 2, 1, 1);

        numberEdit = new QLineEdit(gridWidget);
        numberEdit->setObjectName(QString::fromUtf8("numberEdit"));

        gridLayout->addWidget(numberEdit, 5, 2, 1, 1);

        label_7 = new QLabel(gridWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_7, 7, 1, 1, 1);

        label_3 = new QLabel(gridWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 1, 1, 1, 1);

        label_5 = new QLabel(gridWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 5, 1, 1, 1);

        weigthEdit = new QLineEdit(gridWidget);
        weigthEdit->setObjectName(QString::fromUtf8("weigthEdit"));

        gridLayout->addWidget(weigthEdit, 8, 2, 1, 1);

        patronymicEdit = new QLineEdit(gridWidget);
        patronymicEdit->setObjectName(QString::fromUtf8("patronymicEdit"));

        gridLayout->addWidget(patronymicEdit, 4, 2, 1, 1);

        heigthEdit = new QLineEdit(gridWidget);
        heigthEdit->setObjectName(QString::fromUtf8("heigthEdit"));

        gridLayout->addWidget(heigthEdit, 7, 2, 1, 1);

        addButton = new QPushButton(gridWidget);
        addButton->setObjectName(QString::fromUtf8("addButton"));

        gridLayout->addWidget(addButton, 0, 0, 1, 1);

        gridWidget_2 = new QWidget(centralwidget);
        gridWidget_2->setObjectName(QString::fromUtf8("gridWidget_2"));
        gridWidget_2->setGeometry(QRect(0, 300, 370, 300));
        gridLayout_2 = new QGridLayout(gridWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        surnameInfo = new QPushButton(gridWidget_2);
        surnameInfo->setObjectName(QString::fromUtf8("surnameInfo"));

        gridLayout_2->addWidget(surnameInfo, 0, 0, 1, 1);

        openFileButton = new QPushButton(gridWidget_2);
        openFileButton->setObjectName(QString::fromUtf8("openFileButton"));

        gridLayout_2->addWidget(openFileButton, 5, 0, 1, 1);

        surnameEdit = new QLineEdit(gridWidget_2);
        surnameEdit->setObjectName(QString::fromUtf8("surnameEdit"));

        gridLayout_2->addWidget(surnameEdit, 0, 1, 1, 1);

        deleteButton = new QPushButton(gridWidget_2);
        deleteButton->setObjectName(QString::fromUtf8("deleteButton"));

        gridLayout_2->addWidget(deleteButton, 1, 0, 1, 1);

        limitButton = new QPushButton(gridWidget_2);
        limitButton->setObjectName(QString::fromUtf8("limitButton"));

        gridLayout_2->addWidget(limitButton, 3, 0, 1, 1);

        label_11 = new QLabel(gridWidget_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_11, 2, 2, 1, 1);

        categotyButton = new QPushButton(gridWidget_2);
        categotyButton->setObjectName(QString::fromUtf8("categotyButton"));

        gridLayout_2->addWidget(categotyButton, 2, 0, 1, 1);

        limitEdit = new QLineEdit(gridWidget_2);
        limitEdit->setObjectName(QString::fromUtf8("limitEdit"));

        gridLayout_2->addWidget(limitEdit, 3, 1, 1, 1);

        label_12 = new QLabel(gridWidget_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label_12, 3, 2, 1, 1);

        categoryEdit = new QLineEdit(gridWidget_2);
        categoryEdit->setObjectName(QString::fromUtf8("categoryEdit"));

        gridLayout_2->addWidget(categoryEdit, 2, 1, 1, 1);

        label = new QLabel(gridWidget_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 2, 1, 1);

        youngTeamButton = new QPushButton(gridWidget_2);
        youngTeamButton->setObjectName(QString::fromUtf8("youngTeamButton"));

        gridLayout_2->addWidget(youngTeamButton, 4, 0, 1, 1);

        deleteEdit = new QLineEdit(gridWidget_2);
        deleteEdit->setObjectName(QString::fromUtf8("deleteEdit"));

        gridLayout_2->addWidget(deleteEdit, 1, 1, 1, 1);

        viewButton = new QPushButton(gridWidget_2);
        viewButton->setObjectName(QString::fromUtf8("viewButton"));

        gridLayout_2->addWidget(viewButton, 6, 0, 1, 1);

        saveButton = new QPushButton(gridWidget_2);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));

        gridLayout_2->addWidget(saveButton, 5, 1, 1, 1);

        sortButton = new QPushButton(gridWidget_2);
        sortButton->setObjectName(QString::fromUtf8("sortButton"));

        gridLayout_2->addWidget(sortButton, 6, 1, 1, 1);

        gridWidget_3 = new QWidget(centralwidget);
        gridWidget_3->setObjectName(QString::fromUtf8("gridWidget_3"));
        gridWidget_3->setGeometry(QRect(580, 300, 210, 300));
        gridLayout_3 = new QGridLayout(gridWidget_3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_15 = new QLabel(gridWidget_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_15, 8, 2, 1, 1);

        patronymicEditCorrect = new QLineEdit(gridWidget_3);
        patronymicEditCorrect->setObjectName(QString::fromUtf8("patronymicEditCorrect"));

        gridLayout_3->addWidget(patronymicEditCorrect, 4, 3, 1, 1);

        label_19 = new QLabel(gridWidget_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_19, 7, 2, 1, 1);

        weigthEditCorrect = new QLineEdit(gridWidget_3);
        weigthEditCorrect->setObjectName(QString::fromUtf8("weigthEditCorrect"));

        gridLayout_3->addWidget(weigthEditCorrect, 8, 3, 1, 1);

        heigthEditCorrect = new QLineEdit(gridWidget_3);
        heigthEditCorrect->setObjectName(QString::fromUtf8("heigthEditCorrect"));

        gridLayout_3->addWidget(heigthEditCorrect, 7, 3, 1, 1);

        label_16 = new QLabel(gridWidget_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_16, 4, 2, 1, 1);

        ageEditCorrect = new QLineEdit(gridWidget_3);
        ageEditCorrect->setObjectName(QString::fromUtf8("ageEditCorrect"));

        gridLayout_3->addWidget(ageEditCorrect, 6, 3, 1, 1);

        nameEditCorrect = new QLineEdit(gridWidget_3);
        nameEditCorrect->setObjectName(QString::fromUtf8("nameEditCorrect"));

        gridLayout_3->addWidget(nameEditCorrect, 2, 3, 1, 1);

        label_18 = new QLabel(gridWidget_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_18, 0, 2, 1, 1);

        teamEditCorrect = new QLineEdit(gridWidget_3);
        teamEditCorrect->setObjectName(QString::fromUtf8("teamEditCorrect"));

        gridLayout_3->addWidget(teamEditCorrect, 1, 3, 1, 1);

        label_13 = new QLabel(gridWidget_3);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_13, 2, 2, 1, 1);

        label_20 = new QLabel(gridWidget_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_20, 1, 2, 1, 1);

        label_21 = new QLabel(gridWidget_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_21, 5, 2, 1, 1);

        countryEditCorrect = new QLineEdit(gridWidget_3);
        countryEditCorrect->setObjectName(QString::fromUtf8("countryEditCorrect"));

        gridLayout_3->addWidget(countryEditCorrect, 0, 3, 1, 1);

        numberEditCorrect = new QLineEdit(gridWidget_3);
        numberEditCorrect->setObjectName(QString::fromUtf8("numberEditCorrect"));

        gridLayout_3->addWidget(numberEditCorrect, 5, 3, 1, 1);

        label_14 = new QLabel(gridWidget_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_14, 3, 2, 1, 1);

        label_17 = new QLabel(gridWidget_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setAlignment(Qt::AlignCenter);

        gridLayout_3->addWidget(label_17, 6, 2, 1, 1);

        surnameEditCorrect = new QLineEdit(gridWidget_3);
        surnameEditCorrect->setObjectName(QString::fromUtf8("surnameEditCorrect"));

        gridLayout_3->addWidget(surnameEditCorrect, 3, 3, 1, 1);

        correctButton = new QPushButton(gridWidget_3);
        correctButton->setObjectName(QString::fromUtf8("correctButton"));

        gridLayout_3->addWidget(correctButton, 0, 1, 1, 1);

        deleteBox = new QComboBox(gridWidget_3);
        deleteBox->setObjectName(QString::fromUtf8("deleteBox"));

        gridLayout_3->addWidget(deleteBox, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 890, 26));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", " name", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "surname", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "weigth", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "patronymic", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "age", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "county", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "heigth", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "team", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "number", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
        surnameInfo->setText(QCoreApplication::translate("MainWindow", "get information", nullptr));
        openFileButton->setText(QCoreApplication::translate("MainWindow", "open file", nullptr));
        deleteButton->setText(QCoreApplication::translate("MainWindow", "delete player", nullptr));
        limitButton->setText(QCoreApplication::translate("MainWindow", "set limit", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "enter weigth category", nullptr));
        categotyButton->setText(QCoreApplication::translate("MainWindow", "set category", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "heigth limit", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "enter surname", nullptr));
        youngTeamButton->setText(QCoreApplication::translate("MainWindow", "youngest team", nullptr));
        viewButton->setText(QCoreApplication::translate("MainWindow", "view", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        sortButton->setText(QCoreApplication::translate("MainWindow", "Sort by number", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "weigth", nullptr));
        label_19->setText(QCoreApplication::translate("MainWindow", "heigth", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "patronymic", nullptr));
        label_18->setText(QCoreApplication::translate("MainWindow", "county", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", " name", nullptr));
        label_20->setText(QCoreApplication::translate("MainWindow", "team", nullptr));
        label_21->setText(QCoreApplication::translate("MainWindow", "number", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "surname", nullptr));
        label_17->setText(QCoreApplication::translate("MainWindow", "age", nullptr));
        correctButton->setText(QCoreApplication::translate("MainWindow", "correct", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
