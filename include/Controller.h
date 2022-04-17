#pragma once
#include "Window.h"
#include "Board.h"

class Controller
{
public:
    Controller();
    void run();

private:
    Window m_window;
    Board m_board;
};