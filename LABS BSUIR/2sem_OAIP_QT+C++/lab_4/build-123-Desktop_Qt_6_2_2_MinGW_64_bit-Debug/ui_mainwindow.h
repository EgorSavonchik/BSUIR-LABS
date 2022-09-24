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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPlainTextEdit *outPlainText;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *varNameButton;
    QPushButton *classButton;
    QPushButton *funcButton;
    QPushButton *changeButton;
    QPushButton *localButton;
    QPushButton *overloadButton;
    QPushButton *deppButton;
    QPushButton *logicButton;
    QPushButton *checkFileButton;
    QPlainTextEdit *plainTextEdit;
    QPushButton *closeButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        outPlainText = new QPlainTextEdit(centralwidget);
        outPlainText->setObjectName(QString::fromUtf8("outPlainText"));
        outPlainText->setGeometry(QRect(540, 30, 251, 421));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(410, 20, 119, 411));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        varNameButton = new QPushButton(verticalLayoutWidget);
        varNameButton->setObjectName(QString::fromUtf8("varNameButton"));

        verticalLayout->addWidget(varNameButton);

        classButton = new QPushButton(verticalLayoutWidget);
        classButton->setObjectName(QString::fromUtf8("classButton"));

        verticalLayout->addWidget(classButton);

        funcButton = new QPushButton(verticalLayoutWidget);
        funcButton->setObjectName(QString::fromUtf8("funcButton"));

        verticalLayout->addWidget(funcButton);

        changeButton = new QPushButton(verticalLayoutWidget);
        changeButton->setObjectName(QString::fromUtf8("changeButton"));

        verticalLayout->addWidget(changeButton);

        localButton = new QPushButton(verticalLayoutWidget);
        localButton->setObjectName(QString::fromUtf8("localButton"));

        verticalLayout->addWidget(localButton);

        overloadButton = new QPushButton(verticalLayoutWidget);
        overloadButton->setObjectName(QString::fromUtf8("overloadButton"));

        verticalLayout->addWidget(overloadButton);

        deppButton = new QPushButton(verticalLayoutWidget);
        deppButton->setObjectName(QString::fromUtf8("deppButton"));

        verticalLayout->addWidget(deppButton);

        logicButton = new QPushButton(verticalLayoutWidget);
        logicButton->setObjectName(QString::fromUtf8("logicButton"));

        verticalLayout->addWidget(logicButton);

        checkFileButton = new QPushButton(centralwidget);
        checkFileButton->setObjectName(QString::fromUtf8("checkFileButton"));
        checkFileButton->setGeometry(QRect(130, 500, 93, 29));
        plainTextEdit = new QPlainTextEdit(centralwidget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(20, 20, 361, 451));
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName(QString::fromUtf8("closeButton"));
        closeButton->setGeometry(QRect(670, 490, 93, 29));
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
        varNameButton->setText(QCoreApplication::translate("MainWindow", "variable name", nullptr));
        classButton->setText(QCoreApplication::translate("MainWindow", "class struct array", nullptr));
        funcButton->setText(QCoreApplication::translate("MainWindow", "func", nullptr));
        changeButton->setText(QCoreApplication::translate("MainWindow", "val changes", nullptr));
        localButton->setText(QCoreApplication::translate("MainWindow", "local vars", nullptr));
        overloadButton->setText(QCoreApplication::translate("MainWindow", "overload func", nullptr));
        deppButton->setText(QCoreApplication::translate("MainWindow", "deep if", nullptr));
        logicButton->setText(QCoreApplication::translate("MainWindow", "logic errors", nullptr));
        checkFileButton->setText(QCoreApplication::translate("MainWindow", "from file", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
