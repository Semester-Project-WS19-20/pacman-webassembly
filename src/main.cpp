#include <emscripten.h>
#include <SDL2/SDL.h>
#include <time.h>
#include <iostream>
#include "Game.h"

using namespace std;

const int FPS = 60;
const int DELAY_TIME = 1000.0f / FPS;

Uint32 frameStart, frameTime = 0;
bool isDone = false;

void main_loop(void *)
{
  cout << "Mainloop start" << endl;
  if (!TheGame::Instance()->isRunning())
  {
    emscripten_cancel_main_loop();
    return;
  }

	if (!TheGame::Instance()->isWindowActive())
	{
	  return;
	}

	frameStart = SDL_GetTicks();

	TheGame::Instance()->handleEvents();
	TheGame::Instance()->update();
	TheGame::Instance()->render();

	frameTime = SDL_GetTicks() - frameStart;

	if (frameTime < DELAY_TIME)
	{
		SDL_Delay(static_cast<int>(DELAY_TIME - frameTime));
	}
}

extern "C" int mainf(int argc, char *argv[])
{
  srand((unsigned)time(nullptr));

  cout << "App init attempt..." << endl;

  if (TheGame::Instance()->init("The game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, false))
  {
    cout << "App init success!" << endl;

    emscripten_set_main_loop_arg(main_loop, nullptr, -1, 1);

  }
  else
  {
    cout << "App init failure: " << SDL_GetError() << endl;

    return -1;
  }

  cout << "App closing..." << endl;
  TheGame::Instance()->clean();

  return 0;
}
