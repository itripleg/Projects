#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>
#include <QUdpSocket>
#include <QTableWidget>
#include <mainwindow.h>


class receiver : public QObject
{
    Q_OBJECT
public:
    receiver();
    void sayHello();
    quint16 port;
    quint16 port2;

    QByteArray datagram;
    QByteArray datagram2;

    QUdpSocket *socket;
    QUdpSocket *socket2;
    QTableWidget cameraInfo;

public slots:
    void readingSocket();


private:

    QHostAddress address;
    QHostAddress fromAddress;
    QHostAddress fromAddress2;

    quint16 fromPort;
    quint16 fromPort2;
};

#endif // RECEIVER_H

//QUdpSocket.bind(QHostAddress("239.255.255.250"),0);
