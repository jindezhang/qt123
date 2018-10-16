#include "downloadicon.h"
#include "ui_downloadicon.h"

downloadICON::downloadICON(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::downloadICON)
{
    ui->setupUi(this);

    ui->label->hide();
    manager = new QNetworkAccessManager();
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(downloadFinsh(QNetworkReply*)));
    //connect 函数执行一次就可以了。
}

downloadICON::~downloadICON()
{
    delete ui;
}

#include <QNetworkRequest>
#include <QUrl>
void downloadICON::on_pushButton_clicked()
{
    ui->pushButton->setEnabled(false);

    QNetworkRequest quest;
    QString url;
    //url = QString("https://tse4.mm.bing.net/th?id=OIP.5R3YIr8gLzBgbWY106bVpgHaEo&pid=Api");
    url = ui->lineEdit->text();
    quest.setUrl(QUrl(url));

    manager->get(quest);
    //qDebug()<<"click";
}

#include <QByteArray>
#include <QPixmap>

void downloadICON::downloadFinsh(QNetworkReply *reply)
{

    ui->label->clear();

    // 获取响应状态码，200表示正常
    // QVariant nCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
    if(reply->error() == QNetworkReply::NoError){
        QByteArray bytes = reply->readAll();
        QPixmap pix;
        pix.loadFromData(bytes);
        ui->label->setPixmap(pix);
        ui->label->setScaledContents(true);
        ui->label->resize(pix.size());
    }
    else{
        ui->label->setText("Error!");
    }
    ui->label->show();
    ui->pushButton->setEnabled(true);
    //qDebug()<<"finsh";
}
