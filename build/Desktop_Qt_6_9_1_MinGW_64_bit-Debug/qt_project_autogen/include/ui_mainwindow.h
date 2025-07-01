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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionType_HERE;
    QWidget *centralwidget;
    QLineEdit *lineEdit;
    QPushButton *addButton;
    QListWidget *listWidget;
    QPushButton *removeButton;
    QLabel *label;
    QLabel *labelHora;
    QProgressBar *progressBar;
    QLabel *emptyLabel;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(430, 636);
        MainWindow->setAutoFillBackground(true);
        MainWindow->setTabShape(QTabWidget::TabShape::Rounded);
        actionType_HERE = new QAction(MainWindow);
        actionType_HERE->setObjectName("actionType_HERE");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setEnabled(true);
        lineEdit->setGeometry(QRect(20, 90, 291, 31));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(52, 58, 64);\n"
"color: rgb(255, 255, 255);"));
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");
        addButton->setGeometry(QRect(320, 90, 61, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font.setPointSize(20);
        addButton->setFont(font);
        addButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        addButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 79, 89);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(20, 130, 362, 251));
        listWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(60, 66, 74);\n"
"color: rgb(255, 255, 255);\n"
""));
        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");
        removeButton->setGeometry(QRect(20, 420, 361, 50));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font1.setPointSize(14);
        removeButton->setFont(font1);
        removeButton->setCursor(QCursor(Qt::CursorShape::PointingHandCursor));
        removeButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	background-color: rgb(72, 79, 89);\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"\n"
""));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 20, 191, 81));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font2.setPointSize(24);
        font2.setItalic(false);
        label->setFont(font2);
        label->setMouseTracking(false);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label->setWordWrap(false);
        label->setIndent(0);
        labelHora = new QLabel(centralwidget);
        labelHora->setObjectName("labelHora");
        labelHora->setGeometry(QRect(320, 60, 71, 21));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font3.setPointSize(10);
        labelHora->setFont(font3);
        labelHora->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255)"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(20, 390, 361, 21));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font4.setPointSize(10);
        font4.setBold(true);
        progressBar->setFont(font4);
        progressBar->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        progressBar->setAutoFillBackground(false);
        progressBar->setStyleSheet(QString::fromUtf8("color: rgb(60, 66, 74);"));
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignmentFlag::AlignCenter);
        progressBar->setOrientation(Qt::Orientation::Horizontal);
        emptyLabel = new QLabel(centralwidget);
        emptyLabel->setObjectName("emptyLabel");
        emptyLabel->setGeometry(QRect(20, 130, 361, 251));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Microsoft YaHei")});
        font5.setPointSize(16);
        emptyLabel->setFont(font5);
        emptyLabel->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        emptyLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionType_HERE->setText(QCoreApplication::translate("MainWindow", "Type HERE", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
#if QT_CONFIG(tooltip)
        listWidget->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        removeButton->setText(QCoreApplication::translate("MainWindow", "Deletar tarefa", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "To Do List", nullptr));
        labelHora->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        emptyLabel->setText(QCoreApplication::translate("MainWindow", "Voc\303\252 n\303\243o tem tarefas!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
