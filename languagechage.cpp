#include "languagechage.h"
#include "ui_languagechage.h"

#include <QHBoxLayout>
#include <QLabel>
#include <QComboBox>

LanguageChage::LanguageChage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LanguageChage)
{
    ui->setupUi(this);

    QLabel *label = new QLabel(tr("选择语言"));
    QComboBox *cbb = new QComboBox(this);

    cbb->addItem(tr("英语"));
    cbb->addItem(tr("中文"));
    connect(cbb, SIGNAL(currentTextChanged(QString)), this, SLOT(changeLanguage(QString)));

    QHBoxLayout *box = new QHBoxLayout();
    box->addWidget(label);
    box->addWidget(cbb);

    ui->widget->setLayout(box);

}

LanguageChage::~LanguageChage()
{
    delete ui;
}

void LanguageChage::changeLanguage(QString str)
{

}
