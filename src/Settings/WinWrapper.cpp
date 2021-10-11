#include "WinWrapper.hpp"

#define WIN32_LEAN_AND_MEAN
#include <Windows.h>

namespace raysettings
{
    void GetWindowSize(void *winHandle, int &p_out_width, int &p_out_height)
    {
        HWND window = (HWND)winHandle;

        RECT area;
        GetClientRect(window, &area);

        p_out_width = area.right;
        p_out_height = area.bottom;
    }
}