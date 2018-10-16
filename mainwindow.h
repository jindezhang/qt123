#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QPoint>
#include "dg_esc.h"
#include <QPushButton>
#include <QGridLayout>

#pragma execution_character_set("utf-8")

namespace Ui {
class MainWindow;
}

//#ifdef Q_OS_WIN
//#pragma comment(lib, "user32.lib")
//#include <qt_windows.h>
//#endif

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    //鼠标移动事件
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private slots:
    void pushButton_clicked();
    void creaButton(const QString &text, const char *member);
    void search_clicked();
    void reboot();
    void startCMD();//启动外部程序
    void download();//download pic;

private:
    void initButton();
private:
    Ui::MainWindow *ui;
    bool m_bPressed;
    QPoint m_point;

    QGridLayout *layout;
};

#endif // MAINWINDOW_H
