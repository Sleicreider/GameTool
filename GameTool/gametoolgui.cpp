#include "gametoolgui.h"
#include "ui_gametoolgui.h"

GameToolGUI::GameToolGUI(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GameToolGUI)
{
    ui->setupUi(this);
}

GameToolGUI::~GameToolGUI()
{
    delete ui;
}
