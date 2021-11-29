#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QUdpSocket>
#include "advanced.h"
#include <QDomDocument>
#include <QPixmap>


void delay(qint32 millisecondsToWait_arg)
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait_arg );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    EnumerateLocalIps();

    QPixmap pix(":/graphics/SCW_Icon_long.png");
    ui->logo->setPixmap(pix);
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
        QList<QNetworkAddressEntry> ips = interfaces.at(i).addressEntries();
        for(int j=0; j<ips.count(); j++) {
            if(ips.at(j).ip().protocol() == QAbstractSocket::IPv4Protocol)
            {
                ipEntries.push_back(ips.at(j));
                qDebug() << "ip=" << ips.at(j).ip().toString() << ", subnet=" << ips.at(j).netmask().toString();
            }
        }
    }qDebug() << "done enumerating";
}

void MainWindow::Probe(QString ipArg, int portArg)
{

    QUdpSocket* pSock = new QUdpSocket(this);
    QUdpSocket* psendSock = new QUdpSocket(this);

    QHostAddress localAddress(ipArg);
    QByteArray receiveDatagram;

    QHostAddress multicastAddress= QHostAddress("239.255.255.250");


    if(pSock->bind(localAddress, portArg, QUdpSocket::ReuseAddressHint  | QUdpSocket::ShareAddress)<0){
        qDebug() << "FAILED - local ip:" + ipArg + "bound on port:" + QString::number(portArg);
        qDebug() << "Failed to bind";
        return;
    }
    qDebug() << "SUCCESS - local ip:" + ipArg + "bound on port:" + QString::number(portArg);

    if(!pSock->joinMulticastGroup(multicastAddress)){
        qDebug() << "FAILED - Joining multicast group:" + multicastAddress.toString();
        return;
    }
    qDebug() << "SUCCESS - Joined multicast group:" + multicastAddress.toString();

        if(psendSock->bind(localAddress, portArg, QUdpSocket::ReuseAddressHint  | QUdpSocket::ShareAddress)<0){
            qDebug() << "FAILED - local ip:" + ipArg + "bound on port:" + QString::number(portArg);
            return;
        }
        qDebug() << "SUCCESS - local ip:" + ipArg + "bound on port:" + QString::number(portArg);

        if(!psendSock->joinMulticastGroup(multicastAddress)){
            qDebug() << "FAILED - Joining multicast group:" + multicastAddress.toString();
            return;
        }
        qDebug() << "SUCCESS - Joined multicast group:" + multicastAddress.toString();


    ////these are hardcoded values I found using wireshark to capture ONVIF cameras' broadcast messages
    QByteArray probeDatagram = "<?xml version=\"1.0\" encoding=\"utf-8\"?><Probe><Uuid>304646F5-9268-42C3-9C6B-F83C3788C7CB</Uuid><Types>inquiry</Types></Probe>";
    QByteArray probeDatagram2 ="<?xml version=\"1.0\" encoding=\"UTF-8\"?><SOAP-ENV:Envelope xmlns:SOAP-ENV=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:SOAP-ENC=\"http://www.w3.org/2003/05/soap-encoding\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:xop=\"http://www.w3.org/2004/08/xop/include\" xmlns:wsa=\"http://schemas.xmlsoap.org/ws/2004/08/addressing\" xmlns:tns=\"http://schemas.xmlsoap.org/ws/2005/04/discovery\" xmlns:dn=\"http://www.onvif.org/ver10/network/wsdl\" xlmns:tds=\"http://www.onvif.org/ver10/device/wsdl\" xmlns:wsa5=\"http://www.w3.org/2005/08/addressing\"><SOAP-ENV:Header><wsa:MessageID>urn:uuid:52C215CF-7734-4fec-AAEF-2613D6D44A03</wsa:MessageID><wsa:To SOAP-ENV:mustUnderstand=\"true\">urn:schemas-xmlsoap-org:ws:2005:04:discovery</wsa:To><wsa:Action SOAP-ENV:mustUnderstand=\"true\">http://schemas.xmlsoap.org/ws/2005/04/discovery/Probe</wsa:Action></SOAP-ENV:Header><SOAP-ENV:Body><tns:Probe><tns:Types>dn:NetworkVideoTransmitter tds:Device</tns:Types></tns:Probe></SOAP-ENV:Body></SOAP-ENV:Envelope>";
    QByteArray probeDatagram3 ="<?xml version=\"1.0\" encoding=\"UTF-8\"?><SOAP-ENV:Envelope xmlns:SOAP-ENV=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:SOAP-ENC=\"http://www.w3.org/2003/05/soap-encoding\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:xop=\"http://www.w3.org/2004/08/xop/include\" xmlns:wsa=\"http://schemas.xmlsoap.org/ws/2004/08/addressing\" xmlns:tns=\"http://schemas.xmlsoap.org/ws/2005/04/discovery\" xmlns:dn=\"http://www.onvif.org/ver10/network/wsdl\" xmlns:wsa5=\"http://www.w3.org/2005/08/addressing\"><SOAP-ENV:Header><wsa:MessageID>urn:uuid:8AFEDF99-5A47-4b55-BFDC-80ECD4D5A55F</wsa:MessageID><wsa:To SOAP-ENV:mustUnderstand=\"true\">urn:schemas-xmlsoap-org:ws:2005:04:discovery</wsa:To><wsa:Action SOAP-ENV:mustUnderstand=\"true\">http://schemas.xmlsoap.org/ws/2005/04/discovery/Probe</wsa:Action></SOAP-ENV:Header><SOAP-ENV:Body><tns:UniviewProbe><tns:Types>dn:NetworkVideoTransmitter</tns:Types></tns:UniviewProbe></SOAP-ENV:Body></SOAP-ENV:Envelope>";

    psendSock->writeDatagram(probeDatagram, multicastAddress, portArg);     //<<<<<< only finds hikvision equipment
    psendSock->writeDatagram(probeDatagram2, multicastAddress, portArg);   //<<<<<< seems to find all uniview cams and NVRs
    psendSock->writeDatagram(probeDatagram3, multicastAddress, portArg);    //<<<<<< finds some uniview stuff?


    QHostAddress fromAddress;
    quint16 fromPort=0;

    QByteArrayList allDataGrams;

    //receiving loop//
    int j;

    for(int x=0; x < 20; ++x)
    {
        if(pSock->hasPendingDatagrams()) {
            //a buffer to store the receivied data
            receiveDatagram.resize(pSock->pendingDatagramSize()); //set the datagram buffer to the size of the received datagram

            pSock->readDatagram(receiveDatagram.data(), receiveDatagram.size(), &fromAddress, &fromPort); // fill the data buffer and set sender address

            if (getDiscoveredDevice(fromAddress,portArg))
            {
                continue;
            }

            DiscoverdDevice *device = new DiscoverdDevice;
            device->address = fromAddress;
            device->port = portArg;

            devices.push_back(device);



            //Ignore message from ourself
            if (isLocalIp(fromAddress)){continue;}

            if(allDataGrams.contains(receiveDatagram)){continue;}

            j = ui->cameraInfo->rowCount();
            ui->cameraInfo->insertRow(j);

            qDebug()<<"datagram being received from" << fromAddress << "from port: " << fromPort << "to port :" << portArg;
            qDebug()<< "message: " << receiveDatagram;

            QDomDocument dom;
            dom.setContent(receiveDatagram);
            QDomElement docElement = dom.documentElement();

            QDomNodeList list = dom.elementsByTagName("DeviceDescription");
            QDomElement element = list.at(0).toElement();
            QTableWidgetItem  *tableItem = new QTableWidgetItem(element.text());
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(j,0, tableItem);

//            list = dom.elementsByTagName("IPv4Address");
//            element = list.at(0).toElement();
            tableItem = new QTableWidgetItem(fromAddress.toString());
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(j,1,tableItem );

            list = dom.elementsByTagName("IPv4Gateway");
            element = list.at(0).toElement();
            tableItem = new QTableWidgetItem(element.text());
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(j,2, tableItem);

//            list = dom.elementsByTagName("HttpPort");
//            element = list.at(0).toElement();
            tableItem = new QTableWidgetItem(QString::number(fromPort));
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(j,3, tableItem);

            list = dom.elementsByTagName("CommandPort");
            element = list.at(0).toElement();
            tableItem = new QTableWidgetItem(element.text());
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(j,4, tableItem);

            list = dom.elementsByTagName("DeviceSN");
            element = list.at(0).toElement();
            tableItem = new QTableWidgetItem(element.text());
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(j,5, tableItem);

            list = dom.elementsByTagName("tns:XAddrs");
            element = list.at(0).toElement();
            tableItem = new QTableWidgetItem(element.text());
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(j,6, tableItem);

            allDataGrams.append(receiveDatagram);
        }
        else
        {
            delay(100);
        }    
    }
    pSock->close();
    psendSock->close();
    qDebug() <<"Done";
    ui->total->setDigitCount(allDataGrams.count());

}

