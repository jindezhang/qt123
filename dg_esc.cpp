#include "dg_esc.h"
#include "ui_dg_esc.h"

DG_Esc::DG_Esc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DG_Esc)
{
    ui->setupUi(this);
    //installEventFilter(this);
}

DG_Esc::~DG_Esc()
{
    delete ui;
}

bool DG_Esc::eventFilter(QObject *obj, QEvent *event)
{
    QDialog *pDialog = qobject_cast<QDialog *>(obj);
        if (pDialog != NULL)
        {
            switch (event->type())
            {
            case QEvent::KeyPress:
            {
                QKeyEvent *pKeyEvent = static_cast<QKeyEvent*>(event);
                if (pKeyEvent->key() == Qt::Key_Escape)
                {
                    return true;
                }
            }
            }
        }
        return QObject::eventFilter(obj, event);

}

void DG_Esc::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
        {
//        case Qt::Key_Escape:
//            break;
        default:
            QDialog::keyPressEvent(event);
        }

}

void DG_Esc::reject()
{
    //父类的会关闭。
    QDialog::reject();
}
