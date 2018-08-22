#ifndef GAMETOOLGUI_H
#define GAMETOOLGUI_H

#include <QMainWindow>
#include <memory>
#include <QMenu>
#include <QSystemTrayIcon>
#include <QPainter>

#include "SettingsGUI.h"


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
    void CreateSystemTrayIcon();
    void SetFontColor(const SFontColor& fc);
    void SetBackgroundEnabled(bool enable);

    void paintEvent(QPaintEvent* event)
    {
     int val = bBackgroundEnabled_ ? 255 : 0;

     QColor backgroundColor = palette().light().color();
     backgroundColor.setAlpha(val);
     QPainter customPainter(this);
     customPainter.fillRect(rect(),backgroundColor);
    }


private slots:
    void OnExit();
    void OnSettings();
    void OnHide();
    void OnShow();

private:
    Ui::GameToolGUI *ui;
    std::unique_ptr<QMenu> sys_tray_menu_;
    std::unique_ptr<QSystemTrayIcon> sys_tray_icon_;
    std::unique_ptr<QAction> action_close_;
    SettingsGUI gui_settings_;
    bool bBackgroundEnabled_:1;
};

#endif // GAMETOOLGUI_H
