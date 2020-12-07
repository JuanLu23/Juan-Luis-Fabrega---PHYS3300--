#include "WAMWorld.h"
#include <iostream>

int main()
{
	WAMWorld firstSimulation(vec2D(0.0f, 9.81f));
	WBody firstBody;
	WBody secondBody;
	firstSimulation.addBody(&firstBody);

	float frametime = 0.5f;
	bool simulationOpen = true;
	int counter = 0;

	while (counter <= 10) {
		firstSimulation.Step(frametime);
		firstBody.DisplayBodyInfo();
		counter++;
	}

	return 0;
}