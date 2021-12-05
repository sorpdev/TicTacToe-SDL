#include "SDL.h"
#include "Game.h"

int main(int argc, char* argv[])
{
	Game game("TicTacToe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
	game.Loop();
	return 0;
}
