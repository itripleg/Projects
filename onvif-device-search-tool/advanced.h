#ifndef ADVANCED_H
#define ADVANCED_H

#include <QProcess>
#include <QWidget>
#include <QDebug>
#include <QThread>
#include <QListWidgetItem>


namespace Ui {
class Advanced;
}

class Advanced : public QWidget
{
    Q_OBJECT

public:
    explicit Advanced(QWidget *parent = 0);
    ~Advanced();

    void highlight();

signals:


private slots:
    void on_pingBtn_clicked();
    void on_traceBtn_clicked();
    void on_ipConfigBtn_clicked();
    void on_exeBtn_clicked();

    void readTrace();
    void finishedTrace();

private:
    QProcess *traceProcess;
    Ui::Advanced *ui;
    QString buffer;
    QListWidgetItem* currentItem;

};

#endif // ADVANCED_H
