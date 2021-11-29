#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QNetworkInterface>
#include <QNetworkAddressEntry>
#include "discoverddevice.h"
#include "NetDEVSDK.h"

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    DiscoverdDevice *getDiscoveredDevice(QHostAddress ip, int port);
    void addDiscoveredDevice(DiscoverdDevice *device);
    void EnumerateLocalIps();
    void Probe(QString ipArg, int portArg);
    QList<DiscoverdDevice*> devices;

private slots:
    void on_searchButton_clicked();
    void on_applyButton_clicked();
    void on_advancebtn_clicked();
    bool isLocalIp(QHostAddress);
private:
    QList<QNetworkAddressEntry> ipEntries;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
