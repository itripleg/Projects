#ifndef ADVANCED_H
#define ADVANCED_H

#include <QProcess>
#include <QWidget>
#include <QDebug>

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

private:
    Ui::Advanced *ui;

};

#endif // ADVANCED_H
