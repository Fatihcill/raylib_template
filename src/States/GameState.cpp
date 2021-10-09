#include "GameState.hpp"

void GameState::initVariables()
{
}

void GameState::initFonts()
{
}

void GameState::initPlayers()
{
}

GameState::GameState(StateData *state_data) : State(state_data)
{
    this->initVariables();
    this->initFonts();
    this->initPlayers();
}

GameState::~GameState()
{
}

void GameState::updateInput(const float &dt)
{
    player.controls();
}

void GameState::updatePlayer()
{
    player.move();
}

void GameState::update(const float &dt)
{
    this->updateInput(dt);
    this->updatePlayer();
}

void GameState::render()
{
    ClearBackground(RAYWHITE);

    //draw player
    player.draw();
}