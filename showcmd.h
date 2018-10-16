#ifndef SHOWCMD_H
#define SHOWCMD_H

#include <QDialog>

namespace Ui {
class showCMD;
}

class showCMD : public QDialog
{
    Q_OBJECT

public:
    explicit showCMD(QWidget *parent = 0);
    ~showCMD();
    void setText(QString &text);

private:
    Ui::showCMD *ui;
};

#endif // SHOWCMD_H
