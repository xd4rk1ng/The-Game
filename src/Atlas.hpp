#pragma once

#include <raylib.h>
#include <string_view>

class Atlas
{
private:
    Texture2D m_spriteSheet;
    static Atlas *s_instance;
    Atlas();
    ~Atlas();

public:
    static const Atlas *instance();

    enum class SourceType
    {
        SPACESHIP = 0,
        PLANET = 1,
        STAR = 2,
        DEBRIS = 3,
    };
    static Rectangle getSourceRectangle(SourceType sourceType);
    const Texture2D &getTexture() const;
};