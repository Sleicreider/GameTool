#ifndef GAMETOOLGUI_H
#define GAMETOOLGUI_H

#include <QMainWindow>
#include <memory>
#include <QMenu>
#include <QSystemTrayIcon>


namespace Ui {
class GameToolGUI;
}

class GameToolGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameToolGUI(QWidget *parent = 0);
    ~GameToolGUI();

public:
    void SetTextRam(std::string&& text);
    void SetTextCpu(std::string&& text);

private:
    Ui::GameToolGUI *ui;
    std::unique_ptr<QMenu> sys_tray_menu_;
    std::unique_ptr<QSystemTrayIcon> sys_tray_icon_;
};

#endif // GAMETOOLGUI_H
