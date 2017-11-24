#ifndef PARSER_H
#define PARSER_H
#include <QObject>
#include <QDebug>
#include <QDomDocument>
#include <QBuffer>
#include <QXmlSimpleReader>
#include <QXmlInputSource>
#include <QXmlStreamWriter>

#include <receiver.h>



class parser : QObject
{
    Q_OBJECT

public:
    parser();

public slots:
        void ParseReceivedPacket(QByteArray &datagram_arg);
};

#endif // PARSER_H
