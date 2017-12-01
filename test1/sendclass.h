#ifndef SENDCLASS_H
#define SENDCLASS_H
#include <QDebug>

#include <QUdpSocket>
#include <mainwindow.h>


class sendClass : QObject
{
        Q_OBJECT

private:
    sendClass(); //constructor

private:
     static QUdpSocket *sendSocket; //socket for connection
     static QHostAddress groupAddress; // multicast/brodcast address to join
     static quint16 port; //will hold onvif port
     static quint16 port2;
     static QByteArray datagram; //hold prob message
     static QByteArray datagram2;
     static QByteArray datagram3;

public:
     static void sendingData(){
         if(sendClass::sendSocket->writeDatagram(datagram,groupAddress,port)<0){
             qDebug() << "error writing";         };
         qDebug() << "sendingData() probe on port: "<< port <<endl;
     }

     static void sendingData2(){
              if(sendClass::sendSocket->writeDatagram(datagram2,groupAddress,port2)<0){
                  qDebug() << "error writing";         };
              qDebug() << "sendingData() probe on port: "<< port2 <<endl;
          }
};

#endif //SENDCLASS_H
