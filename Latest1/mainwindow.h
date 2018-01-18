#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include "discoverddevice.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void EnumerateLocalIps();
    void Probe(QString ipArg, int portArg);
private slots:
    void on_searchButton_clicked();
    void on_applyButton_clicked();
    void on_advancebtn_clicked();
    bool isLocalIp(QHostAddress);
private:
    QList<QNetworkAddressEntry> ipEntries;
    Ui::MainWindow *ui;
    QList<DiscoverdDevice*> devices;
    DiscoverdDevice *getDiscoveredDevice(QHostAddress ip, int port);
};

#endif // MAINWINDOW_H
