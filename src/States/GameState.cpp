#include "GameState.hpp"

void GameState::initVariables()
{
    this->target = LoadRenderTexture(this->stateData->virtualwindow_width, this->stateData->virtualwindow_height); // 800 600 beginning resolutions of game look Game.cpp for change that
    //setup camera
    cameramanager.setupCamera();
    virtualratio = GetScreenWidth() / this->stateData->virtualwindow_height; // virtual ratio calc
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
    {
        virtualratio = GetScreenWidth() / this->stateData->virtualwindow_height;
        return; //if the game paused. its return.
    }
    this->updateInput(dt);
    player.move();

    // change update worldcamera center
    cameramanager.UpdateCameraCenter(player.worldpos);
}

void GameState::draw()
{
    BeginTextureMode(target); //texture of world camera (everything will be write on this texture)
    ClearBackground(GRAY);    //background color.
    BeginMode2D(cameramanager.worldspacecamera); //worldspacecamera will be game camera
    
    // draw player
    player.draw();

    // End draw
    EndMode2D();
    EndTextureMode();
}

void GameState::render()
{

    ClearBackground(BLACK); // outside of world camera will be black 
    BeginMode2D(cameramanager.screenspacecamera);
    DrawTexturePro(target.texture, Rectangle{0.0f, 0.0f, (float)target.texture.width, -(float)target.texture.height},
                   Rectangle{-virtualratio, -virtualratio, GetScreenWidth() + (virtualratio * 2), GetScreenHeight() + (virtualratio * 2)},
                   Vector2{0, 0}, 0.f, WHITE);
    EndMode2D();

    DrawText(TextFormat("Screen resolution: %ix%i", GetScreenWidth(), GetScreenHeight()), 10, 10, 20, DARKBLUE);
    DrawText(TextFormat("World resolution: %ix%i", this->stateData->virtualwindow_width, this->stateData->virtualwindow_height), 10, 40, 20, DARKGREEN);
    DrawFPS(GetScreenWidth() - 95, 10);
    pauseWindow.render(stateData);
}