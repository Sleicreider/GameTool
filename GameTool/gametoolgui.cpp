#include "gametoolgui.h"
#include "ui_gametoolgui.h"

#include <QMenu>
#include <QSystemTrayIcon>


GameToolGUI::GameToolGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameToolGUI)
{

    //Always in foreground (doesn't work all the time)
    //QT::SubWindow to hide taskbar
	Qt::WindowFlags flags = windowFlags();
	flags = flags & ~Qt::WindowMinimizeButtonHint;
    setWindowFlags(flags | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::SubWindow);

    ui->setupUi(this);

    //Transparent BG
	setAttribute(Qt::WA_TranslucentBackground);

	QPoint p;
	p.setX(1750);
	p.setY(100);
	move(p);

    auto sys_tray_menu = new QMenu(this);
    //sys_tray_menu->addAction(minimizeAction);
    //sys_tray_menu->addAction(maximizeAction);
    //sys_tray_menu->addAction(restoreAction);
    sys_tray_menu->addSeparator();
    //sys_tray_menu->addAction(quitAction);

    auto sys_tray_icon = new QSystemTrayIcon(this);
    sys_tray_icon->setContextMenu(sys_tray_menu);

    QIcon icon("baby.ico");
    sys_tray_icon->setIcon(icon);
    //sys_tray_icon->setIcon(this->style()->standardIcon(QStyle::SP_ComputerIcon));

    setWindowIcon(icon);
    sys_tray_icon->show();

	//ui->centralWidget->setWindowOpacity(0.2);
    //ui->label_cpu->palette().setColor(QPalette::WindowText, ui->label_cpu->foregroundRole(), Qt::white);

}

GameToolGUI::~GameToolGUI()
{
    delete ui;
}

void GameToolGUI::SetTextCpu(std::string&& text)
{
    ui->label_edit_cpu->setText(QString::fromStdString(text));
}

void GameToolGUI::SetTextRam(std::string&& text)
{
    ui->label_edit_ram->setText(QString::fromStdString(text));
}
