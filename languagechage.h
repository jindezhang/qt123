#ifndef LANGUAGECHAGE_H
#define LANGUAGECHAGE_H

#include <QDialog>

namespace Ui {
class LanguageChage;
}

class LanguageChage : public QDialog
{
    Q_OBJECT

public:
    explicit LanguageChage(QWidget *parent = 0);
    ~LanguageChage();
private slots:
    void changeLanguage(QString str);
private:
    Ui::LanguageChage *ui;
};

#endif // LANGUAGECHAGE_H
