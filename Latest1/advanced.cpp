#include "advanced.h"
#include "ui_advanced.h"



Advanced::Advanced(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Advanced)
{
    ui->setupUi(this);
    traceProcess = new QProcess;
    connect(traceProcess, &QProcess::readyReadStandardOutput, this, &Advanced::readTrace);
//    connect(traceProcess, &QProcess::finished, this, &Advanced::finishedTrace);
    currentItem = 0;
}

Advanced::~Advanced()
{
    delete ui;
}



void Advanced::on_pingBtn_clicked()
{

    QProcess *process = new QProcess;
    QStringList pingList;
    pingList << "/c" << "start" << "ping" << ui->pingLine->text();
    qDebug() << pingList;
    process->startDetached("cmd" , pingList);

    QString stdOut = process->readAllStandardOutput();
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

void Advanced::on_traceBtn_clicked()
{
    if(traceProcess->state()==QProcess::Running)
    {
        return;
    }

    traceProcess->start("cmd.exe");
    traceProcess->write("tracert -h 3 google.com \n");
    traceProcess->closeWriteChannel();   //done Writing

    ui->traceList->clear();


//    while(traceProcess->state()!=QProcess::NotRunning){
//        traceProcess->waitForReadyRead();


//        QStringList resultList= result.split("\r\n",QString::SkipEmptyParts);
//        for(int i =0 ; i <resultList.count(); i++)
//        {

//            ui->traceList->addItem(resultList[i]);
//        }
//    }
}

void Advanced::on_exeBtn_clicked()
{
    QProcess *process = new QProcess;
    QStringList exeArg;
    exeArg << "/c"  << ui->exeLine->text();
    process->startDetached("cmd" , exeArg);
}

void Advanced::readTrace()
{
    if (currentItem == 0)
    {
        currentItem = new QListWidgetItem;
        ui->traceList->addItem(currentItem);
    }
    QString result = traceProcess->readAll();
    for(int i = 0; i < result.length(); i++)
    {
        if(result.at(i) == '\n')
        {
            result = result.mid(i);
            i=0;
            currentItem = new QListWidgetItem;
            ui->traceList->addItem(currentItem);
        }
        else if(result.at(i) == "\r")
        {
         continue;
        }
        else
        {
            QString buffer = currentItem->text();
            buffer.append(result.at(i));
            currentItem->setText(buffer);
        }
    }
}

void Advanced::finishedTrace()
{
    traceProcess->close();
}
