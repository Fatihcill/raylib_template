#include "PauseWindow.hpp"
#include "extras/raygui.h"

PauseWindow::PauseWindow()
{
}

PauseWindow::~PauseWindow()
{
}

void PauseWindow::render(StateData *currentStateData) 
{

    if (currentStateData->states->top()->paused)
    {

        if (GuiWindowBox(Rectangle{0, 0, currentStateData->windowSettings.GetResolution().x, currentStateData->windowSettings.GetResolution().y}, "PAUSE MENU") || GuiButton((Rectangle){(currentStateData->windowSettings.GetResolution().x - 100) / 2.f, ((currentStateData->windowSettings.GetResolution().y - 50) / 2.f) + (50 * -1.5f), 100, 50}, "Resume"))
        {
            currentStateData->states->top()->unpauseState(); // Resume the game
        }

        if (GuiButton((Rectangle){(currentStateData->windowSettings.GetResolution().x - 100) / 2.f, ((currentStateData->windowSettings.GetResolution().y - 50) / 2.f), 100, 50}, "Settings"))
        {
            currentStateData->windowSettings.Show(true); //Show Settings
        }
        if (GuiButton((Rectangle){(currentStateData->windowSettings.GetResolution().x - 100) / 2.f, ((currentStateData->windowSettings.GetResolution().y - 50) / 2.f) + (50 * 1.5f), 100, 50}, "Exit"))
        {
            currentStateData->states->top()->endState(); //end state (return the previous state)
        }
        currentStateData->windowSettings.Update();
        return; // does not draw the below gui elements
    }

    if (GuiButton((Rectangle){(currentStateData->windowSettings.GetResolution().x - 50) / 2.f, 25, 50, 50}, "PAUSE")) // pause button in the state
    {
        currentStateData->states->top()->pauseState();
    }
}
