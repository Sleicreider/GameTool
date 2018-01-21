#include "gametoolgui.h"
#include "ui_gametoolgui.h"

GameToolGUI::GameToolGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameToolGUI)
{
	Qt::WindowFlags flags = windowFlags();
	flags = flags & ~Qt::WindowMinimizeButtonHint;
	setWindowFlags(flags | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);

    //ui->centralWidget->setStyleSheet("background-color");

    //ui->centralWidget->setProperty("windowOpacity",.5f);

    ui->setupUi(this);
	setAttribute(Qt::WA_TranslucentBackground);

	QPoint p;
	p.setX(1750);
	p.setY(100);

	move(p);

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
