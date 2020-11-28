#include "Simulation.h"
#include "TextureManager.h"
#include "GameObject.h"

GameObject* box1;
GameObject* box2;
GameObject* box3;
GameObject* box4;

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

	box1 = new GameObject("Assets/Box1.jpg", renderer);
	box2 = new GameObject("Assets/Box2.jpg", renderer);
	box3 = new GameObject("Assets/Box3.png", renderer);
	box4 = new GameObject("Assets/Box4.png", renderer);

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
	//  x = constant 
	//  y = Yo + Asin(wt) 
	// If A is ingrased the range of the movement is increased on the contrary when the A is decreased so does the movement range to 
	// If w is increased the speed of update in other words the speed of the object, and decreasing it will decrease the speed of it
	timeCount += dt;
	box1->update(1000 - 32, 384 + 400 * sin(1.2 * timeCount) - 32, 64, 64);
	box2->update(384 + 150 * sin(10 * timeCount) - 32, 100 - 32, 64, 64);
	box3->update(384 + 300 * sin(1 * timeCount) - 32, 400 - 32, 64, 64);
	box4->update(384 + 50 * sin(30 * timeCount) - 32, 700 - 32, 64, 64);
}

void Simulation::render()
{
	SDL_RenderClear(renderer);
	box1->render();
	box2->render();
	box3->render();
	box4->render();
	SDL_RenderPresent(renderer);
}

void Simulation::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Simulation cleaned..." << std::endl;
}
