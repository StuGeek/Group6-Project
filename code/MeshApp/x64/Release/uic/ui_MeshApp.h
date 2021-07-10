/********************************************************************************
** Form generated from reading UI file 'MeshApp.ui'
**
** Created by: Qt User Interface Compiler version 5.12.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MESHAPP_H
#define UI_MESHAPP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MeshAppClass
{
public:
    QAction *actionOpen;
    QAction *actionSave_as;
    QWidget *centralWidget;
    QLabel *status;
    QPushButton *calculateButton;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MeshAppClass)
    {
        if (MeshAppClass->objectName().isEmpty())
            MeshAppClass->setObjectName(QString::fromUtf8("MeshAppClass"));
        MeshAppClass->resize(600, 400);
        actionOpen = new QAction(MeshAppClass);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave_as = new QAction(MeshAppClass);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        centralWidget = new QWidget(MeshAppClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        status = new QLabel(centralWidget);
        status->setObjectName(QString::fromUtf8("status"));
        status->setGeometry(QRect(80, 10, 421, 16));
        calculateButton = new QPushButton(centralWidget);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setGeometry(QRect(200, 80, 93, 28));
        MeshAppClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MeshAppClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        MeshAppClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MeshAppClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MeshAppClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MeshAppClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MeshAppClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(actionOpen);
        menu->addAction(actionSave_as);

        retranslateUi(MeshAppClass);

        QMetaObject::connectSlotsByName(MeshAppClass);
    } // setupUi

    void retranslateUi(QMainWindow *MeshAppClass)
    {
        MeshAppClass->setWindowTitle(QApplication::translate("MeshAppClass", "MeshApp", nullptr));
        actionOpen->setText(QApplication::translate("MeshAppClass", "Open", nullptr));
        actionSave_as->setText(QApplication::translate("MeshAppClass", "Save as", nullptr));
        status->setText(QApplication::translate("MeshAppClass", "Idle...", nullptr));
        calculateButton->setText(QApplication::translate("MeshAppClass", "Calculate", nullptr));
        menu->setTitle(QApplication::translate("MeshAppClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeshAppClass: public Ui_MeshAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESHAPP_H
