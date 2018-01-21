#include "gametoolgui.h"
#include "ui_gametoolgui.h"

GameToolGUI::GameToolGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameToolGUI)
{
	Qt::WindowFlags flags = windowFlags();
	flags = flags & ~Qt::WindowMinimizeButtonHint;
	setWindowFlags(flags | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    ui->setupUi(this);
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
