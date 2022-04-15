#pragma once
#include <SFML/Graphics.hpp>

//grapics
const int WINDOW_WIDTH = 1600;
const int WINDOW_HEIGHT = 900;

const int CHAR_SIZE = 30;

//moving statistics
const float BASE_SPEED = 130.0;
const float STEP = 30.0;

//for functions
const float SIGMA = 4.0;
const int DELTA_TIME = 5;

enum class Backgrounds
{
	//menu, game, win, lose, help, button, reload, music
};
