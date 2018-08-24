#ifndef SETTINGSCONTROLLER_H
#define SETTINGSCONTROLLER_H

class Settings;

class SettingsController
{
public:
   SettingsController(const Settings& settings);

   void LoadSettings();
   void SaveSettings();

private:
   const Settings& settings_;
};

#endif // SETTINGSCONTROLLER_H
