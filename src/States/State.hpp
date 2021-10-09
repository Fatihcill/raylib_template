#ifndef STATE_H
#define STATE_H

#include "stdafx.hpp"

class State;

class StateData
{
public:
    StateData(){};

    //Variables
    std::stack<State *> *states;
    short window_width;
    short window_height;
};

class State
{
private:
protected:
    StateData *stateData;
    std::stack<State *> *states;
    bool quit;
    bool paused;

    //Resources
    std::vector<Texture> textures;



public:
    State(StateData *state_data);
    virtual ~State();

    //Accessors
    const bool &getQuit() const;

    //Functions
    void endState();
    void pauseState();
    void unpauseState();

    virtual void updateInput(const float &dt) = 0;
    virtual void update(const float &dt) = 0;
    virtual void render() = 0;
};

#endif