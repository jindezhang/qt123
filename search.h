#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include <QLineEdit>
#include <QHBoxLayout>

namespace Ui {
class Search;
}

class Search : public QDialog
{
    Q_OBJECT

public:
    explicit Search(QWidget *parent = 0);
    ~Search();
private slots:
    void search();
private:
    Ui::Search *ui;
    QLineEdit *m_pSearchLineEdit;
};

#endif // SEARCH_H
