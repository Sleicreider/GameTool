#ifndef GAMETOOLGUI_H
#define GAMETOOLGUI_H

#include <QMainWindow>

namespace Ui {
class GameToolGUI;
}

class GameToolGUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit GameToolGUI(QWidget *parent = 0);
    ~GameToolGUI();

private:
    Ui::GameToolGUI *ui;
};

#endif // GAMETOOLGUI_H
