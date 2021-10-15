#ifndef GAMESTATE_HPP
#define GAMESTATE_HPP

#include "State.hpp"
#include "Player.hpp"
#include "PauseWindow.hpp"

class GameState : public State
{
private:
    //setup pause
    PauseWindow pauseWindow;
    //Functions
    void initVariables();
    //Custom variables
    Player player{Vector2{0, 0}};

public:
    GameState(StateData *state_data);
    virtual ~GameState();
    //Functions
    void updateInput(const float &dt);
    void update(const float &dt);
    void render();
};

#endif