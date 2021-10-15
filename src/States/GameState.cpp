#include "GameState.hpp"

void GameState::initVariables()
{
}

GameState::GameState(StateData *state_data) : State(state_data)
{
    std::cout << "GAME IS STARTING" << std::endl;
    this->initVariables();
}

GameState::~GameState()
{
    std::cout << "Game State Finished" << std::endl;
}

void GameState::updateInput(const float &dt)
{
    player.controls();
}

void GameState::update(const float &dt)
{
    if (this->paused)
        return; //if the game paused. its return.

    this->updateInput(dt);
    player.move();
}

void GameState::render()
{
    ClearBackground(GRAY);

    //draw player
    player.draw();
    pauseWindow.render(stateData);
}