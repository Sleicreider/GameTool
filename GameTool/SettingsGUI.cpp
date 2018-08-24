#include "SettingsGUI.h"
#include "ui_SettingsGUI.h"


SettingsGUI::SettingsGUI(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SettingsGUI)
    , settings_crtl_(settings_)
{
    ui->setupUi(this);

    combo_font_color_ = ui->combo_font_color;
    checkbox_background_enabled_ = ui->checkbox_background_enabled;

    CreateFontColors();

    settings_crtl_.LoadSettings();
    checkbox_background_enabled_->setChecked(settings_.IsBackgroundEnabled());
    combo_font_color_->setCurrentIndex(settings_.GetActiveFontColor().index);

    connect(combo_font_color_, SIGNAL(currentIndexChanged(int)), this, SLOT(OnComboIndexChanged(int)));
    connect(checkbox_background_enabled_, SIGNAL(stateChanged(int)), this, SLOT(OnCheckBoxBackgroundEnabled(int)));
}

void SettingsGUI::CreateFontColors()
{
    auto fn_set_in_container = [&](const SFontColor& fc)
    {
        font_colors_[fc.index] = fc;
    };

    fn_set_in_container(Settings::FONT_BLACK);
    fn_set_in_container(Settings::FONT_WHITE);
    fn_set_in_container(Settings::FONT_BLUE);
    fn_set_in_container(Settings::FONT_YELLOW);

    for(auto item : font_colors_)
    {
        combo_font_color_->addItem(item.name);
    }
}

SettingsGUI::~SettingsGUI()
{
    delete ui;
}

void SettingsGUI::RegisterOnFontChanged(FontColorChangedFunction fn)
{
    fn_font_changed_ = fn;
}

void SettingsGUI::RegisterOnBackgrounEnabledChanged(BackgroundEnabledFunction fn)
{
    fn_background_enabled_changed_ = fn;
}

const Settings& SettingsGUI::GetSettings() const
{
    return settings_;
}

void SettingsGUI::OnComboIndexChanged(int index)
{
    settings_.SetActiveFontColor(font_colors_[index]);

    if(fn_font_changed_)
        fn_font_changed_(font_colors_[index]);
}

void SettingsGUI::OnCheckBoxBackgroundEnabled(int enabled)
{
    settings_.SetBackgroundEnabled(enabled);

    if(fn_background_enabled_changed_)
        fn_background_enabled_changed_(settings_.IsBackgroundEnabled());
}
