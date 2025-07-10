/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *inputLineEdit;
    QLineEdit *lineEdit;
    QPushButton *browseOutput;
    QLabel *outputLineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *compressButton;
    QPushButton *browseInput;
    QPushButton *decompressButton;
    QProgressBar *progressBar;
    QLabel *statusLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        inputLineEdit = new QLabel(centralwidget);
        inputLineEdit->setObjectName("inputLineEdit");
        inputLineEdit->setGeometry(QRect(8, 80, 81, 21));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(110, 80, 113, 24));
        browseOutput = new QPushButton(centralwidget);
        browseOutput->setObjectName("browseOutput");
        browseOutput->setGeometry(QRect(130, 240, 80, 24));
        outputLineEdit = new QLabel(centralwidget);
        outputLineEdit->setObjectName("outputLineEdit");
        outputLineEdit->setGeometry(QRect(10, 130, 91, 20));
        lineEdit_2 = new QLineEdit(centralwidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(120, 130, 113, 24));
        compressButton = new QPushButton(centralwidget);
        compressButton->setObjectName("compressButton");
        compressButton->setGeometry(QRect(230, 240, 80, 24));
        browseInput = new QPushButton(centralwidget);
        browseInput->setObjectName("browseInput");
        browseInput->setGeometry(QRect(30, 240, 80, 24));
        decompressButton = new QPushButton(centralwidget);
        decompressButton->setObjectName("decompressButton");
        decompressButton->setGeometry(QRect(330, 240, 80, 24));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(70, 200, 271, 21));
        progressBar->setValue(24);
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setGeometry(QRect(130, 160, 151, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        inputLineEdit->setText(QCoreApplication::translate("MainWindow", "inputLineEdit", nullptr));
        browseOutput->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        outputLineEdit->setText(QCoreApplication::translate("MainWindow", "outputLineEdit", nullptr));
        compressButton->setText(QCoreApplication::translate("MainWindow", "Compress", nullptr));
        browseInput->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        decompressButton->setText(QCoreApplication::translate("MainWindow", "Decompress", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "statusLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
