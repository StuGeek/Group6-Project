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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
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
    QProgressBar *calculate_pb;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_14;
    QLabel *iter_label;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QLabel *rms_label;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLabel *save_label;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QLabel *area_label;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLabel *flux_res_label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QLabel *perem_label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *update_label;
    QLineEdit *iter_input;
    QLabel *label;
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
        calculateButton->setGeometry(QRect(130, 240, 93, 28));
        calculate_pb = new QProgressBar(centralWidget);
        calculate_pb->setObjectName(QString::fromUtf8("calculate_pb"));
        calculate_pb->setGeometry(QRect(110, 190, 181, 23));
        calculate_pb->setValue(0);
        calculate_pb->setTextVisible(true);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(390, 20, 160, 311));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_14 = new QLabel(verticalLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_8->addWidget(label_14);

        iter_label = new QLabel(verticalLayoutWidget);
        iter_label->setObjectName(QString::fromUtf8("iter_label"));

        horizontalLayout_8->addWidget(iter_label);


        verticalLayout_5->addLayout(horizontalLayout_8);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_12 = new QLabel(verticalLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_7->addWidget(label_12);

        rms_label = new QLabel(verticalLayoutWidget);
        rms_label->setObjectName(QString::fromUtf8("rms_label"));

        horizontalLayout_7->addWidget(rms_label);


        verticalLayout_5->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_6->addWidget(label_7);

        save_label = new QLabel(verticalLayoutWidget);
        save_label->setObjectName(QString::fromUtf8("save_label"));

        horizontalLayout_6->addWidget(save_label);


        verticalLayout_5->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        area_label = new QLabel(verticalLayoutWidget);
        area_label->setObjectName(QString::fromUtf8("area_label"));

        horizontalLayout_5->addWidget(area_label);


        verticalLayout_5->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_9 = new QLabel(verticalLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        flux_res_label = new QLabel(verticalLayoutWidget);
        flux_res_label->setObjectName(QString::fromUtf8("flux_res_label"));

        horizontalLayout_4->addWidget(flux_res_label);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_10 = new QLabel(verticalLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);

        perem_label = new QLabel(verticalLayoutWidget);
        perem_label->setObjectName(QString::fromUtf8("perem_label"));

        horizontalLayout_3->addWidget(perem_label);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        update_label = new QLabel(verticalLayoutWidget);
        update_label->setObjectName(QString::fromUtf8("update_label"));

        horizontalLayout_2->addWidget(update_label);


        verticalLayout_5->addLayout(horizontalLayout_2);

        iter_input = new QLineEdit(centralWidget);
        iter_input->setObjectName(QString::fromUtf8("iter_input"));
        iter_input->setGeometry(QRect(190, 130, 113, 21));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(51, 130, 121, 20));
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
        label_14->setText(QApplication::translate("MeshAppClass", "iter", nullptr));
        iter_label->setText(QApplication::translate("MeshAppClass", "0", nullptr));
        label_12->setText(QApplication::translate("MeshAppClass", "rms", nullptr));
        rms_label->setText(QApplication::translate("MeshAppClass", "0", nullptr));
        label_7->setText(QApplication::translate("MeshAppClass", "save", nullptr));
        save_label->setText(QApplication::translate("MeshAppClass", "0", nullptr));
        label_8->setText(QApplication::translate("MeshAppClass", "area", nullptr));
        area_label->setText(QApplication::translate("MeshAppClass", "0", nullptr));
        label_9->setText(QApplication::translate("MeshAppClass", "flux_res", nullptr));
        flux_res_label->setText(QApplication::translate("MeshAppClass", "0", nullptr));
        label_10->setText(QApplication::translate("MeshAppClass", "perem", nullptr));
        perem_label->setText(QApplication::translate("MeshAppClass", "0", nullptr));
        label_2->setText(QApplication::translate("MeshAppClass", "update", nullptr));
        update_label->setText(QApplication::translate("MeshAppClass", "0", nullptr));
        label->setText(QApplication::translate("MeshAppClass", "\350\257\267\350\276\223\345\205\245\350\277\255\344\273\243\346\254\241\346\225\260", nullptr));
        menu->setTitle(QApplication::translate("MeshAppClass", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MeshAppClass: public Ui_MeshAppClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MESHAPP_H
