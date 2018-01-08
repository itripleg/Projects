#include "advanced.h"
#include "ui_advanced.h"

Advanced::Advanced(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Advanced)
{
    ui->setupUi(this);
}

Advanced::~Advanced()
{
    delete ui;
}



void Advanced::on_pingBtn_clicked()
{

    QProcess *process = new QProcess;

    QStringList pingList;
    pingList << "/c" << "start" << "ping";
    pingList << ui->pingLabel->text();
    process->start("cmd.exe", pingList);



}

void Advanced::on_ipConfigBtn_clicked()
{
    QProcess *process = new QProcess;

    process->start("cmd.exe");

    process->write("ipconfig\n");
    process->closeWriteChannel();   //done Writing

    ui->ipList->clear();

    while(process->state()!=QProcess::NotRunning){
        process->waitForReadyRead();
        QString result = process->readAll();

        QStringList resultList= result.split("\r\n",QString::SkipEmptyParts);
        for(int i =3 ; i <resultList.count(); i++)
        {

            ui->ipList->addItem(resultList[i]);
        }
    }
}

void Advanced::highlight()
{
    QString label;
    label = ui->ipList->currentRow();
    QTextCursor highlightCursor();
}
//QTextCursor cursor(document);

//cursor.beginEditBlock();

//QTextCharFormat plainFormat(highlightCursor.charFormat());
//QTextCharFormat colorFormat = plainFormat;
//colorFormat.setForeground(Qt::red);

//while (!highlightCursor.isNull() && !highlightCursor.atEnd()) {
//    highlightCursor = document->find(searchString, highlightCursor, QTextDocument::FindWholeWords);

//    if (!highlightCursor.isNull()) {
//        found = true;
//        highlightCursor.movePosition(QTextCursor::WordRight,
//                               QTextCursor::KeepAnchor);
//        highlightCursor.mergeCharFormat(colorFormat);

void Advanced::on_traceBtn_clicked()
{
    QProcess *process = new QProcess;
    process->start("cmd.exe");
    process->write("tracert -h 3 google.com \n");
    process->closeWriteChannel();   //done Writing

    ui->traceList->clear();


    while(process->state()!=QProcess::NotRunning){
        process->waitForReadyRead();
        QString result = process->readAll();

        QStringList resultList= result.split("\r\n",QString::SkipEmptyParts);
        for(int i =0 ; i <resultList.count(); i++)
        {

            ui->traceList->addItem(resultList[i]);
        }
    }

}
