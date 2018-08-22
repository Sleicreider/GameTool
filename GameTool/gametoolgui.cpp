#include "gametoolgui.h"
#include "ui_gametoolgui.h"

GameToolGUI::GameToolGUI(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::GameToolGUI)
    //, gui_settings_(new SettingsGUI(this))
{
    // Always in foreground (doesn't work all the time)
    // QT::SubWindow to hide taskbar
    Qt::WindowFlags flags = windowFlags();
    flags = flags & ~Qt::WindowMinimizeButtonHint;
    setWindowFlags(flags | Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);// | Qt::SubWindow);

    ui->setupUi(this);

    //Transparent BG
    setAttribute(Qt::WA_TranslucentBackground);

    //setWindowOpacity(0);

    QPoint p;
    p.setX(1750);
    p.setY(100);
    move(p);

	CreateSystemTrayIcon();


    gui_settings_.RegisterOnFontChanged([&](const SFontColor& fc){ SetFontColor(fc); });
    gui_settings_.RegisterOnBackgrounEnabledChanged([&](bool enabled){ SetBackgroundEnabled(enabled); });
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

void GameToolGUI::CreateSystemTrayIcon()
{
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
    //sys_tray_icon_->showMessage("Orgel Hanz", "Befreundet seie er das manz");

    // ui->centralWidget->setWindowOpacity(0.2);
    // ui->label_cpu->palette().setColor(QPalette::WindowText, ui->label_cpu->foregroundRole(), Qt::white);
}

void GameToolGUI::SetFontColor(const SFontColor &fc)
{
    ui->label_cpu->setStyleSheet(fc.style_sheet);
    ui->label_edit_cpu->setStyleSheet(fc.style_sheet);
    ui->label_edit_ram->setStyleSheet(fc.style_sheet);
    ui->label_ram->setStyleSheet(fc.style_sheet);
}

void GameToolGUI::SetBackgroundEnabled(bool enable)
{
    bBackgroundEnabled_ = enable;
    update();
}

void GameToolGUI::OnExit()
{
    close();
}

void GameToolGUI::OnSettings()
{
    gui_settings_.show();
}

void GameToolGUI::OnShow()
{
    setVisible(true);
}

void GameToolGUI::OnHide()
{
    setVisible(false);
}
