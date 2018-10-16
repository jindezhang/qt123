#ifndef DG_ESC_H
#define DG_ESC_H

#include <QDialog>
#include <QKeyEvent>

/*
 * 屏蔽Esc键
 * 方法一：事件过滤 eventFilter()，过滤Esc。需要注册事件。
 * 方法二：重写按键事件 keyPressEvent()
 * 方法三：重写reject(); 一般情况下，会触发的函数。会导致窗体无法关闭，不推荐使用。
 */
namespace Ui {
class DG_Esc;
}

class DG_Esc : public QDialog
{
    Q_OBJECT

public:
    explicit DG_Esc(QWidget *parent = 0);
    ~DG_Esc();
private:
    bool eventFilter(QObject *obj, QEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void reject();
private:
    Ui::DG_Esc *ui;
};

#endif // DG_ESC_H
