#include "mainwindow.h"
#include <QApplication>
#include "receiver.h"
#include "sendclass.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    receiver acceptor;
    sendClass senderObj;



    return a.exec();
}
