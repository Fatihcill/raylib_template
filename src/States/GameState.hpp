#ifndef GAMESTATE_H
#define GAMESTATE_H

#include "State.hpp"
#include "Player.hpp"

class GameState : public State
{
private:
    //Player Variables
    Player player{Vector2{0, 0}};

    //Functions
    void initVariables();
    void initFonts();

    void initPlayers();

public:
    GameState(StateData *state_data);
    virtual ~GameState();

    //Functions
    void updateInput(const float &dt);

    void updatePlayer();

    void update(const float &dt);

    void render();
};

#endif