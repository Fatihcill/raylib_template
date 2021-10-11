#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include "State.hpp"

#include <GLFW/glfw3.h>
#include "RaySettingsTypes.hpp"

namespace raysettings
{
    enum class WindowMode : uint32
    {
        eFullscreen = 0,
        eWindowed,
        eBorderlessWindowed,
    };
    inline constexpr uint32 c_numResolutionPairs = 18u;
    inline constexpr UIntPair c_resolutionPairs[c_numResolutionPairs] =
    {
        {800, 600},
        {1024, 768},
        {1280, 720},
        {1280, 800},
        {1280, 1024},
        {1360, 768},
        {1366, 768},
        {1440, 900},
        {1536, 864},
        {1600, 900},
        {1680, 1050},
        {1920, 1080},
        {1920, 1200},
        {2048, 1152},
        {2560, 1080},
        {2560, 1440},
        {3440, 1440},
        {3840, 2160},
    };
    
    inline constexpr char const *c_resolutionStrings =
        "800x600;"
        "1024x768;"
        "1280x720;"
        "1280x800;"
        "1280x1024;"
        "1360x768;"
        "1366x768;"
        "1440x900;"
        "1536x864;"
        "1600x900;"
        "1680x1050;"
        "1920x1080;"
        "1920x1200;"
        "2048x1152;"
        "2560x1080;"
        "2560x1440;"
        "3440x1440;"
        "3840x2160;";

    inline constexpr char const *c_windowModeStrings =
        "Fullscreen;"
        "Windowed;"
        "Borderless Windowed";

    struct SettingsWindowLayout
    {
        Vector2 m_anchor01 = {50, 50};
        Vector2 m_anchor02 = {100, 125};
        Vector2 m_anchor03 = {800, 125};

        Rectangle m_layoutRecs[19] = {
            Rectangle{m_anchor01.x + 0, m_anchor01.y + 0, 1820, 350},
            Rectangle{m_anchor02.x + 0, m_anchor02.y + 0, 675, 250},
            Rectangle{m_anchor02.x + 125, m_anchor02.y + 25, 525, 25},
            Rectangle{m_anchor02.x + 50, m_anchor02.y + 25, 50, 25},
            Rectangle{m_anchor02.x + 125, m_anchor02.y + 75, 25, 25},
            Rectangle{m_anchor02.x + 50, m_anchor02.y + 75, 90, 25},
            Rectangle{m_anchor02.x + 125, m_anchor02.y + 125, 525, 25},
            Rectangle{m_anchor02.x + 25, m_anchor02.y + 125, 75, 30},
            Rectangle{m_anchor02.x + 125, m_anchor02.y + 175, 525, 25},
            Rectangle{m_anchor02.x + 20, m_anchor02.y + 175, 80, 30},
            Rectangle{m_anchor03.x + 0, m_anchor03.y + 0, 475, 250},
            Rectangle{m_anchor03.x + 100, m_anchor03.y + 25, 350, 25},
            Rectangle{m_anchor03.x + 25, m_anchor03.y + 25, 80, 25},
            Rectangle{m_anchor03.x + 100, m_anchor03.y + 75, 350, 25},
            Rectangle{m_anchor03.x + 25, m_anchor03.y + 75, 80, 25},
            Rectangle{m_anchor03.x + 100, m_anchor03.y + 125, 350, 25},
            Rectangle{m_anchor03.x + 25, m_anchor03.y + 125, 80, 25},
            Rectangle{m_anchor03.x + 100, m_anchor03.y + 175, 350, 25},
            Rectangle{m_anchor03.x + 25, m_anchor03.y + 175, 80, 25},
        };

        SettingsWindowLayout(uint32 p_targetWidth, uint32 p_targetHeight);
    };

    struct SettingsState
    {
        bool m_vsyncActive{};

        int m_numSupportedResolutions{};
        UIntPair const *m_resolution = &(c_resolutionPairs[0]);
        int m_activeDisplay{};
        int m_numDisplay{};
        WindowMode m_windowMode{};

        float m_masterVolumePercentage = 0.0f;
        float m_musicVolumePercentage = 0.0f;
        float m_fxVolumePercentage = 0.0f;
    };

    class SettingsMenuState : public State
    {
    private:
        //Variables
        Texture backgroundTexture;
        int count;

        //Functions
        void initVariables();
        void initFonts();

        void UpdateState(SettingsState p_newState);
        void UpdateFields();

        std::vector<char const *> m_displayNames;
        std::string m_displayStrings{};
        std::string m_resolutionStrings{};

        SettingsWindowLayout m_layout;

        bool WindowBox000Active = true;
        bool DropdownBox002EditMode = false;
        int DropdownBox002Active = 0;
        bool DropdownBox006EditMode = false;
        int DropdownBox006Active = 0;
        bool DropdownBox008EditMode = false;
        int DropdownBox008Active = 0;

        SettingsState m_state{};

    public:
        SettingsMenuState(StateData *state_data);
        virtual ~SettingsMenuState();

        SettingsState GetState() const;
        void LoadState(SettingsState p_state);

        float GetMasterAudioLevel() const;
        float GetMusicAudioLevel() const;
        float GetFXAudioLevel() const;
        UIntPair GetResolution() const;

        //StateFunctions
        void updateInput(const float &dt);
        void updateGui(const float &dt);
        void update(const float &dt);
        void render();
    };
}








#endif