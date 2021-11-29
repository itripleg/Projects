#ifndef DISCOVERDDEVICE_H
#define DISCOVERDDEVICE_H

#include <QString>
#include <QHostAddress>

class DiscoverdDevice
{
public:
    DiscoverdDevice();
    int port;
    QHostAddress address;
    QString serial;
    QString ipv4;
    QString gateway;
    int type;
    QString mac;
    QString name;
    QString model;
    QString version;
    QString manuf;
    int serverPort;
};

#endif // DISCOVERDDEVICE_H
