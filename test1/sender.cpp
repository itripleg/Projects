#include "sendclass.h"
#include <QDebug>
#include "windows.h"

//use the sender's constructor to send initial probe then
//tie a send probe funtion to a 'refresh' button.
sendClass::sendClass()
{
    qDebug() << "sender object constructed" << endl;
}

quint16 sendClass::port = 3702;
quint16 sendClass::port2 = 37020;
QByteArray sendClass::datagram = "<?xml version=\"1.0\" encoding=\"utf-8\"?><Probe><Uuid>E9D24483-3B71-4B66-8A27-CC67EE559678</Uuid><Types>inquiry</Types></Probe>";
QHostAddress sendClass::groupAddress = QHostAddress("239.255.255.250");
QUdpSocket * sendClass::sendSocket = new QUdpSocket;
QByteArray sendClass::datagram2 = "<?xml version=\"1.0\" encoding=\"utf-8\"?><Probe><Uuid>E9D24483-3B71-4B66-8A27-CC67EE559678</Uuid><Types>inquiry</Types></Probe>";
