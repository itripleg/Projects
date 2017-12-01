#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "receiver.h"
#include "sendclass.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    EnumerateLocalIps();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::EnumerateLocalIps()
{
    if(ipEntries.count() > 0)
    {
        ipEntries.clear();
    }
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    for(int i=0; i<interfaces.count(); i++) {
        qDebug() << "Interface '" + interfaces.at(i).hardwareAddress() + "'";
        ipEntries = interfaces.at(i).addressEntries();
        for(int j=0; j<ipEntries.count(); j++) {
            if(ipEntries.at(j).ip().protocol() == QAbstractSocket::IPv4Protocol)
            {
                qDebug() << "ip=" << ipEntries.at(j).ip().toString() << ", subnet=" << ipEntries.at(j).netmask().toString();
            }
        }
    }
}

void MainWindow::on_searchButton_clicked()
{
    sendClass::sendingData();
    sendClass::sendingData2();
    //qDebug() << "search button clicked";

}

void MainWindow::on_applyButton_clicked()
{

}

