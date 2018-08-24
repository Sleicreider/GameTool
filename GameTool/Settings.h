#ifndef SETTINGS_H
#define SETTINGS_H

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

class Settings
{
public:
    Settings();

public:
    void SetBackgroundEnabled(bool enabled);
    void SetActiveFontColor(const SFontColor& index);

    bool IsBackgroundEnabled() const;
    const SFontColor& GetActiveFontColor() const;

public:
    static const SFontColor FONT_BLACK;
    static const SFontColor FONT_WHITE;
    static const SFontColor FONT_BLUE;
    static const SFontColor FONT_YELLOW;


private:
    bool bBackgroundEnabled_:1;
    SFontColor active_font_color_;
};

#endif // SETTINGS_H
