#include "Simulation.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* Asteroid;
GameObject* MainPlanet;

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

	Asteroid = new GameObject("Assets/Asteroid.png", renderer);
	MainPlanet = new GameObject("Assets/Main-planet.png", renderer);

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
	// Formula for vertical movement 
	//  x = Xc + r * cos(wt) 
	//  y = Yc + r * sin(wt)
	// If r is increased accordingky to which cordinate it changes the radis lengt. If the x-axis is increased then the circle will have a horizontal movement, in the  
	//	y-axis is increased the circle has a more vertical movement. If they are increase simultaniously then the orbit is increased in size 
	// If the w is increase the speed of display is increased. If you increase the w enough something interesting can happen the program displays more than one object 
	//  but is the object moving really fast
	timeCount += dt;
	Asteroid->update(640 + 200 * cos(1 * timeCount) - 16, 400 + 200 * sin(1 * timeCount) - 16, 32, 32);
	MainPlanet->update(640 - 32, 400 - 32, 64, 64);

}

void Simulation::render()
{
	SDL_RenderClear(renderer);
	Asteroid->render();
	MainPlanet->render();
	SDL_RenderPresent(renderer);
}

void Simulation::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Simulation cleaned..." << std::endl;
}