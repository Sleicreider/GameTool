/********************************************************************************
** Form generated from reading UI file 'gametoolgui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMETOOLGUI_H
#define UI_GAMETOOLGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameToolGUI
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GameToolGUI)
    {
        if (GameToolGUI->objectName().isEmpty())
            GameToolGUI->setObjectName(QStringLiteral("GameToolGUI"));
        GameToolGUI->resize(400, 300);
        menuBar = new QMenuBar(GameToolGUI);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        GameToolGUI->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GameToolGUI);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GameToolGUI->addToolBar(mainToolBar);
        centralWidget = new QWidget(GameToolGUI);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GameToolGUI->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(GameToolGUI);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GameToolGUI->setStatusBar(statusBar);

        retranslateUi(GameToolGUI);

        QMetaObject::connectSlotsByName(GameToolGUI);
    } // setupUi

    void retranslateUi(QMainWindow *GameToolGUI)
    {
        GameToolGUI->setWindowTitle(QApplication::translate("GameToolGUI", "GameToolGUI", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameToolGUI: public Ui_GameToolGUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMETOOLGUI_H
