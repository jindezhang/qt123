#include "showcmd.h"
#include "ui_showcmd.h"

showCMD::showCMD(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showCMD)
{
    ui->setupUi(this);
}

showCMD::~showCMD()
{
    delete ui;
}

void showCMD::setText(QString &text)
{
    ui->textEdit->setText(text);
}
