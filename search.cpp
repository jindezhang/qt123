#include "search.h"
#include "ui_search.h"
#include <QLineEdit>
#include <QPushButton>

Search::Search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Search)
{
    ui->setupUi(this);

    m_pSearchLineEdit = new QLineEdit();
    QPushButton *pSearchButton = new QPushButton(this);

    pSearchButton->setCursor(Qt::PointingHandCursor);
    pSearchButton->setFixedSize(22, 22);
    pSearchButton->setToolTip(QStringLiteral("搜索"));
    pSearchButton->setStyleSheet("QPushButton{border-image:url(:/icon/icon/search.png); background:transparent;}");

    //防止文本框输入内容位于按钮之下
    QMargins margins = m_pSearchLineEdit->textMargins();
    m_pSearchLineEdit->setTextMargins(margins.left(), margins.top(), pSearchButton->width(), margins.bottom());
    m_pSearchLineEdit->setPlaceholderText(QStringLiteral("请输入搜索内容"));

    QHBoxLayout *pSearchLayout = new QHBoxLayout();
    pSearchLayout->addStretch();
    pSearchLayout->addWidget(pSearchButton);
    pSearchLayout->setSpacing(0);
    pSearchLayout->setContentsMargins(0, 0, 0, 0);
    m_pSearchLineEdit->setLayout(pSearchLayout);

    connect(pSearchButton, SIGNAL(clicked()), this, SLOT(search()));
    //ui->widget->setLayout(pSearchLayout);
    QHBoxLayout *box = new QHBoxLayout();
    box->addWidget(m_pSearchLineEdit);
    ui->widget->setLayout(box);

}

Search::~Search()
{
    delete ui;
}
#include <QMessageBox>
void Search::search()
{
    QString strText = m_pSearchLineEdit->text();
        if (!strText.isEmpty())
        {
            QMessageBox::information(this, QStringLiteral("搜索"), QStringLiteral("搜索内容为:%1").arg(strText));
        }
}
