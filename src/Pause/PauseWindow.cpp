#include "PauseWindow.hpp"
#include "extras/raygui.h"

PauseWindow::PauseWindow(/* args */)
{
}

PauseWindow::~PauseWindow()
{
}

void PauseWindow::checkbutton(StateData *currentStateData) 
{
    if (GuiButton(Rectangle{20, 20, 50, 50}, "PAUSE"))
    {
        currentStateData->states->top()->pauseState();
        std::cout << "PAUSED THE GAME" << std::endl;
    }

        //SHOWPAUSEMENU
    
}
