#include "gametoolgui.h"
#include "ui_gametoolgui.h"

GameToolGUI::GameToolGUI(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::GameToolGUI)
{

    // Always in foreground (doesn't work all the time)
    // QT::SubWindow to hide taskbar
    // Qt::WindowFlags flags = windowFlags();
    // flags = flags & ~Qt::WindowMinimizeButtonHint;
    // setWindowFlags(flags | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint | Qt::SubWindow);

    ui->setupUi(this);

    // Transparent BG
    // setAttribute(Qt::WA_TranslucentBackground);

    // QPoint p;
    // p.setX(1750);
    // p.setY(100);
    // move(p);

    auto action_show = new QAction(tr("Show"), this);
    connect(action_show, &QAction::triggered, this, &GameToolGUI::OnShow);

    auto action_hide = new QAction(tr("Hide"), this);
    connect(action_hide, &QAction::triggered, this, &GameToolGUI::OnHide);

    auto action_settings = new QAction(tr("&Settings"), this);
    connect(action_settings, &QAction::triggered, this, &GameToolGUI::OnSettings);

    auto action_exit = new QAction(tr("&Exit"), this);
    connect(action_exit, &QAction::triggered, this, &GameToolGUI::OnExit);

    sys_tray_menu_ = std::make_unique<QMenu>(this);
    sys_tray_menu_->addAction(action_show);
    sys_tray_menu_->addAction(action_hide);
    sys_tray_menu_->addSeparator();
    sys_tray_menu_->addAction(action_settings);
    sys_tray_menu_->addSeparator();
    sys_tray_menu_->addAction(action_exit);

    auto cicon = QIcon(":/icons/meteor.ico");

    sys_tray_icon_ = std::make_unique<QSystemTrayIcon>(this);
    sys_tray_icon_->setContextMenu(sys_tray_menu_.get());
    sys_tray_icon_->setIcon(cicon);

    // m_systemTrayIcon->show();

    // auto icon = QIcon("atrophy.ico");

    // m_systemTrayIcon = std::make_unique<QSystemTrayIcon>(this);
    // m_systemTrayIcon->setIcon(icon);

    // m_systemTrayMenu = std::make_unique<QMenu>(this);
    // m_systemTrayMenu->addSeparator();

    // setWindowIcon(icon);
    sys_tray_icon_->show();
    sys_tray_icon_->showMessage("Orgel Hanz", "Befreundet seie er das manz");

     ui->centralWidget->setWindowOpacity(0.2);
    // ui->label_cpu->palette().setColor(QPalette::WindowText, ui->label_cpu->foregroundRole(), Qt::white);
}

GameToolGUI::~GameToolGUI() { delete ui; }

void GameToolGUI::SetTextCpu(std::string&& text) 
{ 
	ui->label_edit_cpu->setText(QString::fromStdString(text)); 
}

void GameToolGUI::SetTextRam(std::string&& text) 
{ 
	ui->label_edit_ram->setText(QString::fromStdString(text));
}

void GameToolGUI::OnExit()
{
    close();
}

void GameToolGUI::OnSettings()
{

}

void GameToolGUI::OnShow()
{
    setVisible(true);
}

void GameToolGUI::OnHide()
{
    setVisible(false);
}
