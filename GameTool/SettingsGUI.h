#ifndef SETTINGSGUI_H
#define SETTINGSGUI_H

#include <QWidget>
#include <string>
#include <array>
#include <functional>
#include <QCloseEvent>

#include "Settings.h"
#include "SettingsController.h"


class QComboBox;
class QCheckBox;


namespace Ui {
class SettingsGUI;
}

class SettingsGUI : public QWidget
{
    Q_OBJECT
    using FontColorContainer = std::array<SFontColor, EFontColor::COUNT>;
    using FontColorChangedFunction = std::function<void(const SFontColor&)>;
    using BackgroundEnabledFunction = std::function<void(bool)>;

public:
    explicit SettingsGUI(QWidget *parent = 0);
    ~SettingsGUI();

    void RegisterOnFontChanged(FontColorChangedFunction fn);
    void RegisterOnBackgrounEnabledChanged(BackgroundEnabledFunction fn);
    const Settings& GetSettings() const;

private:
    void CreateFontColors();

private slots:
    void OnComboIndexChanged(int index);
    void OnCheckBoxBackgroundEnabled(int enabled);

private:
    FontColorContainer font_colors_;

    Ui::SettingsGUI *ui;
    QComboBox* combo_font_color_;
    QCheckBox* checkbox_background_enabled_;

    Settings settings_;
    SettingsController settings_crtl_;

    FontColorChangedFunction fn_font_changed_;
    BackgroundEnabledFunction fn_background_enabled_changed_;
};

#endif // SETTINGSGUI_H