void MainWindow::on_searchButton_clicked()
{
   EnumerateLocalIps();
    //clearing out camera table, try to find a better way
    for(int i =0; i < 254; i++)
    {
        for(int j = 0; j < 5 ; j++)
        {
            QTableWidgetItem *tablei = new QTableWidgetItem("");
            ui->cameraInfo->setItem(i,j,tablei);
        }
        QTableWidgetItem *tablei = new QTableWidgetItem("");
        ui->cameraInfo->setItem(i,5,tablei);
    }

    //start 2 probes
    for(int j=0; j<ipEntries.count(); j++) {
        if(ipEntries.at(j).ip().protocol() == QAbstractSocket::IPv4Protocol)
        {
            Probe(ipEntries.at(j).ip().toString(), 3702);
            Probe(ipEntries.at(j).ip().toString(), 37020);
        }
    }
}

//test to fill camera table
void MainWindow::on_applyButton_clicked()
{
    for(int i =0; i < 254; i++)
    {
        for(int j = 0; j < 5 ; j++)
        {
            QTableWidgetItem *tablei = new QTableWidgetItem("test");

            ui->cameraInfo->setItem(i,j,tablei);
        }
        QTableWidgetItem *tablei = new QTableWidgetItem("test");

        ui->cameraInfo->setItem(i,5,tablei);
    }EnumerateLocalIps();
}

void MainWindow::on_advancebtn_clicked()
{
    Advanced *advance = new Advanced;
    advance->show();

}

bool MainWindow::isLocalIp(QHostAddress address)
{
    for(int i =0; i < ipEntries.count(); i++)
    {
        if(ipEntries.at(i).ip().toString().compare(address.toString())==0)
        {
            return true;
        }
    }
    return false;
}

DiscoverdDevice *MainWindow::getDiscoveredDevice(QHostAddress ip , int port)
{
    for(int i = 0 ; i < devices.count() ; i++)
    {
        if(devices.at(i)->address==ip && port == devices.at(i)->port)
        {
            return devices.at(i);
        }
    }
    return 0;
}
