#include "Atlas.hpp"

static constexpr std::string_view FILE_PATH = PROJECT_ROOT "/assets/SpriteSheetV1.png";
static constexpr float SPRITE_LENGTH = 16; // TODO:
static constexpr int COL_NUMBERS = 1;      // TODO:

Atlas *Atlas::s_instance = nullptr;

Rectangle Atlas::getSourceRectangle(SourceType sourceType)
{
    return {
        static_cast<float>(sourceType % COL_NUMBERS * SPRITE_LENGTH),
        static_cast<float>(sourceType / COL_NUMBERS * SPRITE_LENGTH),
        static_cast<float>(SPRITE_LENGTH),
        static_cast<float>(SPRITE_LENGTH),
    };
}

const Texture2D &Atlas::getTexture() const
{
    return m_spriteSheet;
}

const Atlas *Atlas::instance()
{
    if (s_instance == nullptr)
        s_instance = new Atlas();
    return s_instance;
}

void Atlas::destroyInstance()
{
    delete s_instance;
    s_instance = nullptr;
}

/*
    Private
*/
Atlas::Atlas() : m_spriteSheet(LoadTexture(FILE_PATH.data())) {}

Atlas::~Atlas() { UnloadTexture(m_spriteSheet); }