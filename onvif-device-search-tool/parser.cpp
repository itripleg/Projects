#include "parser.h"

parser::parser()
{
    //ParseReceivedPacket(receiver::datagram);

}

void parser::ParseReceivedPacket(QByteArray &datagram_arg)
{
    QDomDocument doc;
    QXmlInputSource* psource=0;
    QBuffer inputbuffer(&datagram_arg);

    psource = new QXmlInputSource(&inputbuffer);

    if(!doc.setContent(psource, false))
    {
        // 000 Note: Error handler
        qDebug() << "Failed call to 'doc.setContent()'";
        return;
    }

    QDomElement root = doc.documentElement();
    qDebug() << root.tagName();

    QDomNode dnode = root.firstChild();
    QDomElement child;
    QMap<QString, QString> elements;

    while(!dnode.isNull())
    {
        QDomElement currentElement = dnode.toElement();
        QString tagname = "";
        QString value="";
        tagname = currentElement.tagName();
        value = currentElement.text();

        elements[tagname] = value;

        qDebug()<<currentElement.tagName() << "=" << currentElement.text() ;

        dnode = dnode.nextSibling();

    }qDebug() << endl << endl;

    delete psource;
}
