#ifndef SETTINGSGUI_H
#define SETTINGSGUI_H

#include <QWidget>
#include <string>
#include <array>
#include <functional>
#include <QCloseEvent>


class QComboBox;
class QCheckBox;

struct EFontColor
{
    enum Type
    {
        Black = 0,
        White,
        Yellow,
        Blue,
        COUNT
    };
};

struct SFontColor
{
    EFontColor::Type index;
    const char* name;
    const char* style_sheet;
};

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

   private:
    void CreateFontColors();



private slots:
    void OnComboIndexChanged(int index)
    {
        if(fn_font_changed_)
            fn_font_changed_(font_colors_[index]);
    }

    void OnCheckBoxBackgroundEnabled(int enabled)
    {
        bBackgroundEnabled_ = enabled;

        if(fn_background_enabled_changed_)
            fn_background_enabled_changed_(bBackgroundEnabled_);
    }

private:
    static const SFontColor FONT_BLACK;
    static const SFontColor FONT_WHITE;
    static const SFontColor FONT_BLUE;
    static const SFontColor FONT_YELLOW;

private:
    FontColorContainer font_colors_;

private:
    Ui::SettingsGUI *ui;
    QComboBox* combo_font_color_;
    QCheckBox* checkbox_background_enabled_;
    FontColorChangedFunction fn_font_changed_;
    BackgroundEnabledFunction fn_background_enabled_changed_;
    bool bBackgroundEnabled_:1;
};

#endif // SETTINGSGUI_H
