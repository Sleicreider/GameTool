#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

class Settings;

class SettingsController
{
public:
   SettingsController(const Settings& settings);

   void LoadSettings();
   void SaveSettings();

   inline static constexpr char* TAG_BACKGROUND_ENABLED = "BackgroundEnabled";
   inline static constexpr char* TAG_SELECTED_FONT_COLOR_INDEX = "SelectedFontColorIndex";

private:
   const Settings& settings_;
};

#endif // SETTINGSCONTROLLER_H
