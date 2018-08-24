#include "Settings.h"

const SFontColor Settings::FONT_BLACK = { EFontColor::Black, "Black", "QLabel { color : black; }" };
const SFontColor Settings::FONT_WHITE = { EFontColor::White, "White", "QLabel { color : white; }" };
const SFontColor Settings::FONT_BLUE = { EFontColor::Blue, "Blue", "QLabel { color : blue; }" };
const SFontColor Settings::FONT_YELLOW = { EFontColor::Yellow, "Yellow" ,"QLabel { color : yellow; }" };


Settings::Settings()
    : bBackgroundEnabled_(false)
    , active_font_color_(Settings::FONT_BLACK)
{
}

void Settings::SetBackgroundEnabled(bool enabled)
{
    bBackgroundEnabled_ = enabled;
}

void Settings::SetActiveFontColor(const SFontColor& fc)
{
    active_font_color_ = fc;
}

bool Settings::IsBackgroundEnabled() const
{
    return bBackgroundEnabled_;
}

const SFontColor& Settings::GetActiveFontColor() const
{
    return active_font_color_;
}
