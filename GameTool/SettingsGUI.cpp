#include "SettingsGUI.h"
#include "ui_SettingsGUI.h"

const SFontColor SettingsGUI::FONT_BLACK = { EFontColor::Black, "Black", "QLabel { color : black; }" };
const SFontColor SettingsGUI::FONT_WHITE = { EFontColor::White, "White", "QLabel { color : white; }" };
const SFontColor SettingsGUI::FONT_BLUE = { EFontColor::Blue, "Blue", "QLabel { color : blue; }" };
const SFontColor SettingsGUI::FONT_YELLOW = { EFontColor::Yellow, "Yellow" ,"QLabel { color : yellow; }" };

SettingsGUI::SettingsGUI(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsGUI)
{
    ui->setupUi(this);

    combo_font_color_ = ui->combo_font_color;
    checkbox_background_enabled_ = ui->checkbox_background_enabled;

    CreateFontColors();

    bBackgroundEnabled_ = checkbox_background_enabled_->isChecked();

    connect(combo_font_color_, SIGNAL(currentIndexChanged(int)), this, SLOT(OnComboIndexChanged(int)));
    connect(checkbox_background_enabled_, SIGNAL(stateChanged(int)), this, SLOT(OnCheckBoxBackgroundEnabled(int)));
}

void SettingsGUI::CreateFontColors()
{
    auto fn_set_in_container = [&](const SFontColor& fc)
    {
        font_colors_[fc.index] = fc;
    };

    fn_set_in_container(SettingsGUI::FONT_BLACK);
    fn_set_in_container(SettingsGUI::FONT_WHITE);
    fn_set_in_container(SettingsGUI::FONT_BLUE);
    fn_set_in_container(SettingsGUI::FONT_YELLOW);

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
