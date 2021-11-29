/********************************************************************************
** Form generated from reading UI file 'advanced.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVANCED_H
#define UI_ADVANCED_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Advanced
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *pingLabel;
    QLabel *pingLabel_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *pingLine;
    QLineEdit *exeLine;
    QVBoxLayout *verticalLayout_3;
    QPushButton *pingBtn;
    QPushButton *exeBtn;
    QListWidget *traceList;
    QListWidget *ipList;
    QPushButton *traceBtn;
    QPushButton *ipConfigBtn;

    void setupUi(QWidget *Advanced)
    {
        if (Advanced->objectName().isEmpty())
            Advanced->setObjectName(QString::fromUtf8("Advanced"));
        Advanced->resize(631, 359);
        gridLayout = new QGridLayout(Advanced);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pingLabel = new QLabel(Advanced);
        pingLabel->setObjectName(QString::fromUtf8("pingLabel"));

        verticalLayout->addWidget(pingLabel);

        pingLabel_2 = new QLabel(Advanced);
        pingLabel_2->setObjectName(QString::fromUtf8("pingLabel_2"));

        verticalLayout->addWidget(pingLabel_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        pingLine = new QLineEdit(Advanced);
        pingLine->setObjectName(QString::fromUtf8("pingLine"));

        verticalLayout_2->addWidget(pingLine);

        exeLine = new QLineEdit(Advanced);
        exeLine->setObjectName(QString::fromUtf8("exeLine"));

        verticalLayout_2->addWidget(exeLine);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        pingBtn = new QPushButton(Advanced);
        pingBtn->setObjectName(QString::fromUtf8("pingBtn"));

        verticalLayout_3->addWidget(pingBtn);

        exeBtn = new QPushButton(Advanced);
        exeBtn->setObjectName(QString::fromUtf8("exeBtn"));

        verticalLayout_3->addWidget(exeBtn);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 7, 1, 1, 2);

        traceList = new QListWidget(Advanced);
        traceList->setObjectName(QString::fromUtf8("traceList"));

        gridLayout->addWidget(traceList, 5, 2, 1, 1);

        ipList = new QListWidget(Advanced);
        ipList->setObjectName(QString::fromUtf8("ipList"));

        gridLayout->addWidget(ipList, 5, 1, 2, 1);

        traceBtn = new QPushButton(Advanced);
        traceBtn->setObjectName(QString::fromUtf8("traceBtn"));

        gridLayout->addWidget(traceBtn, 3, 2, 1, 1);

        ipConfigBtn = new QPushButton(Advanced);
        ipConfigBtn->setObjectName(QString::fromUtf8("ipConfigBtn"));

        gridLayout->addWidget(ipConfigBtn, 3, 1, 1, 1);

        ipList->raise();
        traceList->raise();
        traceBtn->raise();
        ipConfigBtn->raise();

        retranslateUi(Advanced);

        QMetaObject::connectSlotsByName(Advanced);
    } // setupUi

    void retranslateUi(QWidget *Advanced)
    {
        Advanced->setWindowTitle(QCoreApplication::translate("Advanced", "Form", nullptr));
        pingLabel->setText(QCoreApplication::translate("Advanced", "Ping", nullptr));
        pingLabel_2->setText(QCoreApplication::translate("Advanced", "Custom command", nullptr));
        pingLine->setText(QCoreApplication::translate("Advanced", "192.168.86.1", nullptr));
        exeLine->setText(QCoreApplication::translate("Advanced", "coming soon", nullptr));
        pingBtn->setText(QCoreApplication::translate("Advanced", "Ping", nullptr));
        exeBtn->setText(QCoreApplication::translate("Advanced", "Execute", nullptr));
        traceBtn->setText(QCoreApplication::translate("Advanced", "Trace Route", nullptr));
        ipConfigBtn->setText(QCoreApplication::translate("Advanced", "IP Config", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Advanced: public Ui_Advanced {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVANCED_H
