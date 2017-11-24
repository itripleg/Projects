#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "receiver.h"
#include "sendclass.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
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

