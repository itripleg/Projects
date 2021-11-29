/********************************************************************************
** Form generated from reading UI file 'advanced.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADVANCED_H
#define UI_ADVANCED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
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
            Advanced->setObjectName(QStringLiteral("Advanced"));
        Advanced->resize(631, 359);
        gridLayout = new QGridLayout(Advanced);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        pingLabel = new QLabel(Advanced);
        pingLabel->setObjectName(QStringLiteral("pingLabel"));

        verticalLayout->addWidget(pingLabel);

        pingLabel_2 = new QLabel(Advanced);
        pingLabel_2->setObjectName(QStringLiteral("pingLabel_2"));

        verticalLayout->addWidget(pingLabel_2);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        pingLine = new QLineEdit(Advanced);
        pingLine->setObjectName(QStringLiteral("pingLine"));

        verticalLayout_2->addWidget(pingLine);

        exeLine = new QLineEdit(Advanced);
        exeLine->setObjectName(QStringLiteral("exeLine"));

        verticalLayout_2->addWidget(exeLine);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        pingBtn = new QPushButton(Advanced);
        pingBtn->setObjectName(QStringLiteral("pingBtn"));

        verticalLayout_3->addWidget(pingBtn);

        exeBtn = new QPushButton(Advanced);
        exeBtn->setObjectName(QStringLiteral("exeBtn"));

        verticalLayout_3->addWidget(exeBtn);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 7, 1, 1, 2);

        traceList = new QListWidget(Advanced);
        traceList->setObjectName(QStringLiteral("traceList"));

        gridLayout->addWidget(traceList, 5, 2, 1, 1);

        ipList = new QListWidget(Advanced);
        ipList->setObjectName(QStringLiteral("ipList"));

        gridLayout->addWidget(ipList, 5, 1, 2, 1);

        traceBtn = new QPushButton(Advanced);
        traceBtn->setObjectName(QStringLiteral("traceBtn"));

        gridLayout->addWidget(traceBtn, 3, 2, 1, 1);

        ipConfigBtn = new QPushButton(Advanced);
        ipConfigBtn->setObjectName(QStringLiteral("ipConfigBtn"));

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
        Advanced->setWindowTitle(QApplication::translate("Advanced", "Form", Q_NULLPTR));
        pingLabel->setText(QApplication::translate("Advanced", "Ping", Q_NULLPTR));
        pingLabel_2->setText(QApplication::translate("Advanced", "Custom command", Q_NULLPTR));
        pingLine->setText(QApplication::translate("Advanced", "192.168.86.1", Q_NULLPTR));
        exeLine->setText(QApplication::translate("Advanced", "coming soon", Q_NULLPTR));
        pingBtn->setText(QApplication::translate("Advanced", "Ping", Q_NULLPTR));
        exeBtn->setText(QApplication::translate("Advanced", "Execute", Q_NULLPTR));
        traceBtn->setText(QApplication::translate("Advanced", "Trace Route", Q_NULLPTR));
        ipConfigBtn->setText(QApplication::translate("Advanced", "IP Config", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Advanced: public Ui_Advanced {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADVANCED_H
