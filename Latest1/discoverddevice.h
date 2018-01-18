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
    QString deviceDescription;
    QString ipv4;
    QString gateway;
};

#endif // DISCOVERDDEVICE_H
