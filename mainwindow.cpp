#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle(tr("from RD330"));

    setWindowFlags(Qt::FramelessWindowHint | windowFlags());//窗体无边框，无法移动。
    m_bPressed = false;

    layout = new QGridLayout;
    layout->setSizeConstraint(QLayout::SetFixedSize);

    initButton();
    ui->widget->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
       {
           m_bPressed = true;
           m_point = event->pos();
       }

//#ifdef Q_OS_WIN
//    if (ReleaseCapture())
//           SendMessage(HWND(winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
//       event->ignore();
//#else
//#endif
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_bPressed)
            move(event->pos() - m_point + pos());
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);

       m_bPressed = false;
}

void MainWindow::pushButton_clicked()
{
    DG_Esc dialog;
    dialog.exec();
}

void MainWindow::creaButton(const QString &text, const char *member)
{
    static int i =0;
    QPushButton *bt = new QPushButton(text);
    connect(bt, SIGNAL(clicked()), this, member);
    layout->addWidget(bt, i/5, i%5);
    i++;
}

#include <search.h>
void MainWindow::search_clicked()
{
    Search search;
    search.exec();
}

#include <QDir>
#include <QProcess>

void MainWindow::reboot()
{
    //使用QProcess重启
    QString program = QApplication::applicationFilePath();
    QString workPath = QDir::currentPath();
    QStringList arguments = QApplication::arguments();
    QProcess::startDetached(program, arguments, workPath);
    QApplication::exit();
}

#include <showcmd.h>
void MainWindow::startCMD()
{
    QStringList args;
    args<<"/c"<<"ping www.baidu.com";   //没有"/c" 那么命令不会执行。
    QProcess process(this);
    process.start("cmd.exe", args);
    process.waitForStarted();
    process.waitForFinished();
    QString result = QString::fromLocal8Bit(process.readAllStandardOutput());

    showCMD box;
    box.setText(result);
    box.exec();
}

#include <downloadicon.h>
void MainWindow::download()
{
    downloadICON dialog;
    dialog.exec();
}

void MainWindow::initButton()
{
    creaButton(tr("屏蔽Esc"), SLOT(pushButton_clicked()));
    creaButton(tr("搜索框"), SLOT(search_clicked()));
    creaButton(tr("重启"), SLOT(reboot()));
    creaButton(tr("启动外部程序cmd"), SLOT(startCMD()));
    creaButton((tr("下载图片")), SLOT(download()));

}
