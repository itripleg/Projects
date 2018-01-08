#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTime>
#include <QUdpSocket>
#include "advanced.h"
#include <QDomDocument>

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
    }
}

QByteArray probeDatagram = "<?xml version=\"1.0\" encoding=\"utf-8\"?><Probe><Uuid>E9D24483-3B71-4B66-8A27-CC67EE559678</Uuid><Types>inquiry</Types></Probe>";
QByteArray probeDatagram2 ="<?xml version=\"1.0\" encoding=\"UTF-8\"?><SOAP-ENV:Envelope xmlns:SOAP-ENV=\"http://www.w3.org/2003/05/soap-envelope\" xmlns:SOAP-ENC=\"http://www.w3.org/2003/05/soap-encoding\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\" xmlns:xop=\"http://www.w3.org/2004/08/xop/include\" xmlns:wsa=\"http://schemas.xmlsoap.org/ws/2004/08/addressing\" xmlns:tns=\"http://schemas.xmlsoap.org/ws/2005/04/discovery\" xmlns:dn=\"http://www.onvif.org/ver10/network/wsdl\" xmlns:wsa5=\"http://www.w3.org/2005/08/addressing\"><SOAP-ENV:Header><wsa:MessageID>urn:uuid:52C215CF-7734-4fec-AAEF-2613D6D44A03</wsa:MessageID><wsa:To SOAP-ENV:mustUnderstand=\"true\">urn:schemas-xmlsoap-org:ws:2005:04:discovery</wsa:To><wsa:Action SOAP-ENV:mustUnderstand=\"true\">http://schemas.xmlsoap.org/ws/2005/04/discovery/Probe</wsa:Action></SOAP-ENV:Header><SOAP-ENV:Body><tns:Probe><tns:Types>dn:NetworkVideoTransmitter</tns:Types></tns:Probe></SOAP-ENV:Body></SOAP-ENV:Envelope>";

void MainWindow::Probe(QString ipArg, int portArg)
{
    QUdpSocket* psendSock = new QUdpSocket(this);
    QHostAddress multicastAddress= QHostAddress("239.255.255.250");

    QUdpSocket* pSock = new QUdpSocket(this);
    QHostAddress localAddress(ipArg);
    QByteArray receiveDatagram;

    if(pSock->bind(localAddress, portArg, QUdpSocket::ReuseAddressHint  | QUdpSocket::ShareAddress)<0){
        qDebug() << "FAILED - local ip:" + ipArg + "bound on port:" + QString::number(portArg);
        return;
    }
    qDebug() << "SUCCESS - local ip:" + ipArg + "bound on port:" + QString::number(portArg);

    if(!pSock->joinMulticastGroup(multicastAddress)){
        qDebug() << "FAILED - Joining multicast group:" + multicastAddress.toString();
        return;
    }
    qDebug() << "SUCCESS - Joined multicast group:" + multicastAddress.toString();

    psendSock->writeDatagram(probeDatagram, multicastAddress, portArg);
    psendSock->writeDatagram(probeDatagram2, multicastAddress, portArg);


    QHostAddress fromAddress;
    quint16 fromPort=0;
    for(int x=0; x < 100; ++x)
    {
        if(pSock->hasPendingDatagrams()) {
            //a buffer to store the receivied data
            receiveDatagram.resize(pSock->pendingDatagramSize()); //set the datagram buffer to the size of the received datagram

            pSock->readDatagram(receiveDatagram.data(), receiveDatagram.size(), &fromAddress, &fromPort); // fill the data buffer and set sender address

            if(fromAddress == QHostAddress::LocalHost){qDebug() << "message from yourself";}

            if(fromAddress != QHostAddress::LocalHost)
            {
            qDebug()<<"datagram being received from" << fromAddress << "from port: " << fromPort << "to port :" << portArg;
            qDebug()<< "message: " <<receiveDatagram << endl;

            QDomDocument dom;
            dom.setContent(receiveDatagram);
            QDomElement docElement = dom.documentElement();


            QDomNodeList list = dom.elementsByTagName("IPv4Address");
            QDomElement element = list.at(0).toElement();
            QTableWidgetItem *tableItem = new QTableWidgetItem(element.text());
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(x,1, tableItem);

            list = dom.elementsByTagName("IPv4Gateway");
            element = list.at(0).toElement();
            tableItem = new QTableWidgetItem(element.text());
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(x,2, tableItem);

            list = dom.elementsByTagName("DeviceDescription");
            element = list.at(0).toElement();
            tableItem = new QTableWidgetItem(element.text());
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(x,0, tableItem);

            list = dom.elementsByTagName("HttpPort");
            element = list.at(0).toElement();
            tableItem = new QTableWidgetItem(element.text());
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(x,3, tableItem);

            list = dom.elementsByTagName("CommandPort");
            element = list.at(0).toElement();
            tableItem = new QTableWidgetItem(element.text());
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(x,4, tableItem);

            list = dom.elementsByTagName("DeviceSN");
            element = list.at(0).toElement();
            tableItem = new QTableWidgetItem(element.text());
            tableItem->setTextAlignment(Qt::AlignCenter);
            ui->cameraInfo->setItem(x,5, tableItem);
            }



        }
        else
        {
            delay(100);
        }
    }

    pSock->close();
}

void MainWindow::on_searchButton_clicked()
{
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
    }
}

void MainWindow::on_advancebtn_clicked()
{
    Advanced *advance = new Advanced;
    advance->show();

}
