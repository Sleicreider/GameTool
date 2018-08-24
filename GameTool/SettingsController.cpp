#include "SettingsController.h"
#include "Settings.h"

#include "FileOperation.h"

SettingsController::SettingsController(const Settings& settings)
    : settings_(settings)
{

}

void SettingsController::LoadSettings()
{
    bool value = false;
    FileOperation::GetInt(TAG_BACKGROUND_ENABLED, value);
    settings_.bBackgroundEnabled_ = value;

    FileOperation::GetInt(TAG_SELECTED_FONT_COLOR_INDEX, settings_.se)
}

void SettingsController::SaveSettings()
{
    FileOperation::SetInt(TAG_BACKGROUND_ENABLED, settings_.IsBackgroundEnabled());
    FileOperation::SetInt(TAG_SELECTED_FONT_COLOR_INDEX, settings_.GetActiveFontColor().index);
}
