#ifndef SETTINGSSTATE_H
#define SETTINGSSTATE_H

#include "State.hpp"

class SettingsState : public State
{
private:
    //Variables
    Texture backgroundTexture;
    
    //std::vector<sf::VideoMode> modes;
    
    //Functions
    void initVariables();
    void initFonts();

public:
    SettingsState(StateData *state_data);
    virtual ~SettingsState();

    //Accessors

    //Functions
    void updateInput(const float &dt);
    void updateGui(const float &dt);
    void update(const float &dt);
    void render();
};

#endif