#ifndef DOWNLOADICON_H
#define DOWNLOADICON_H

#include <QDialog>
#include<QNetworkAccessManager>
#include <QNetworkReply>
#include <QDebug>

namespace Ui {
class downloadICON;
}

class downloadICON : public QDialog
{
    Q_OBJECT

public:
    explicit downloadICON(QWidget *parent = 0);
    ~downloadICON();

private slots:
    void on_pushButton_clicked();
    void downloadFinsh(QNetworkReply *reply);
private:
    Ui::downloadICON *ui;
    QNetworkAccessManager *manager;
};

#endif // DOWNLOADICON_H
