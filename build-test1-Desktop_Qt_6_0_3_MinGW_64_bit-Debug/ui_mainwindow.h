/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QCheckBox *checkBox;
    QLabel *iPAddressLabel_2;
    QLineEdit *iPAddressLineEdit_2;
    QLabel *subnetMaskLabel;
    QLineEdit *subnetMaskLineEdit;
    QLabel *gatewayLabel_2;
    QLineEdit *gatewayLineEdit;
    QLabel *managementPortLabel;
    QLineEdit *managementPortLineEdit;
    QLabel *hTTPPortLabel;
    QLineEdit *hTTPPortLineEdit;
    QLabel *userNameLabel;
    QLineEdit *userNameLineEdit;
    QLabel *passwordLabel;
    QLineEdit *passwordLineEdit;
    QPushButton *advancebtn;
    QPushButton *applyButton;
    QLabel *logo;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLCDNumber *total;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *searchButton;
    QTableWidget *cameraInfo;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1257, 542);
        MainWindow->setMinimumSize(QSize(1156, 542));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(250, 50));
        groupBox->setMaximumSize(QSize(322, 524));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        checkBox = new QCheckBox(groupBox);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout_2->addWidget(checkBox, 0, 1, 1, 1);

        iPAddressLabel_2 = new QLabel(groupBox);
        iPAddressLabel_2->setObjectName(QString::fromUtf8("iPAddressLabel_2"));

        gridLayout_2->addWidget(iPAddressLabel_2, 1, 0, 1, 1);

        iPAddressLineEdit_2 = new QLineEdit(groupBox);
        iPAddressLineEdit_2->setObjectName(QString::fromUtf8("iPAddressLineEdit_2"));

        gridLayout_2->addWidget(iPAddressLineEdit_2, 1, 1, 1, 1);

        subnetMaskLabel = new QLabel(groupBox);
        subnetMaskLabel->setObjectName(QString::fromUtf8("subnetMaskLabel"));

        gridLayout_2->addWidget(subnetMaskLabel, 2, 0, 1, 1);

        subnetMaskLineEdit = new QLineEdit(groupBox);
        subnetMaskLineEdit->setObjectName(QString::fromUtf8("subnetMaskLineEdit"));

        gridLayout_2->addWidget(subnetMaskLineEdit, 2, 1, 1, 1);

        gatewayLabel_2 = new QLabel(groupBox);
        gatewayLabel_2->setObjectName(QString::fromUtf8("gatewayLabel_2"));

        gridLayout_2->addWidget(gatewayLabel_2, 3, 0, 1, 1);

        gatewayLineEdit = new QLineEdit(groupBox);
        gatewayLineEdit->setObjectName(QString::fromUtf8("gatewayLineEdit"));

        gridLayout_2->addWidget(gatewayLineEdit, 3, 1, 1, 1);

        managementPortLabel = new QLabel(groupBox);
        managementPortLabel->setObjectName(QString::fromUtf8("managementPortLabel"));

        gridLayout_2->addWidget(managementPortLabel, 4, 0, 1, 1);

        managementPortLineEdit = new QLineEdit(groupBox);
        managementPortLineEdit->setObjectName(QString::fromUtf8("managementPortLineEdit"));

        gridLayout_2->addWidget(managementPortLineEdit, 4, 1, 1, 1);

        hTTPPortLabel = new QLabel(groupBox);
        hTTPPortLabel->setObjectName(QString::fromUtf8("hTTPPortLabel"));

        gridLayout_2->addWidget(hTTPPortLabel, 5, 0, 1, 1);

        hTTPPortLineEdit = new QLineEdit(groupBox);
        hTTPPortLineEdit->setObjectName(QString::fromUtf8("hTTPPortLineEdit"));

        gridLayout_2->addWidget(hTTPPortLineEdit, 5, 1, 1, 1);

        userNameLabel = new QLabel(groupBox);
        userNameLabel->setObjectName(QString::fromUtf8("userNameLabel"));

        gridLayout_2->addWidget(userNameLabel, 6, 0, 1, 1);

        userNameLineEdit = new QLineEdit(groupBox);
        userNameLineEdit->setObjectName(QString::fromUtf8("userNameLineEdit"));

        gridLayout_2->addWidget(userNameLineEdit, 6, 1, 1, 1);

        passwordLabel = new QLabel(groupBox);
        passwordLabel->setObjectName(QString::fromUtf8("passwordLabel"));

        gridLayout_2->addWidget(passwordLabel, 7, 0, 1, 1);

        passwordLineEdit = new QLineEdit(groupBox);
        passwordLineEdit->setObjectName(QString::fromUtf8("passwordLineEdit"));

        gridLayout_2->addWidget(passwordLineEdit, 7, 1, 1, 1);

        advancebtn = new QPushButton(groupBox);
        advancebtn->setObjectName(QString::fromUtf8("advancebtn"));

        gridLayout_2->addWidget(advancebtn, 8, 0, 1, 1);

        applyButton = new QPushButton(groupBox);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setCursor(QCursor(Qt::ArrowCursor));
        applyButton->setCheckable(false);

        gridLayout_2->addWidget(applyButton, 8, 1, 1, 1);

        logo = new QLabel(groupBox);
        logo->setObjectName(QString::fromUtf8("logo"));

        gridLayout_2->addWidget(logo, 9, 0, 1, 2);


        gridLayout->addWidget(groupBox, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        total = new QLCDNumber(centralWidget);
        total->setObjectName(QString::fromUtf8("total"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(total->sizePolicy().hasHeightForWidth());
        total->setSizePolicy(sizePolicy);
        total->setSizeIncrement(QSize(50, 50));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(63, 170, 30, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(94, 255, 45, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(78, 212, 37, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(31, 85, 15, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(42, 113, 20, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush6);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(159, 212, 142, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
        QBrush brush10(QColor(0, 0, 0, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush11(QColor(0, 0, 0, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        total->setPalette(palette);
        QFont font;
        font.setFamily(QString::fromUtf8("Segoe Print"));
        total->setFont(font);
        total->setFrameShape(QFrame::NoFrame);
        total->setMode(QLCDNumber::Dec);
        total->setProperty("intValue", QVariant(0));

        horizontalLayout_3->addWidget(total);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QString::fromUtf8("searchButton"));
        searchButton->setLayoutDirection(Qt::RightToLeft);

        horizontalLayout_3->addWidget(searchButton);


        verticalLayout_2->addLayout(horizontalLayout_3);

        cameraInfo = new QTableWidget(centralWidget);
        if (cameraInfo->columnCount() < 7)
            cameraInfo->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        cameraInfo->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        cameraInfo->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        cameraInfo->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        cameraInfo->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        cameraInfo->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        cameraInfo->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        cameraInfo->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        cameraInfo->setObjectName(QString::fromUtf8("cameraInfo"));
        cameraInfo->setMinimumSize(QSize(800, 0));
        cameraInfo->setAutoFillBackground(true);
        cameraInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
        cameraInfo->setDragEnabled(false);
        cameraInfo->setAlternatingRowColors(true);
        cameraInfo->setSelectionMode(QAbstractItemView::NoSelection);
        cameraInfo->setSelectionBehavior(QAbstractItemView::SelectRows);
        cameraInfo->setTextElideMode(Qt::ElideNone);
        cameraInfo->setShowGrid(false);
        cameraInfo->setGridStyle(Qt::NoPen);
        cameraInfo->setSortingEnabled(true);
        cameraInfo->setWordWrap(false);
        cameraInfo->setCornerButtonEnabled(true);
        cameraInfo->setRowCount(0);
        cameraInfo->setColumnCount(7);
        cameraInfo->horizontalHeader()->setVisible(true);
        cameraInfo->horizontalHeader()->setCascadingSectionResizes(false);
        cameraInfo->horizontalHeader()->setMinimumSectionSize(52);
        cameraInfo->horizontalHeader()->setDefaultSectionSize(150);
        cameraInfo->horizontalHeader()->setHighlightSections(true);
        cameraInfo->horizontalHeader()->setStretchLastSection(true);
        cameraInfo->verticalHeader()->setVisible(false);
        cameraInfo->verticalHeader()->setMinimumSectionSize(30);
        cameraInfo->verticalHeader()->setHighlightSections(true);
        cameraInfo->verticalHeader()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_2->addWidget(cameraInfo);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 1, 1);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);
        QObject::connect(checkBox, &QCheckBox::toggled, iPAddressLineEdit_2, &QLineEdit::setDisabled);
        QObject::connect(checkBox, &QCheckBox::toggled, subnetMaskLineEdit, &QLineEdit::setDisabled);
        QObject::connect(checkBox, &QCheckBox::clicked, gatewayLineEdit, &QLineEdit::setDisabled);
        QObject::connect(checkBox, &QCheckBox::clicked, managementPortLineEdit, &QLineEdit::setDisabled);
        QObject::connect(checkBox, &QCheckBox::clicked, hTTPPortLineEdit, &QLineEdit::setDisabled);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "ODST", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Edit Device", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Enable DHCP", nullptr));
        iPAddressLabel_2->setText(QCoreApplication::translate("MainWindow", "IP Address", nullptr));
        subnetMaskLabel->setText(QCoreApplication::translate("MainWindow", "Subnet Mask", nullptr));
        gatewayLabel_2->setText(QCoreApplication::translate("MainWindow", "Gateway", nullptr));
        managementPortLabel->setText(QCoreApplication::translate("MainWindow", "Management Port", nullptr));
        hTTPPortLabel->setText(QCoreApplication::translate("MainWindow", "HTTP Port", nullptr));
        userNameLabel->setText(QCoreApplication::translate("MainWindow", "User Name", nullptr));
        passwordLabel->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        advancebtn->setText(QCoreApplication::translate("MainWindow", "Advanced", nullptr));
        applyButton->setText(QCoreApplication::translate("MainWindow", "Apply", nullptr));
        logo->setText(QString());
        label->setText(QCoreApplication::translate("MainWindow", "Number Of Online Devices", nullptr));
        searchButton->setText(QCoreApplication::translate("MainWindow", "search", nullptr));
        QTableWidgetItem *___qtablewidgetitem = cameraInfo->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "Device Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = cameraInfo->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Ip Address", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = cameraInfo->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Gateway", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = cameraInfo->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Http Port", "disam"));
        QTableWidgetItem *___qtablewidgetitem4 = cameraInfo->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Server Port", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = cameraInfo->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Device Serial", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = cameraInfo->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "uniview", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
