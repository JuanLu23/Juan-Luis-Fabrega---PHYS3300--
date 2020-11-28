#include "Simulation.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* Pendulum;
GameObject* pin;
SDL_Texture* background;


const float pi = 3.141592653589793f;

Simulation::Simulation()
{}

Simulation::~Simulation()
{}

void Simulation::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized!" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		std::cout << "Couldn't initiate SDL..." << std::endl;
		isRunning = false;
	}

	Pendulum = new GameObject("Assets/Pedulum.png", renderer);
	pin = new GameObject("Assets/Hand.png", renderer);
	SDL_Surface* backgroundTmpSurface = IMG_Load("Assets/Background.jpg");
	background = SDL_CreateTextureFromSurface(renderer, backgroundTmpSurface);
	SDL_FreeSurface(backgroundTmpSurface);

}

void Simulation::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Simulation::update(float dt)
{

	timeCount += dt;

	t = 15.0f * pi/180.0f * cos(0.866 * timeCount);
	x = 200 * sin(t) + 640.0f;
	y = 200 * cos(t) + 100.0f;

	Pendulum->update(x, y, 64, 93);
	pin->update(640.0f - 32, 100.0f - 50, 64,64);

}

void Simulation::render()
{
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, NULL, NULL);

	//Background va antes del drawLine.

	SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(renderer, 640, 100, x + 32, y + 2);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	Pendulum->render();
	pin->render();
	SDL_RenderPresent(renderer);
}

void Simulation::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Simulation cleaned..." << std::endl;
}
