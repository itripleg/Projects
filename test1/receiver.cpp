#include "receiver.h"
#include <QDebug>
#include <mainwindow.h>
#include "windows.h"
#include <QTableWidget>
#include <parser.h>

receiver::receiver()
{
    qDebug() << "receivier object constructed " << endl;
    //TODO Need to create socket, join multicast group and listen for probe after

    address= QHostAddress("239.255.255.250");
    port=3702;
    port2=37020;
    socket = new QUdpSocket(this);
    socket2 = new QUdpSocket(this);

    //Bind to port 3702
    if(socket->bind(address,port,QUdpSocket::ReuseAddressHint)<0){
        qDebug() << "bind failed " <<endl;

    }


    //bind to port 37020
    if(socket2->bind(address,port2,QUdpSocket::ReuseAddressHint)<0){
        qDebug() << "bound socket 2 " <<endl;
    }


    if(!socket->joinMulticastGroup(address)){
        qDebug() << "Error: failed to join multicast group";
        return;
    }

    if(!socket2->joinMulticastGroup(address)){
        qDebug() << "Error: failed to join multicast group 2 ";
        return;
    }


    connect(socket, SIGNAL(readyRead()),
           this, SLOT(readingSocket()));


//    while (1) {
//        if(socket->hasPendingDatagrams()){
//            //a buffer to store the receivied data
//            receiver::datagram.resize(socket->pendingDatagramSize()); //set the datagram buffer to the size of the received datagram

//            socket->readDatagram(datagram.data(),datagram.size(),&fromAddress); // fill the data buffer and set sender address
//            qDebug()<<"datagram being received from" << fromAddress << "from port: " << fromPort << "to port :" << port;
//        }

//        else if(socket2->hasPendingDatagrams()){
//        qDebug()<<"datagram being received on port: " << port2 << endl;
//        receiver::datagram2.resize(socket2->pendingDatagramSize()); //set the datagram buffer to the size of the received datagram
//        socket2->readDatagram(datagram2.data(),datagram2.size(),&fromAddress2); // fill the data buffer
//        qDebug()<<"datagram being received from" << fromAddress2 << "from port: " << fromPort2 << "to port :" << port2;
//        //qDebug() << datagram2 << endl;
//        }
//        else { Sleep(1000);

//    parser parse1;
//    parse1.ParseReceivedPacket(datagram);
//    connect(socket2, SIGNAL(readyRead()),
//           this, SLOT(readingSocket()));

    //readingSocket();
}


void receiver::readingSocket()
{   //receiving loop

    while (socket->hasPendingDatagrams()){
        //a buffer to store the receivied data
        receiver::datagram.resize(socket->pendingDatagramSize()); //set the datagram buffer to the size of the received datagram

        socket->readDatagram(datagram.data(),datagram.size(),&fromAddress); // fill the data buffer and set sender address
        qDebug()<<"datagram being received from" << fromAddress << "from port: " << fromPort << "to port :" << port;


    }        if(socket2->hasPendingDatagrams()){
        qDebug()<<"datagram being received on port: " << port2 << endl;
        receiver::datagram2.resize(socket2->pendingDatagramSize()); //set the datagram buffer to the size of the received datagram
        socket2->readDatagram(datagram2.data(),datagram2.size(),&fromAddress2); // fill the data buffer
        qDebug()<<"datagram being received from" << fromAddress2 << "from port: " << fromPort2 << "to port :" << port2;
        //qDebug() << datagram2 << endl;
    }


    parser parse1;
    parse1.ParseReceivedPacket(datagram);
    //parser::ParseReceivedPacket(datagram2);
}

void sayHello() //might use this function to send received data to device info table
{
       qDebug() << "sayHello function";
}



//-----------------------------------//
//attempting to parse a received xml reply


